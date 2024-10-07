#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high], i = low-1;
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[high], arr[i]);

    return i;
}

void quicksort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

vector<int> arr1ayRankTransform(vector<int>& arr) {
    unordered_map<int, int> hash;
    vector<int> result, aux;

    for(int i = 0; i < arr.size(); i++){
        aux.push_back(arr[i]);
    }
    
    quicksort(aux, 0, aux.size() - 1);

    int i_normalized = 0;
    for(int i = 0; i < aux.size(); i++){
        if(hash.find(aux[i]) == hash.end()){
            hash[aux[i]] = i_normalized;
            i_normalized++;
        }
    }

    for(int i = 0; i < arr.size(); i++){
        result.push_back(hash[arr[i]] + 1);
    }

    return result;
}

int main(){
    vector<int> arr = {40,10,20,30};
    
    arr = arr1ayRankTransform(arr);
    for(auto num : arr)
        cout << num << " ";
    cout << endl;

    vector<int> arr2 = {100, 100, 100};

    arr2 = arr1ayRankTransform(arr2);
    for(auto num : arr2)
        cout << num << " ";
    cout << endl;

    vector<int> arr3 = {37,12,28,9,100,56,80,5,12};
    
    arr3 = arr1ayRankTransform(arr3);
    for(auto num : arr3)
        cout << num << " ";
    cout << endl;

    return 0;
}