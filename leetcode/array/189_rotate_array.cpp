#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3, n = nums.size();

    int jump[n], result[n];
    for(int i = 0; i < n; i++){
        int jump_value = i+k;
        if(jump_value >= n){
            jump_value = jump_value % n;
        }
        jump[i] = jump_value;
        result[jump[i]] = nums[i];
    }

    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << endl;
}