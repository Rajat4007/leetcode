class Solution {
public:
    int digit_sum(int x){
        int sum = 0;
        while(x>0){
            int digit = x%10;
            sum+=digit;
            x = x/10;
        }
        return sum;
    }
    int countEven(int num) {
        int count = 0;
        for(int i=2; i<=num; i++){
            int y = digit_sum(i);
            if(y%2==0){
                count++;
            }
        }
        return count;
    }
};