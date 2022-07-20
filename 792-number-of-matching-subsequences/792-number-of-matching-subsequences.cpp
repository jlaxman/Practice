class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        
//         // ---------------O(n*26+ m*L)-----------
//           vector<int> curr(26, -1);
//           vector<vector<int>> next;
//           for(int i=s.size()-1; i>=0; i--){
//               next.push_back(curr);
//               curr[s[i]-'a']=i;
//           }
//           next.push_back(curr);
//           reverse(next.begin(), next.end());
//           int cnt=0;
//           for(auto w: words){
//               int i=-1;
//               int flag=0;
//               for(auto ch: w){
//                   if(next[i+1][ch-'a']==-1){
//                       flag=1;
//                       break;
//                   }else{
//                       i= next[i+1][ch-'a'];
//                   }
                   
//                }
//               if(flag==0){
//                   cnt++;
//               }
//             }
//         return cnt;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
// ---------------O(n+ m*L*logn)-----------
        vector<vector<int>> q(26, vector<int>());
        for(int i=0;i<s.size(); i++){
            q[s[i]-'a'].push_back(i);
        }
        int cnt=0;
        for(auto& w: words){
            int flag=0;
            int prev=-1;
            for(auto& ch: w){
                if(q[ch-'a'].size()==0){
                    flag=1;
                    break;
                }
                int ind=upper_bound(q[ch-'a'].begin(), q[ch-'a'].end(), prev)-q[ch-'a'].begin();
                if(ind==q[ch-'a'].size()){
                    flag=1;
                    break;
                }else{
                    prev=q[ch-'a'][ind];
                }
            }
            if(flag==0){
                cnt++;
            } 
        }
        return cnt;
        
    }
};