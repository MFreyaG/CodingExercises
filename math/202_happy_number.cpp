#include <iostream>
#include <string>

using namespace std;

bool isHappy(int n){
    string num;
    int buffer = 0;
    while(buffer != 1){
        buffer = 0;
        num = to_string(n);

        int aux;
        for(int i = 0; i < num.size(); i++){
            aux = num[i] - '0';
            buffer += aux*aux;
        }
        
        if(buffer == 4)
            return false;

        n = buffer;
    }
    
    return true;
}

int main(){
    int n = 19;

    cout << isHappy(n) << endl;

    return 0;
}