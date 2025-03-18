#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string input){
    string result;
    for (char c : input) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            result += std::tolower(static_cast<unsigned char>(c));
        }
    }

    int size = result.size();
    if(size == 1 or size == 0) 
        return true;

    int i = 0, j = size - 1;
    while(i <= j){
        if(result[i] != result[j])
            return false;

        i++, j--;
    }
    return true;
}
int main(){
    string input = "race a car";
    
    cout << is_palindrome(input) << endl;

    return 0;
}