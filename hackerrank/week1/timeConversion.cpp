#include <iostream>
#include <string>

using namespace std;

string timeConversion(string s){
    string time = s.substr(8, s.size()), result = s;

    int hours = stoi(s.substr(0,2));
    if(time == "PM"){
        if(hours == 12) return result.substr(0, 8);
        hours += 12;

        if(hours == 24) result = "00" + s.substr(2,s.size());
        else result = to_string(hours) + s.substr(2,s.size());
    } else if(time == "AM" && hours == 12){
        result = "00" + s.substr(2,s.size());
    }

    return result.substr(0, 8);
}

int main(){
    string s1 = "07:05:45PM";
    string s2 = "12:00:00PM";
    cout << timeConversion(s1) << endl;
    cout << timeConversion(s2) << endl;
    return 0;
}