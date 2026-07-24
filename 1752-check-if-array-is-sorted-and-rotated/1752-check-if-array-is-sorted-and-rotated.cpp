class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                count++;
            }
        }

        //check cirular loop
        if(nums[n-1] > nums[0]){
            count++;
        }

        return count <= 1;

    }
};