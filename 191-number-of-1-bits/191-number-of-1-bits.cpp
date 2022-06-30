class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        // for(int i=31; i>=0; i--){
        //     if(n & (1<<i)) cnt++;
        // }
        while(n){
            cnt++;
            n&=(n-1);
        }
        
        return cnt;
        
    }
};