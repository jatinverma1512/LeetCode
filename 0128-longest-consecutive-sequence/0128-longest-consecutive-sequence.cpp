class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int num: nums){
            s.insert(num);
        }

        int  maxLen = 0;

        for(int num : s){
            //agr map mein num se chota element nhi milta toh ussi ko current maan lo
            if(s.find(num - 1) == s.end()){
                int currNum = num;
                int len = 1;

                while(s.find(currNum+1) != s.end()){
                    currNum++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};