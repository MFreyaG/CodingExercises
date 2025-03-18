#include <iostream>
#include <vector>

using namespace std;

vector<int> breakingRecords(vector<int> scores) {
    int lowR = 0, highR = 0;

    int min = scores[0], max = scores[0];
    for(int i = 0; i < scores.size(); i++){
        if(min > scores[i]){
            lowR++;
            min = scores[i];
        } else if(max < scores[i]){
            highR++;
            max = scores[i];
        }
    }

    vector<int> result = {lowR, highR};
    return result;
}

int main(){
    vector<int> vec1 = {12,24,10,24}, result;
    result = breakingRecords(vec1);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}