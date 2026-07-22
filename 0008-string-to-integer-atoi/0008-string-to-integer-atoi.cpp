class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        long result = 0;
        int sign = 1;

        //ignore whitespace
        while(i<n && s[i] == ' '){
            i++;
        }
        //check sign
        if(i<n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }

        //read digit
        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0';
            result = result * 10 + digit;

            if(sign == 1 && result > INT_MAX) return INT_MAX;
            if(sign == -1 && -result < INT_MIN) return INT_MIN;
            
            i++;
        }

        return (sign*result);
    }
};