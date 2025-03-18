#include <iostream> 
#include <unordered_map> 
#include <string>
#include <vector>

using namespace std;

int partition(string& s, int low, int high){
    char pivot = s[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(s[j] <= pivot){
            i++;

            swap(s[j], s[i]);
        }
    }
    i++;
    swap(s[i], s[high]);

    return i;
}

void quicksort(string& s, int low, int high){
    if(low < high){
        int pi = partition(s, low, high);
        quicksort(s, low, pi - 1);
        quicksort(s, pi + 1, high);
    }
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> umap;
    for(int i = 0; i < strs.size(); i++){
        string sorted_string = strs[i];
        quicksort(sorted_string, 0, sorted_string.size() - 1);
        umap[sorted_string].push_back(strs[i]);
    }

    vector<vector<string>> result;
    for (const auto& [key, value] : umap) {
        result.push_back(value);
    }

    return result;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams(strs);

        for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}