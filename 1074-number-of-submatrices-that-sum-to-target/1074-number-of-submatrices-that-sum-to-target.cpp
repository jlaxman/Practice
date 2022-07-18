class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n=matrix[0].size();
        vector<vector<int> > pre(m+1, vector<int>(n+1, 0));
        int ans=0;
        pre[0][0]=matrix[0][0];
        // if(target==pre[0][0]) ans++;
        
        for(int i=1; i<m; i++){
            pre[i][0]= matrix[i][0]+pre[i-1][0];
            // if(pre[0][i]==target) ans++;
        }
        for(int i=1; i<n; i++){
            pre[0][i]= matrix[0][i]+pre[0][i-1];
             // if(pre[i][0]==target) ans++;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                pre[i][j]= matrix[i][j]+ pre[i-1][j]+ pre[i][j-1]-pre[i-1][j-1];
            }
        }
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=i; j<m; j++){
                
                unordered_map<int, int> mpp;
                mpp[0]=1;
                for(int k=0; k<n; k++){
                    int a=0;
                    if(i!=0) a=pre[j][k]-pre[i-1][k];
                    else a= pre[j][k];
                    if(mpp.find(-target+a)!=mpp.end()){
                        cnt+= mpp[-target+a];
                    }
                    mpp[a]++;
                    
                }
                
                
            }
        }
        return cnt;
    }
};