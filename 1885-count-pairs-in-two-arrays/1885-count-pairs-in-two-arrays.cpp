class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<long long> vec;
        for(int i=0; i<n; i++){
            vec.push_back(nums1[i]-nums2[i]);
        }
        long long ans=0LL;
        sort(vec.begin(), vec.end());
        for(int i=0; i<n; i++){
            int ind=upper_bound(vec.begin()+i+1, vec.end(), -vec[i])-vec.begin();
            ans+= (1LL*(n-ind));
        }
        return ans;
        
    }
};