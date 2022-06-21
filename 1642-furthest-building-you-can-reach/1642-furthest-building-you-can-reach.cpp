class Solution {
public:
    bool predicate(int mid, vector<int>& diff, int l, int b){
        priority_queue<int> pq(diff.begin(), diff.begin()+mid+1);
        while(!pq.empty()){
            int h=pq.top();
            if(l>0){
                pq.pop();
                l--;
            }else if(b>=h){
                b-=h;
                pq.pop();
            }else{
                break;
            }
        }
        return pq.empty();
        
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        if(n==1) return 0;
        vector<int> diff;
        for(int i=1; i<heights.size(); i++){
            diff.push_back(max(0, heights[i]-heights[i-1]));
        }
        int l=0;
        int r=n-2;
        int ans=0;
        int flag=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(predicate(mid, diff, ladders, bricks)){
                l=mid+1;
                flag=1;
                ans=max(mid, ans);
            }else{
                r=mid-1;
            }
            
        }
        if(ans==0){
            if(flag==1){
                return 1;
            }else{
                return 0;
            }
        }
        return (ans+1);
        
    }
};