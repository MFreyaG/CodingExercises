#include <iostream>
#include <unordered_map>

using namespace std;

// ababccc
int maxUniqueSplit(string s){
    if(s.size() == 0) return 0;
    else if(s.size() == 1) return 1;

    unordered_map<string, bool> hash;
    int index = 0, result = 0;

    string current = "", previous = "";
    while(index != s.size() + 1){
        current += s[index];
        cout << current << endl;
        if(hash.find(current) == hash.end()){
            hash[current] = true;

            previous = current;
            current = "";
            result++;
        }
        else {
            hash.erase(previous);
            current = previous;
            index--;
            result--;
        }
        index++;
    }

    return result - 1;
}

int main(){
    string s1 = "ababccc";
    cout << maxUniqueSplit(s1) << endl;
    return 0;
}