#include <iostream>
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int charHash[26] = {0};
    for(int i = 0; i < magazine.size(); i++)
        charHash[magazine[i]-'a']++;

    for(int i = 0; i < ransomNote.size(); i++){
        charHash[ransomNote[i]-'a']--;
        if(charHash[ransomNote[i]-'a'] < 0)
            return false;
    }  

    return true;
}

int main(){
    string ransomNote = "aa", magazine = "aba";

    cout << canConstruct(ransomNote, magazine) << endl;

    return 0;
}