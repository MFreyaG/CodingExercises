#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high], i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[high]);

    return i;
}

void quicksort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

long long dividePlayers(vector<int>& skill){
    int size = skill.size();

    long long result = 0;
    quicksort(skill, 0, size - 1);

    if(size % 2 == 1) return -1;
    
    int j = size - 1, previous_sum = skill[0] + skill[size - 1];
    for(int i = 0; i < j; i++){
        int current_sum = skill[i] + skill[j];
        if(current_sum != previous_sum) return -1;

        result += skill[i]*skill[j];
        j--;
    }

    return result;
}

int main(){
    vector<int> skill = {3, 2, 5, 1, 3, 4};
    cout << dividePlayers(skill) << endl;

    skill = {3, 4};
    cout << dividePlayers(skill) << endl;

    skill = {1, 1, 2, 3};
    cout << dividePlayers(skill) << endl;

    return 0;
}