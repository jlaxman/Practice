class Solution {
    
bool predicate(int mid, vector<int>& add, int a){
    int ans=0;
    for(int i=0; i<add.size(); i++){
        if(a>=add[i]){
            a-=add[i];
            ans++;
        }else{
            break;
        }
        
    }
    return ans>=mid;
    
}
public:
    int maximumBags(vector<int>& cp, vector<int>& r, int a) {
        
        int right= cp.size();
        int left=0;
        vector<int> add;
        int k=0;
        for(auto nbr: cp){
            add.push_back(nbr-r[k]);
            k++;
        }
        sort(add.begin(), add.end());
        int ans=0;
//         while(left<=right){
//             int mid= left+ (right-left)/2;
            
//             if(predicate(mid, add, a)){
//                 left= mid+1;
//                 ans= max(ans, mid);
//             }else{
//                 right= mid-1;
//             }
//         }
//         return ans;
        for(int i=0; i<add.size(); i++){
            if(a>=add[i]){
                a-=add[i];
                ans++;
            }else{
                break;
            }
        }
        return ans;

        
    
        
    }
};