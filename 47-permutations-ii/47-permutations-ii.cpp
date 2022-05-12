class Solution {
    int N;
public:
    bool check(vector<bool> visited){
        for(int i=0; i<visited.size(); i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
    
public:
    void fun(vector<int>& nums, vector<bool>& visited, vector<int>& temp, vector<vector<int>>& vec){
        if(check(visited)){
            vec.push_back(temp);
            return ;
        }
        int i=0;
        while(i<nums.size()){
            if(visited[i]==true){
                i++;
                continue;
            }
            
            visited[i]=true;
            temp.push_back(nums[i]);
            fun(nums, visited, temp, vec);
            visited[i]=false;
            temp.pop_back();
            int var=nums[i];
            while(i< nums.size() && nums[i]==var){
                i++;
            }
    
        }
        
        
        
        
        
        
        
        
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visited(n, false);
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> vec;
        fun(nums, visited, temp, vec);
        return vec;
    }
};