#include <iostream>
#include <string>

using namespace std;

bool is_subsequence(string s, string t){
    int s_size = s.size(), t_size = t.size();

    if(s_size == 0)
        return true;
    else if(t_size == 0)
        return false;
    
    int buffer = 0, i = 0, j = 0;
    while(1){
        if(s[i] == t[j]){
            buffer++, i++, j++;
        } else {
            j++;
        }

        if(j > t_size)
            return false;
        else if(buffer == s_size){
            return true;
        }
    }
}

int main(){
    string s = "abc", t = "ahbgdc";
    
    cout << is_subsequence(s, t) << endl;

    return 0;
}