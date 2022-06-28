class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(auto ch: s){
            freq[ch-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans=0;
        int maxi=freq[0];
        for(int i=0; i<26; i++){
            if(freq[i]==0) continue;
            
            if(maxi==0){
                ans+=freq[i];
                continue;
            }
            if(freq[i]<=maxi){
                maxi=freq[i];
                maxi--;
            }else{
                ans+=(freq[i]-maxi);
                maxi--;
            }
            
        }
        return ans;
        
       
       
        
    }
};