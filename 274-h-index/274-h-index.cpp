class Solution {

public:
    bool predicate(int m, vector<int>& c){
        int cnt=0;
        for(auto n: c){
            if(n>=m){
                cnt++;
            }
        }
        return cnt>=m;
    }
    int hIndex(vector<int>& c) {
//         int l;
//          int r;
//         l=0;
//         r=c.size();
//         int ans=0;
//         while(l<=r){
//             int mid=(l+r)/2;
//             if(predicate(mid, c)){
//                 l=mid+1;
//                 ans=mid;
//             }else{
//                 r=mid-1;
//             }
            
//         }
//         return ans;
        
        
//         sort(c.begin(), c.end());
//         int ans=0;
//         for(int i=0; i<c.size(); i++){
//             int r= c.size()-i;
//             ans=max(ans, min(r, c[i]));
            
//         }
//         return ans;
        
        int n=c.size();
        vector<int> cnt(n+1, 0);
        for(auto m: c){
            cnt[min(m, n)]++;
        }
        int k=n;
        int sum=cnt[n];
        while(k>sum){
            k--;
            sum+=cnt[k];
        }
        return k;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};