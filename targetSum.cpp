#include<iostream>
#include<vector>
#include<numeric> // Often useful, though not strictly needed here

using namespace std;

class Solution{
public:
  
    int findWays(vector<int> &nums, int target, int index){
        // Base Case: We've considered all the numbers.
        if(index < 0){
            // If the target is 0, we found one valid way. Otherwise, this path failed.
            return (target == 0) ? 1 : 0;
        }

        // --- RECURSIVE STEP (THE CHOICE) ---
        // For the number at nums[index], we can either add it or subtract it.

        // Choice 1: Add nums[index]. The remaining numbers must sum to (target - nums[index])
        int plus = findWays(nums, target - nums[index], index - 1); // FIX #2 and #3

        // Choice 2: Subtract nums[index]. The remaining numbers must sum to (target + nums[index])
        int minus = findWays(nums, target + nums[index], index - 1); // FIX #2 and #3

        // The total number of ways is the sum of ways from both choices.
        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target){
        // Start the recursion from the last element of the array.
        return findWays(nums, target, nums.size() - 1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int n;
    cin >> n;
    
    // FIX #1: Create the vector with the correct size from the start.
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int target;
    cin >> target;

    int ans = sol.findTargetSumWays(nums, target);

    // It's good practice to print the answer to verify
    cout << ans << endl;

    // The return value of main isn't used by the judge, but 0 indicates success.
    return 0; 
}