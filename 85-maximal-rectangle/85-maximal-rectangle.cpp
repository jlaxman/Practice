class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n=matrix[0].size();
        int m=matrix.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1') dp[i][j]=1;
                if(dp[i][j]!=0){
                    if(j!=0) dp[i][j]+=dp[i][j-1];
                }
            }
        }
        int maxsofar=0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int curr=0;
                int minw=n;
                if(dp[i][j]==0) continue;
                for(int k=i; k>=0; k--){
                    if(dp[k][j]==0) break;
                    minw= min(dp[k][j], minw);
                    int h=i-k+1;
                    curr= minw*h;
                    maxsofar=max(curr, maxsofar); 
                }
                
            }
        }
        return maxsofar;
    }
};