class Solution {
    
    int fun(int i, vector<char> & v, int n, string & temp){
        if(i>4){
            if(temp.size()==n) return 1;
            return 0;
        }
        if(temp.size()>n) return 0;
        int op1=0;
        int op2=0;
        temp+=v[i];
        op1=fun(i, v, n, temp);
        temp.pop_back();
        op2=fun(i+1, v, n, temp);
        return op1+op2;
    }
public:
    int countVowelStrings(int n) {
        vector<char> v={'a', 'e', 'i', 'o', 'u'};
        // v.push_back('a');
        // v.push_back('e');
        // v.push_back('i');
        // v.push_back('o');
        // v.push_back('u');
        string temp;
        return fun(0, v, n, temp);
        
    }
};