class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       unordered_set<int> st;
        int sum=0;
        int mx=0;
        int j=0;
        for(int i=0; i<nums.size(); i++){
           if(st.find(nums[i])==st.end()){
               sum+=nums[i];
               st.insert(nums[i]);
               mx=max(sum, mx);
               continue;
           }
           while(st.find(nums[i])!=st.end()){
               sum-=nums[j];
               auto f=st.find(nums[j]);
               st.erase(f);
               j++;
           }
            st.insert(nums[i]);
            sum+=nums[i];
        }
        return mx;
        
        
    }
};