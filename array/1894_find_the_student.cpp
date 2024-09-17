#include <iostream>
#include <vector>

using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
    long long chalkUses = 0;
    for(int i = 0; i < chalk.size(); i++){
        chalkUses += chalk[i];
    }

    if(chalkUses == 0)
        return 0;

    long long replaceAfter = k % chalkUses;
    for(int i = 0; i < chalk.size(); i++){
        replaceAfter -= chalk[i];
        if(replaceAfter < 0)
            return i;
    }

    return -1;
}

int main(){
    vector<int> chalk = {5,1,5};
    int k = 22;

    cout << chalkReplacer(chalk, k) << endl;

    return 0;
}