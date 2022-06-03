class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n%2==0){
            double ans= myPow(x, n/2);
            return ans*ans;
        }else{
            double y= n>0? x: 1.0/x;
            double ans= myPow(x, n/2);
            return ans*ans*y;
        }
    }
};