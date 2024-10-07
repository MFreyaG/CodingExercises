#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> hash;

    vector<int> result;
    for(int i = 0; i < nums.size(); i++){
        int key = target - nums[i];
        if(hash.find(key) != hash.end()){
            result.push_back(i);
            result.push_back(hash[key]);
            break;
        } else {
            hash[nums[i]] = i;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}