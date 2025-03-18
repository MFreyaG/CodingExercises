#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    unordered_map<string, int> hash;
    for(int i = 0; i < strings.size(); i++){
        if(hash.find(strings[i])!=hash.end()) hash.at(strings[i])++;
        else hash.insert({strings[i], 1});
    }

    vector<int> result;
    for(int i = 0; i < queries.size(); i++){
        int curr;
        if(hash.find(queries[i]) != hash.end()) curr = hash.at(queries[i]);
        else curr = 0;
        result.push_back(curr);
    }

    return result;
}

int main(){
    vector<string> s1 = {"aba", "baba", "aba", "xzxb"};
    vector<string> q1 = {"aba", "xzxb", "ab"};

    vector<int> r1 = matchingStrings(s1, q1);
    for(int i = 0; i < r1.size(); i++) cout << r1[i] << endl;

    cout << endl;

    vector<string> s2 = {"def", "de", "fgh"};
    vector<string> q2 = {"de", "lmn", "fgh"};

    vector<int> r2 = matchingStrings(s2, q2);
    for(int i = 0; i < r2.size(); i++) cout << r2[i] << endl;

    return 0;
}