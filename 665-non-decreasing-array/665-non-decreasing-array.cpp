class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<=nums[i+1]) continue;
            else{
                 if(flag==1) return 0;
                if(i!=0){
                   
                    if(nums[i-1]<=nums[i+1]){
                        flag=1;
                    }else{
                        nums[i+1]=nums[i];
                        flag=1;
                    }
                }else{
                    flag=1;
                }
            }
        }
        return 1;
        
    }
};