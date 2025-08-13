#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    //pick or notPick 
    //if reached last index, check remaining target and nums[0]
    //return accordingly 

    public:
    int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    
    // dp[i][j] = number of ways to get sum 'j' using first 'i' elements
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Correct Base Case: With 0 items, there is 1 way to make sum 0.
    dp[0][0] = 1;

    // Main loops to fill the table
    // Start from i=1 to build upon the i=0 base case
    for (int i = 1; i <= n; i++) {
        // The current number is arr[i-1] because of 0-based indexing
        int current_num = arr[i - 1]; 
        
        // Iterate through all possible sub-targets from 0 to target
        for (int j = 0; j <= target; j++) {
            // Option 1: Don't pick the current number (arr[i-1])
            int notPick = dp[i - 1][j];

            // Option 2: Pick the current number
            int pick = 0;
            if (j >= current_num) {
                pick = dp[i - 1][j - current_num];
            }
            
            // The result for dp[i][j] is the sum of both options
            dp[i][j] = pick + notPick;
        }
    }
    
    return dp[n][target];
}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //cin-cout input: array with size n
    int n;
    cin >> n;
    vector<int>arr;

    for(int i = 0; i <n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    Solution sol;
    int target;
    cin >> target;

    int ans = sol.perfectSum(arr,target);
    cout << ans;
    return 0;
}