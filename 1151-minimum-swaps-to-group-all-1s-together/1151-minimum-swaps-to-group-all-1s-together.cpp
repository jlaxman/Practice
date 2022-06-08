class Solution {
public:
    int minSwaps(vector<int>& data) {
        int sum= accumulate(data.begin(), data.end(), 0);
        if(sum==data.size() || sum==0) return 0;
        int cnt=0;
        int mxcnt=0;
        for(int i=0; i<data.size(); i++){
            cnt+=data[i];
            if(i>=sum-1){
                mxcnt= max(cnt, mxcnt);
                cnt-=data[i-sum+1];
            }
        }
        return sum-mxcnt;
        
    }
};