class Solution {
public:
    int divide(int dd, int di) {
        if(dd==INT_MIN && di==-1) return INT_MAX;
        int HALF_INT_MIN = -1073741824;
        int p=0;
        if(dd>0){
            dd=-dd;
            p++; 
        }
        if(di>0){
            di=-di;
            p++;
        }
        if(di<dd) return 0;
        int q=0;
        while(dd<=di){
           int cnt=-1;
           int v=di;
            while(v>=HALF_INT_MIN && dd<= v+ v){
                cnt+=cnt;
                v+=v;
            }
            dd-=v;
            q+=cnt;
            
        }
        if(p==1) return q;
        else return -q;
        
        
       
     } 
      
        
    
};