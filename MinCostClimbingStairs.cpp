
#include<vector>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;
class solution{
    public:
    //recursion function 
    int climb(vector<int> &cost, int i){
        if(i == 0) return cost[0];
        if(i == 1) return cost[1];

        //cost to reach any i
        int cost1 = cost[i] + climb(cost,i-1);
        int cost2 = cost[i] + climb(cost,i-2);
        return min(cost1, cost2);
    }

    int climbingStairs(vector<int> &cost){
        //shift to dp
        vector<int>dp(cost.size(), -1);
        //enter base cases
        dp[0] = cost[0];
        dp[1] = cost[1];
        //fill dp
        for(int i = 2; i < cost.size(); i++){
            int cost1 = cost[i] + dp[i-1];
            int cost2 = cost[i] + dp[i-2];
            dp[i] = min(cost1, cost2);
        }
        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    solution sol;

    //input is an array 
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> cost;
    int number;
    while(iss >> number){
        cost.push_back(number);
    }

    int ans = sol.climbingStairs(cost);
    cout << ans;
    //cin - cout
    return 0;
}
