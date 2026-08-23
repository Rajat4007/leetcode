class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        
        int left_sum = 0;
        int right_sum = 0;
        int left_q = 0; 
        int right_q=0;
        for(int i=0;i<n/2;i++){
            if(num[i] != '?'){
                left_sum += num[i] - '0';
            }else{
                left_q++;
            }
            if(num[n-i-1] != '?' ){
                right_sum += num[n-i-1]-'0';
            }else{
                right_q++;
            }
        }
        if((left_q+right_q)%2 != 0){
            return true;
        }
        if((2*(left_sum - right_sum)+9*(left_q - right_q) == 0)){
            return false;
        }
        return true;
    }
};