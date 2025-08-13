#include<iostream>
#include<vector>
#include<numeric> // For std::accumulate
#include<algorithm> // For std::min
#include<cmath> // For std::abs

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }

        // dp[i][j] will be true if a subset with sum j is possible using the first i items
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

        // Base case: a sum of 0 is always possible (with an empty subset)
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }

        // Base case: with only the first element, only a sum equal to its value is possible
        if (arr[0] <= totalSum) {
            dp[0][arr[0]] = true;
        }

        // Fill the DP table
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= totalSum; ++j) {
                // Option 1: Don't include the current element arr[i]
                bool notTake = dp[i - 1][j];
                
                // Option 2: Include the current element arr[i]
                bool take = false;
                if (j >= arr[i]) {
                    take = dp[i - 1][j - arr[i]];
                }
                
                dp[i][j] = take || notTake;
            }
        }

        // Find the minimum difference by checking the last row of the DP table
        int minDiff = -1;

        // We only need to check up to totalSum / 2. For any subset sum s1 > totalSum/2,
        // the other subset sum (totalSum - s1) will be smaller, and we would have already processed it.
        for (int j = 0; j <= totalSum / 2; ++j) {
            // Check if a subset with sum 'j' is possible using all elements
            if (dp[n - 1][j]) {
                int currentDiff = abs(totalSum - 2 * j);
                if (minDiff == -1 || currentDiff < minDiff) {
                    minDiff = currentDiff;
                }
            }
        }

        return minDiff;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    vector<int> arr;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    cout << "The minimum difference is: " << sol.minDifference(arr) << endl;

    return 0;
}
