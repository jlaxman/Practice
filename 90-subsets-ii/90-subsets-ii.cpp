class Solution {
public:
     void generateSub(int i, int n, vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums){
         if(i==n){
             ans.push_back(ds);
             return ;
         }
         ds.push_back(nums[i]);
         generateSub(i+1, n, ds, ans, nums);
         ds.pop_back();
         int c=nums[i];
         while(i<n && nums[i]==c){
             i++;
         }
         generateSub(i, n, ds, ans, nums);
         return ;
         
     }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       
        set<vector<int>> ans;
        // generateSub(0, nums.size(), ds, ans, nums);
        for(int i=0; i< (1<<nums.size()); i++){
             vector<int> ds;
            for(int k=0; k<nums.size(); k++){
                if(i&(1<<k)){
                    ds.push_back(nums[k]);
                }
            }
            ans.insert(ds);
            
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
        
    }
};