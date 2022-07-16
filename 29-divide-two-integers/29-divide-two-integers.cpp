class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        int p=0;
        if(dividend>0) {
            dividend= -dividend;
            p++;
        }
        if(divisor>0) {
            divisor= -divisor;
            p++;
        }
        if(dividend>divisor) return 0;
       int power=31;
       long long res=0;
       long long y= (-1LL* divisor<< power);
       y=-y;
        while(dividend<= divisor){
            while(y<dividend){
                y=y>>1LL;
                power--;
            }
            res+= -(1LL<<power);
            dividend-=y; 
        }
        if(p==1){
            if(res<INT_MIN){
                return INT_MIN;
            }else return res;
            
        }
        else{
            // cout<<p<<res<<endl;
            if(-1LL*res>INT_MAX){
                return INT_MAX;
            }else return -1*res;
           
        }
        
        
    }
};