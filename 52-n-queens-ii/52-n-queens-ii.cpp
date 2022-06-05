class Solution {
private:
   int ans;
    vector<int> col, cross, across;
public:
    void recurseQueens(int i, int n, vector<string>& ds ){
        if(i==n){
            ans++;
            return ;
        }
        for(int k=0; k<n; k++){
            if(col[k]==0 && cross[i+k]==0 && across[k-i+n-1]==0){
                ds[i][k]='Q';
                col[k]=1;
                cross[i+k]=1;
                across[k-i+n-1]=1;
                recurseQueens(i+1, n, ds);
                ds[i][k]='.';
                col[k]=0;
                cross[i+k]=0;
                across[k-i+n-1]=0;
            }
            
        }
        
        
    }
public:
    int totalNQueens(int n) {
        ans=0;
        string temp;
        for(int i=0; i<n; i++){
            temp+='.';
        }
        col.resize(n, 0);
        cross.resize(2*n-1, 0);
        across.resize(2*n-1, 0);
       vector<string> ds(n, temp);
       recurseQueens(0,n, ds);
       return ans;
    }
};