class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int ans = INT_MIN;

        unordered_map<char,int> freq;
        
        if(s.length() == 0) return 0;

        for(int high = 0; high<s.length(); high++){
            freq[s[high]]++;

            while(freq[s[high]] > 1){
                freq[s[low]]--;
                if(freq[s[low]] == 0){
                    freq.erase(s[low]);
                }
                low++;
            }

            int len = high-low+1;
            ans = max(ans,len);
        }
        return ans;
    }
};