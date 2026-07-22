class Solution {
public:
    int romanToInt(string s) {
        unordered_map<int,int> roman{
            {'I' , 1}, {'V', 5}, {'X', 10}, {'L',50},
            {'C' , 100}, {'D',500}, {'M', 1000}
        };

        int total = 0;
        for(int i=0; i<s.length(); i++){
            int val = roman[s[i]];
            int nextval = (i+1 <s.size())? roman[s[i+1]] : 0;

            if(val < nextval){
                total -= val;
            }
            else{
                total += val;
            }
        }
        return total;
    }
};