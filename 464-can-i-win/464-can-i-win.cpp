class Solution {
    private:
    int dp[1<<21];
    int t;

    int winPossible(int n, int T,int M){
        if(T>=t){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        
        for(int k=1; k<=M; k++){
            if((n & 1<<k) ==0){
                int f=n;
                f|= 1<<k;
                if(winPossible(f,  T+k, M)==0) return dp[n]=1;
            }
        }
        return dp[n]=0;
        
    }
    
public:
    bool canIWin(int mCI, int desiredTotal) {
        if((mCI*(mCI+1))/2< desiredTotal){
            return false;
        }
        if(desiredTotal<=0) return 1;
        this->t= desiredTotal;
        
        // int n=0;
        // int s= (mCI*(mCI+1))/2;
        memset(dp, -1, sizeof dp);
        
        // vector<vector<vector<int>>> dp(pow(2, mCI+1), vector<vector<int>>(s+1, vector<int>(2, -1)));
        return winPossible(0, 0, mCI);
        
    }
};