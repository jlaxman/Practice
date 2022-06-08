class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size()) return 0;
        s+=s;
        for(int i=0; i<s.size()/2; i++){
            if(s.substr(i, s.size()/2)==goal) return 1;
        }
        return 0;
        
    }
};