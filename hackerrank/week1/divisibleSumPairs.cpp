#include <iostream>
#include <vector>

using namespace std;

int divisibleSumPairs(int n, int k, vector<int> ar) {
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((ar[i]+ar[j])%k==0) {
                result++;
            }
        }
    }
    return result;
}

int main(){
    vector<int> v1 = {1,3,2,6,1,2};
    cout << divisibleSumPairs(6, 3, v1) << endl;
    return 0;
}