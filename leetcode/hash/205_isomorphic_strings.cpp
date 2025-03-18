#include <iostream>
#include <string>

using namespace std;

// The hash key is 's' char and the mapped value is 't' char.
bool isIsomorphic(string s, string t) {
    int charHashA[128] = {0};
    int charHashB[128] = {0};

    for(int i = 0; i < s.size(); i++){
        int keyA = s[i];
        int keyB = t[i];

        if(charHashA[keyA] == 0 && charHashB[keyB] == 0){
            charHashA[keyA] = t[i];
            charHashB[keyB] = s[i];
        }
        else if(charHashA[keyA] != 0 && charHashB[keyB] != 0){
            if(charHashA[keyA] != t[i] || charHashB[keyB] != s[i])
                return false;
        } else{
            return false;
        }
    }

    return true;
}

int main(){
    string s = "badc", t = "baba";

    cout << isIsomorphic(s, t) << endl;

    return 0;
}