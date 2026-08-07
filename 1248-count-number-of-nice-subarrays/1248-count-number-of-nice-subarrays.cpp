class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int low = 0;
        int countOdd = 0;
        int ans = 0;

        for(int high = 0; high<nums.size(); high++){
            if(nums[high] % 2 == 1){
                countOdd++;
            }

            while(countOdd > k){
                if(nums[low] % 2 == 1){
                    countOdd--;
                }
                low++;
            }

            ans = ans + (high-low+1);
        } 
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};