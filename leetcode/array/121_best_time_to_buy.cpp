#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices){
    int result = 0, buy_i = 0;
    for(int sell_i = 1; sell_i < prices.size(); sell_i++){
        if(prices[sell_i] - prices[buy_i] < result){
            if(prices[sell_i] < prices[buy_i]){
                buy_i = sell_i;
                sell_i = buy_i;
            }
        } else {
            result = prices[sell_i] - prices[buy_i];
        }
    }

    return result;
}

int main(){
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << maxProfit(prices1) << endl;

    vector<int> prices2 = {2, 1, 4};
    cout << maxProfit(prices2) << endl;

    vector<int> prices3 = {2,1,2,1,0,1,2};
    cout << maxProfit(prices3) << endl;

    return 0;
}