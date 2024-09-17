#include <iostream>
#include <string>

using namespace std;

bool containsChar(string subs, char c){
    for(int i = 0; i < subs.size(); i++){
        if(subs[i] == c)
            return true;
    }
    return false;
}

int lengthOfLongestSubstring(string s) {
    int l = 0, best = 0, cur = 0;
    string subs = "";
    for(int r = 0; r < s.size(); r++){
        if(containsChar(subs, s[r]) == false){
            subs += s[r];
            cur++;
        }
        else{
            subs += s[r];
            cur++;
            while(s[l] != s[r]){
                cur--;
                subs.erase(0,1);
                l++;
            }
            cur--;
            subs.erase(0,1);
            l++;
        }
        if(cur > best)
            best = cur;
    }
    return best;
}

int main(){
    string s = "aab";
    
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}