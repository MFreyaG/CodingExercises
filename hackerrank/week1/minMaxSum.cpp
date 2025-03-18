#include <iostream>
#include <vector>

using namespace std;

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void miniMaxSum(vector<int> arr) {
    quickSort(arr, 0, arr.size()-1);

    long long int min = 0, max = 0;
    for(int i = 0; i < 4; i++) min += arr[i];
    for(int i = 1; i < 5; i++) max += arr[i];
    
    cout << min << " " << max << endl;
}

int main(){
    vector<int> vec1 = {1,3,5,7,9};
    vector<int> vec2 = {256741038, 623958417 ,467905213 ,714532089, 938071625};
    miniMaxSum(vec1);
    miniMaxSum(vec2);
    return 0;
}