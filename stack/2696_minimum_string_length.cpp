#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minLength(string s){
    int result = s.size();
    if(result == 0)
        return result;

    vector<char> stack;
    for(int i = 0; i < s.size(); i++){
        if(!stack.empty() && stack.back() == 'A' && s[i] == 'B'){
            result-= 2;
            stack.pop_back();
        } else if(!stack.empty() && stack.back() == 'C' && s[i] == 'D'){
            result-= 2;
            stack.pop_back();
        } else{
            stack.push_back(s[i]);
        }
    }
    
    return result;
}

int main(){
    string s = "ABFCACDB";

    cout << minLength(s) << endl;

    return 0;
}