class Solution {
public:
    bool checkDivisibility(int n) {
        int number = n;
        int multiplied = 1;
        int added = 0;
        while(n>0){
            int last_digit = n%10;
            added+=last_digit;
            multiplied *= last_digit;
            n=n/10;
        }
        if(number%(added+multiplied)==0){
            return true;
        }else{
            return false;
        }
    }
};