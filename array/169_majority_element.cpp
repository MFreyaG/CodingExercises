#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    std::vector<int> nums = {-1,1,1,1,2,1};
    unordered_map<int, int> hash;

    for(int i = 0; i < nums.size(); i++){
        hash[nums[i]]++;
    }

    int bigger = -1, result = -1;
    for(const auto& pair : hash){
        if(pair.second > bigger){
            bigger = pair.second;
            result = pair.first;
        }
    }

    cout << result << endl;

    return 0;
}