class Solution {
public:
    bool solveMem(vector<int>&nums, int target, int i, vector<vector<int>>&dp){
        if(target < 0 || i == nums.size()) return false;
        if(target == 0) return true;

        if(dp[target][i] != -1){
            return dp[target][i];
        }

        bool inc = solveMem(nums, target-nums[i], i+1,dp);
        bool exc = solveMem(nums, target, i+1,dp);
        bool ans = inc || exc;

        dp[target][i] = ans;
        return dp[target][i];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;

        int target = sum/2;

        vector<vector<int>>dp(target+1, vector<int>(n+1, -1));
        bool ans = solveMem(nums, target, 0, dp);
        return ans;
    }
};