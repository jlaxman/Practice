class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size()!=t.size()) return 0;
        vector<int> vec(26, 0);
        for(int i=0; i<s.size(); i++){
            int d= (int)t[i]- (int)s[i];
            if(d<0){
                d+=26;
            }
            if(d!=0){
                if(vec[d]*26+d<=k){
                    vec[d]++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};