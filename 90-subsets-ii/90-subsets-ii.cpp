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
       
        unordered_set<string> seen;
        // generateSub(0, nums.size(), ds, ans, nums);
        vector<vector<int>> res;
        for(int i=0; i< (1<<nums.size()); i++){
             vector<int> ds;
             string arg;
            for(int k=0; k<nums.size(); k++){
                if(i&(1<<k)){
                    ds.push_back(nums[k]);
                    arg.push_back(nums[k]+'#');
                }
            }
            if(seen.find(arg)==seen.end()){
                seen.insert(arg);
                res.push_back(ds);
            }
            
            
        }
        
        return res;
        
    }
};