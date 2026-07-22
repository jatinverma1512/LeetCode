class Solution {
public:
    string expandAroundCenter(string &s, int i, int j){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        return s.substr(i+1, j-i-1);
    }
    string longestPalindrome(string s) {
        string longest = "";
        for(int i=0; i<s.length(); i++){
            string odd = expandAroundCenter(s,i,i);
            if(odd.length() > longest.length()){
                longest = odd;
            }

            string even = expandAroundCenter(s,i,i+1);
            if(even.length() > longest.length()){
                longest = even;
            }
        }

        return longest;
    }
};