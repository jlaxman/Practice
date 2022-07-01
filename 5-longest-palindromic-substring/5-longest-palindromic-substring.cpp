class Solution {
public:
    pair<int,int> expCenter(string& s, int l, int r){
        int n=s.size();
        while(l>=0 && r<n){
            if(s[l]==s[r]){
                l--;
                r++;
            }else{
                break;
            }
        }
        return make_pair(l, r-l-1);
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
//         int dp[n+1][n+1];
//         memset(dp, 0, sizeof dp);
//         string ans;
//         int maxl=1;
//         ans=s[0];
//         int start=0;
        
//         for(int i=0; i<n; i++) dp[i][i]=1;
//         for(int i=0; i<n-1; i++){
//             if(s[i]==s[i+1]){
//                 dp[i][i+1]=1;
//                 start=i;
//                 maxl=2;
//             }
//         }
        
//         for(int l=3; l<=n; l++){
//             for(int i=0; i<=n-l; i++){
//                 if(s[i]==s[i+l-1] && dp[i+1][i+l-2]){
//                     dp[i][i+l-1]=1;
//                 }
//                 if(dp[i][i+l-1] && l>maxl){
//                     maxl=l;
//                     start=i;
//                 }
//             }
//         }
//         return s.substr(start, maxl);
        int maxl=1;
        
        string ans;
        ans=s[0];
        int start=0;
        for(int i=0; i<n-1; i++){
            auto l1= expCenter(s, i, i);
            auto l2= expCenter(s, i, i+1);
           if(l2.second>= l1.second && maxl<l2.second){
               maxl=l2.second;
               start=l2.first+1;
               
           }else if(l1.second>= l2.second && maxl<l1.second){
               maxl=l1.second;
               start=l1.first+1;
           }
        }
        return s.substr(start, maxl);
        
        
    }
};