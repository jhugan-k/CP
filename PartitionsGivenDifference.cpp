#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* - count number of subsets where subset sum = (totalsum + d) / 2

*/
class Solution {
  public:
    int countSum(vector<int> &arr, int i, int target, vector<vector<int>> &dp){
        //base cases
        if(i == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || arr[0] == target) return 1;
            return 0;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        //recursion: pick and notpick
        int pick = target >= arr[i] ? countSum(arr,i-1,target-arr[i],dp) : 0;
        int notPick = countSum(arr,i-1,target,dp);
        
        return dp[i][target] = pick + notPick;
    }
    
    int countPartitions(vector<int>& arr, int d) {
        //find sum
        int totalsum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            totalsum += arr[i];
            
        }
        if ((d + totalsum) % 2 != 0 || (d > totalsum)) return 0;
        int target = (d + totalsum) / 2;
        
        vector<vector<int>> dp(arr.size(), vector<int> (target + 1, -1 ));
        int count = countSum(arr,arr.size() - 1,target,dp);
        return count;
        
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //---
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    Solution sol; 
    int d;
    cin >> d;

    return sol.countPartitions(arr,d);
    
}