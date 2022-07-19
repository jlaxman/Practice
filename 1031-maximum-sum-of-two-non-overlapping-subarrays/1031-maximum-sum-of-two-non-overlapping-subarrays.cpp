class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int fL, int sL) {
        int n=nums.size();
        int sum=0;
        
        vector<int> sf(n-fL+1, 0), ss(n-sL+1, 0);
        for(int i=0; i<n; i++){
            sum+= nums[i];
            if(i>= fL-1){
                sf[i-fL+1]=sum;
                sum-=nums[i-fL+1];
            }
        }
        sum=0;
        for(int i=0; i<n; i++){
            sum+= nums[i];
            if(i>= sL-1){
                ss[i-sL+1]=sum;
                sum-=nums[i-sL+1];
            }
        }
        int mx=0;
        for(int i=0; i<= n-fL; i++){
            
            for(int j= i+fL; j<= n-sL; j++){
                mx=max(sf[i]+ss[j],mx);
            }
            for(int j= 0; j<i; j++){
                if(j+sL-1<i) mx=max(sf[i]+ss[j],mx);
            }
            
        }
        return mx;
        
        
        
        
        
        
        
    }
};