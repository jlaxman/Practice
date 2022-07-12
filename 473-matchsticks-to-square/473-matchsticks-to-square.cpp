class Solution {
public:
   int recurse(int i, vector<int>& m, int X, int l, int r, int u, int d){
       if(i==m.size()){
           if(l==r && r==u && u==d && d==X){
               return 1;
           }
           return 0;
       }
       int op1=0, op2=0, op3=0, op4=0;
        if(l+m[i]<=X){
            op1=recurse(i+1, m, X, l+m[i], r, u, d);
            if(op1) return 1;
        }
        if(r+m[i]<=X){
            op2=recurse(i+1, m, X, l, r+m[i], u, d);
            if(op2) return 1;
        }
        if(u+m[i]<=X){
            op3=recurse(i+1, m, X, l, r, u+m[i], d);
            if(op3) return 1;
        }
        if(d+m[i]<=X){
            op4=recurse(i+1, m, X, l, r, u, d+m[i]);
            if(op4) return 1;
        }
       return 0;
   }
    
    bool makesquare(vector<int>& m) {
        int n=m.size();
        int sum=accumulate(m.begin(), m.end(), 0);
        sort(m.begin(), m.end(), greater<int>());
        if(sum%4) return 0;
        int X=sum/4;
        return recurse(0, m, X, 0, 0, 0, 0);
        
        
    }
};