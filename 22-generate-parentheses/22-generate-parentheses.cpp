class Solution {
public:
    void fun(int i, int n, string& temp , vector<string>& ans, int o, int c, int cnt){
        if(i==2*n){
            ans.push_back(temp);
            return ;
        }
        if(cnt==0){
            temp+='(';
            fun(i+1, n, temp, ans, o-1, c, cnt+1);
            temp.pop_back();
        }else{
            if(o!=0){
                temp+='(';
                fun(i+1, n, temp, ans, o-1, c, cnt+1);
                temp.pop_back();
            }
            if(c!=0 && cnt>0){
                temp+=')';
                fun(i+1, n, temp, ans, o, c-1, cnt-1);
                temp.pop_back();
            }
        }
        
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        fun(0, n, temp, ans, n, n ,0);
        return ans;
        
    }
};