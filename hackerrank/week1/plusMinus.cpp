#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void plusMinus(vector<int> arr) {
    float positive = 0, negative = 0, zero = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0) positive++;
        else if(arr[i] == 0) zero++;
        else negative++;
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << positive/arr.size() << endl;
    std::cout << negative/arr.size() << endl;
    std::cout << zero/arr.size() << endl;
}

int main(){
    vector<int> vec = {1,1,0,-1,-1};
    plusMinus(vec);

    return 0;
}