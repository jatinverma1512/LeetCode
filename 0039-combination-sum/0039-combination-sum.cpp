class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& candidates, int target, int i, vector<int>&path){
        if(i == candidates.size()) return;
        
        if(target == 0){
            result.push_back(path);
            return;
        }

        if(candidates[i] <= target){
            path.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i, path);
            path.pop_back();
        }

        solve(candidates, target, i+1, path);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>path;
        solve(candidates, target, 0, path);
        return result;
    }
};