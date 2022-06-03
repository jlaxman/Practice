class NumMatrix {
private:
    vector<vector<int>> row, col;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> rowPrefix(matrix.begin(), matrix.end());
        vector<vector<int>> colPrefix(matrix.begin(), matrix.end());
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                rowPrefix[i][j]+= rowPrefix[i][j-1];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                colPrefix[j][i]+= colPrefix[j-1][i];
            }
        }
        row=rowPrefix;
        col=colPrefix;
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int R= row2-row1;
        int C= col2-col1;
        int ans=0;
        if(R<C){
           for(int i=row1; i<=row2; i++){
               if(col1!=0) ans+= row[i][col2]-row[i][col1-1];
               else ans+= row[i][col2];
           } 
        }else{
            for(int i=col1; i<=col2; i++){
               if(row1!=0) ans+= col[row2][i]-col[row1-1][i];
               else ans+= col[row2][i];
           } 
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */