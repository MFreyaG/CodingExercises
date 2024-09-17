#include <iostream>

using namespace std;

bool isAnagram(string s, string t){
    int hash[26] = {0};
    if(s.size() != t.size())
        return false;
        
    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a']++;
    }

    for(int i = 0; i < t.size(); i++){
        hash[t[i] - 'a']--;

        if(hash[t[i] - 'a']< 0)
            return false;
    }

    return true;
}

int main(){
    string s = "", t = "";

    cout << isAnagram(s, t) << endl;

    return 0;
}