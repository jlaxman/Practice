class Solution {
public:
    int partitionIndex(int start, int end, vector<int>& nums){
        int r= nums[end];
        int i=start;
        for(int j=start; j<end; j++){
            if(nums[j]<=r){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[end]);
        return i;
    }
    
public:
    int quickSelect(int start, int end, int p, vector<int>& nums){
        int j= partitionIndex(start, end, nums);
        if(j==p){
            return nums[j];
        }else if(j<p){
            return quickSelect(j+1, end, p, nums);
        }else{
            return quickSelect(start, j-1, p, nums);
        }
        
    }
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int m= quickSelect(0, n-1, n/2, nums);
        cout<< m<<endl;
        int steps=0;
        for(auto a: nums){
            steps+=abs(a-m);
        }
        return steps;
        
        
    }
};