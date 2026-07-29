class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int ans = INT_MIN;

        if(s.length() == 0) return 0; 

        unordered_map<char,int>mp;

        for(int high = 0; high < s.length(); high++){
            mp[s[high]]++;

            while(mp[s[high]] > 1){
                mp[s[low]]--;
                if(mp[s[low]] == 0){
                    mp.erase(s[low]);
                }
                low++;
            }

            int len = high - low +1;
            ans = max(ans, len);
        }
        return ans;
    }
};