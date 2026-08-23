class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int leftsum = 0;
        int rightsum = 0;

        int leftQnMark = 0;
        int rightQnMark = 0;

        for(int i=0; i<n; i++){
            if(num[i] == '?'){
                if(i < n/2){
                    leftQnMark++;
                }
                else{
                    rightQnMark++;
                }
            }
            else{
                if(i < n/2){
                    leftsum += num[i]-'0';
                }
                else{
                    rightsum += num[i]-'0';
                }
            }
        }

        int totalQnMark = leftQnMark + rightQnMark;
        if(totalQnMark % 2 == 1){ // odd alice always win
            return true;
        }

        int LEFT = 2 * leftsum + 9*leftQnMark;
        int RIGHT = 2 * rightsum + 9*rightQnMark;

        if(LEFT == RIGHT){
            return false;
        }
        else{
            return true;
        }
    }
};