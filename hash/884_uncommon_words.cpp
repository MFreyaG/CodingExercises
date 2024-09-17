#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> tokenize(vector<string>& tokens, string s){
    string buffer = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            tokens.push_back(buffer);
            buffer = "";
        } else {
            buffer += s[i];
        }
    }
    tokens.push_back(buffer);

    return tokens;
}

vector<string> uncommonFromSentences(string s1, string s2) {
    vector<string> tokens, result;
    unordered_map<string, int> hash;
    tokenize(tokens, s1);
    tokenize(tokens, s2);

    for(int i = 0; i < tokens.size(); i++){
        if(hash[tokens[i]] >= 1){
            hash[tokens[i]]++;
        } else {
            hash[tokens[i]] = 1;
        }
    }

    for(int i = 0; i < tokens.size(); i++){
        if(hash[tokens[i]] == 1)
            result.push_back(tokens[i]);
    }

    return result;
}

int main(){
    string s1 = "apple apple", s2 = "banana";
    vector<string> result = uncommonFromSentences(s1, s2);

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    cout << endl;

    return 0;
}