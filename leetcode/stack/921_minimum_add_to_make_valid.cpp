#include <iostream>
#include <vector>

using namespace std;

int minAddToMakeValid(string s){
    vector<char> stack;

    for(int i = 0; i < s.size(); i++){
        if(!stack.empty() && stack.back() == '(' && s[i] == ')'){
            stack.pop_back();
        } else {
            stack.push_back(s[i]);
        }
    }

    return stack.size();
}

int main(){
    string s1 = "())";

    cout << minAddToMakeValid(s1) << endl;

    string s2 = "(((";

    cout << minAddToMakeValid(s2) << endl;

    
    string s3 = "()))((";

    cout << minAddToMakeValid(s3) << endl;

    return 0;
}