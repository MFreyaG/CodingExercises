#include <iostream>
#include <string>

using namespace std;

string convertString(string s){
    string result = "";
    for(int i = 0; i < s.size(); i++){
        result += to_string(s[i] - 'a' + 1);
    }

    return result;
}

int getLucky(string s, int k){
    string numerical_string = convertString(s);

    int buffer = 0;
    for(int i = 0; i < k; i++){
        buffer = 0;
        for(int j = 0; j < numerical_string.size(); j++){
            buffer += numerical_string[j] - '0';
        }
        numerical_string = to_string(buffer);
    }

    return buffer;
}

int main(){
    string s = "zbax";
    int k = 2;

    cout << getLucky(s, k) << endl;

    return 0;
}