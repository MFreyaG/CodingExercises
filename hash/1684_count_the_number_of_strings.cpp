#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
    int hash[26] = {0};
    for(int i = 0; i < allowed.size(); i++)
        hash[allowed[i] - 'a'] = 1;

    int valid, result = 0;
    for(int i = 0; i < words.size(); i++){
        valid = 1;
        for(int j = 0; j < words[i].size(); j++){
            if(hash[words[i][j] - 'a'] == 0)
                valid = 0;
        }
        if(valid == 1)
            result++;
    }

    return result;
}

int main(){
    vector<string> words = {"cc","acd","b","ba","bac","bad","ac","d"};
    string allowed = "cad";

    cout << countConsistentStrings(allowed, words) << endl;

    return 0;
}