#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> sum_indexes(vector<int>& numbers, int target){
    int buffer = 0, i = 0, j = numbers.size() - 1;
    while(1){
        buffer = numbers[i] + numbers[j];
        if(buffer > target)
            j--;
        else if(buffer < target)
            i++;
        else{
            vector<int> result = {i+1, j+1};
            return result;
        }
    }
    vector<int> result = {0, 0};
    return result;
}

int main(){
    vector<int> number = {-10,-8,-2,1,2,5,6};
    int target = 0;
    
    vector<int> result = sum_indexes(number, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}