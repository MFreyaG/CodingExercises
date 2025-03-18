#include <iostream>
#include <string>

using namespace std;

int maximumSwapN2(int num){
    int max = num;
    string s_num = to_string(num);
    for(int i = 0; i < s_num.size(); i++){
        for(int j = i+1; j < s_num.size(); j++){
            swap(s_num[i], s_num[j]);
            if(max < stoi(s_num)) max = stoi(s_num);
            s_num = to_string(num);
        }
    }

    return max;
}

int main(){
    int num1 = 2736;

    cout << maximumSwapN2(num1) << endl;

    int num2 = 9973;

    cout << maximumSwapN2(num2) << endl;

    return 0;
}