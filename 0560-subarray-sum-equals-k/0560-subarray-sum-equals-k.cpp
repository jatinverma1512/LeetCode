class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;

        unordered_map<int,int>f;

        f[0] = 1;  // 0 sum ek baar dekh chuke h

        for(int num : nums){
            sum += num;
            int ques = sum-k;
            int freq = f[ques];
            res += freq;

            f[sum]++;
        }
        return res;
    }
};