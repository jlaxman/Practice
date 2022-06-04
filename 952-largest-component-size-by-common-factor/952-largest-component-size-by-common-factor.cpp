class Solution {
public:
    class dsu{
        vector<int> parent;
        vector<int> rank;
        public:
        dsu(int n){
            parent.resize(n, -1);
            rank.resize(n, 1);
        }
        void union_set(int x, int y){
            int s1=find_set(x);
            int s2=find_set(y);
            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    rank[s2]+=rank[s1];
                    parent[s1]=s2;
                }else{
                     rank[s1]+=rank[s2];
                    parent[s2]=s1;
                }
            }
        }
        int find_set(int x){
            if(parent[x]==-1) return x;
            return parent[x]=find_set(parent[x]);
        }
    };
public:
    int largestComponentSize(vector<int>& nums) {
        int maxi= *max_element(nums.begin(), nums.end());
        dsu d(maxi+1);
        for(int i=0; i<nums.size(); i++){
            for(int j=2; j<=sqrt(nums[i]); j++){
                if(nums[i]%j==0){
                    d.union_set(nums[i], j);
                    d.union_set(nums[i], nums[i]/j);
                 }
            }
        }
            vector<int> freq(maxi+1, 0);
            int mx=0;
            for(auto num: nums){
                int s1=d.find_set(num);
                freq[s1]++;
                if(freq[s1]>mx){
                    mx=freq[s1];
                }
            }
            return mx;
            
                
        }
        
    
};