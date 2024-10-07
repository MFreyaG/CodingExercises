#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canArrange(vector<int>& arr,  int k){
    unordered_map<int, int> remainder;
    for(auto num : arr)
        remainder[(num % k + k) % k]++;

    for(auto num : arr){
        int key = (num % k + k) % k;

        if(key == 0){
            if (remainder[key] % 2 == 1)
                return false;   
        }
        else if(remainder[key] != remainder[k - key])
            return false;
    }

    return true;
}

int main(){
    vector<int> input1 = {1,2,3,4,5,10,6,7,8,9};
    int k1 = 5;

    cout << canArrange(input1, k1) << endl;

    vector<int> input2 = {1,2,3,4,5,6};
    int k2 = 7;

    cout << canArrange(input2, k2) << endl;

    vector<int> input3 = {1,2,3,4,5,6};
    int k3 = 10;

    cout << canArrange(input3, k3) << endl;

    return 0;
}