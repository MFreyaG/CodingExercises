#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums){
    int size = nums.size();
    if(size == 1 || size == 2)
        return size;

    vector<int> result;
    result.push_back(nums[0]);
    result.push_back(nums[1]);
    for(int i = 2; i < size; i++){
        if(nums[i-2] != nums[i])
            result.push_back(nums[i]);
    }

    nums = result;

    return nums.size();
}

int main() {
    vector<int> input1 = {1,1,1,2,2,3};

    cout << removeDuplicates(input1) << endl;
    for(auto num : input1)
        cout << num << " ";
    cout << endl;

    return 0;
}