class Solution {
public:
    bool check(unordered_map<char, int> a){
        for(auto v: a){
            if(v.second>1) return false;
        }
        return true;
    }
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        cout<<n;
        if(n==0) return 0;
        unordered_map<char, int> alpha;
        int ans=0;
        int j=0;
        for(int i=0; i<n; i++){
            alpha[s[i]-'a']++;
            while(check(alpha)==false && j<n){
                alpha[s[j]-'a']--;
                j++;
            }
            ans= max(ans, i-j+1);
        }
        return ans;
        
    }
};