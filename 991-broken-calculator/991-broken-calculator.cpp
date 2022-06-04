class Solution {
public:
    int minSteps(int i, int t){
        if(i==t) return 0;
        if(t<i) return i-t;
        int cnt=0;
        while(i<t){
            if(t%2==0){
                t/=2;
                cnt++;
            }else{
                t++;
                cnt++;
            }
            
        }
        return cnt+i-t;
    }
    
public:
    int brokenCalc(int startValue, int target) {
       return minSteps(startValue, target);
    }
};