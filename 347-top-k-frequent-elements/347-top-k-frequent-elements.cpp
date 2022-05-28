class Solution {
public:
    int partition(vector<pair<int, int>>& pq, int l, int r){
        int pivot= r;
        int j=l;
        for(int i=l; i<r; i++){
            if(pq[i].first<pq[r].first){
                swap(pq[i], pq[j]);
                j++;
            }
        }
        swap(pq[r], pq[j]);
        return j;
    }
    int quick_select(vector<pair<int, int>> & pq, int l, int r, int k){
        if(l<=r){
            int j= partition(pq, l, r);
            if(j==pq.size()-k) return j;
            else if(j>pq.size()-k ){
                return quick_select(pq, l, j-1, k);
            }else{
                return quick_select(pq, j+1, r, k);
            }
        }
        return -1;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==nums.size()) return nums;
        unordered_map<int,int> mpp;
        for(auto a: nums){
            mpp[a]++;
        }
        
        // priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<pair<int, int>> pq;
        for(auto a: mpp){
            pq.push_back(make_pair(a.second, a.first));
        }
        
       int j=quick_select(pq, 0, pq.size()-1, k);
        int n=pq.size();
        vector<int> ans;
        for(int i=j; i<n; i++){
            ans.push_back(pq[i].second);
        }
        // while(pq.size()>0) {
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        
        
        return ans;
        
    }
};