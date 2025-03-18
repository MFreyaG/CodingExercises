#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int l = -1, buffer = 0, best = nums.size() + 1;
    for(int r = 0; r < nums.size(); r++){
        buffer += nums[r];
        while(buffer >= target){
            if(best > r-l)
                best = r-l;
            l++;
            buffer -= nums[l];
        }
    }
    if(best == nums.size() + 1)
        return 0;

    return best;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    int target = 11;
    
    cout << minSubArrayLen(target, nums) << endl;

    return 0;
}