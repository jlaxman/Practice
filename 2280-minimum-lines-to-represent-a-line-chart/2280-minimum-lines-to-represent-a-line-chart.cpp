class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        
        
        int n=sp.size();
        if(n==1) return 0;
        
        sort(sp.begin(), sp.end());
        vector<double > slope(n, 0);
        int ans=0;
        long double prev;
        prev=INT_MAX;
        
        for(int i=1; i<n; i++){
            // cout<< sp[i][0]<<" "<<sp[i][1]<<endl;
            long double div=((sp[i][1]-sp[i-1][1]));
            long double divi=((sp[i][0]-sp[i-1][0]));
            // cout<< div<<" "<<divi<<endl;
            long double curr=  div/(divi);
           
            
            if(curr!=prev) {
                ans++;
            }
            prev= curr;
          
            
            
        }
        return ans;
        
    }
};