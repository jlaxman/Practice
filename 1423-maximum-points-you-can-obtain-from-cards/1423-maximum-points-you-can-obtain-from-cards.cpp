class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sz= cardPoints.size()-k;
        int s1=accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(sz==0){
            return s1;
        }
        
        
        int sum=0;
        int mnsum=INT_MAX;
        for(int i=0; i<cardPoints.size(); i++){
            sum+=cardPoints[i];
            if(i>=sz-1){
                mnsum=min(sum, mnsum);
                sum-=cardPoints[i-sz+1];
            }
        }
        return (s1-mnsum);
    }
};