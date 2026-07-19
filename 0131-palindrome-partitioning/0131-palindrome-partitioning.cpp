class Solution {
public:
    bool isPalindrome(string s){
        string s2 = s;
        reverse(s.begin(), s.end());
        return s == s2;
    }
    void findpart(string s, vector<string>&partition, vector<vector<string>>&ans){
        if(s.size() == 0){
            ans.push_back(partition);
            return;
        }

        for(int i=0; i<s.size(); i++){
            string part = s.substr(0,i+1);

            if(isPalindrome(part)){
                partition.push_back(part);
                findpart(s.substr(i+1, s.size()), partition, ans);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>partition;
        vector<vector<string>>ans;
        findpart(s, partition , ans);
        return ans;
    }
};