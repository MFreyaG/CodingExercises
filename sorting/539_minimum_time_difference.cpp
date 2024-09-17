#include <iostream>
#include <string>
#include <vector>

using namespace std;

int partition(vector<string>& timePoints, int low, int high){
    string pivot = timePoints[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (timePoints[j] <= pivot) {
            i++;
            swap(timePoints[i], timePoints[j]);
        }
    }
    i++;
    swap(timePoints[i], timePoints[high]);

    return i;
}

void quicksort(vector<string>& timePoints, int low, int high) {
    if (low < high) {
        int pi = partition(timePoints, low, high);
        quicksort(timePoints, low, pi - 1); 
        quicksort(timePoints, pi + 1, high);
    }
}

int difference(string time1, string time2){
    int hours1 = stoi(string(1, time1[0]) + string(1, time1[1]));
    int minutes1 = stoi(string(1, time1[3]) + string(1, time1[4]));

    int hours2 = stoi(string(1, time2[0]) + string(1, time2[1]));
    int minutes2 = stoi(string(1, time2[3]) + string(1, time2[4]));
    
    int total_diff = ((hours2 - hours1) * 60) + (minutes2 - minutes1);
    if(total_diff > 12*60)
        total_diff = 24*60 - total_diff;

    return total_diff;
}

int findMinDifference(vector<string>& timePoints) {
    quicksort(timePoints, 0, timePoints.size() - 1);

    int min = 12*60 + 1, diff;
    for(int i = 1; i < timePoints.size(); i++){
        diff = difference(timePoints[i - 1], timePoints[i]);
        if(diff < min)
            min = diff;
    }
    diff = difference(timePoints[0], timePoints[timePoints.size()-1]);
    if(diff < min)
        min = diff;

    return min;
}

int main(){
    vector<string> timePoints = {"00:00","04:00","22:00"};
    
    cout << findMinDifference(timePoints) << endl;

    return 0;
}