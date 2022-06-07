class Solution {
public:
    bool isHappy(int n) {
        int prev=0;
        int cnt=0;
        while(n!=prev){
            cnt++;
            prev=n;
            string s=to_string(n);
            int ans=0;
            for(int i=0; i<s.size(); i++){
                ans+=(s[i]-'0')*(s[i]-'0');
            }
            n=ans;
            if(cnt> 1e4) break;
        }
        return prev==1;
        
    }
};