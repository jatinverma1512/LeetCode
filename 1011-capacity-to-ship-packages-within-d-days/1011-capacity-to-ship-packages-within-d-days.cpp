class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int capacity){
        int load = 0;
        int dayused = 1;
        for(int num: weights){
            if(load + num <= capacity){
                load += num;
            }
            else{
                dayused++;
                load = num;
            }
        }
        return dayused <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(),0);

        int ans = e;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(isPossible(weights, days, mid)){
                ans = mid;
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};