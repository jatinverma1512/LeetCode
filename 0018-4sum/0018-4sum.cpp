class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;

        if(n < 4) return result;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1;
                int right = n-1;
                long long newTarget = (long long)target - nums[i] - nums[j];

                while(left < right){
                    long long sum = (long long)nums[left]+nums[right];
                    if(sum == newTarget){
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left -1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }
                    else if(newTarget > sum){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return result;

    }
};