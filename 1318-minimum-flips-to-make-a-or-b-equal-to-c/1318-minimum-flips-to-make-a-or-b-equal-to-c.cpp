class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=31; i>=0; i--){
            int cth=(c & (1<< i));
            int ath= (a & ( 1<<i));
            int bth= (b & ( 1<<i));
            cout<<ath<<" "<<bth<<" "<<cth<<endl;
            cout<<cnt<<endl;
            if(cth>0){
                if(ath>0 || bth>0){
                    
                }else{
                    cnt++;
                }
            }else{
                if(ath>0){
                    cnt++;
                }
                if(bth>0){
                    cnt++;
                }
            }
            
        }
        return cnt;
        
    }
};