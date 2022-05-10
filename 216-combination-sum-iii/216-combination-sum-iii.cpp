class Solution {
    
    
    void fun(int i, int k, int n, vector<int> temp, vector<vector<int> >& vec){
        if(i>9){
            if(temp.size()==k && n==0){
                vec.push_back(temp);
                return;
            }
            return ;
        }
        temp.push_back(i);
        fun(i+1, k, n-i, temp, vec);
        temp.pop_back();
        fun(i+1, k, n, temp, vec);
        return ;
        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > vec;
        vector<int> temp;
        
        fun(1, k, n, temp, vec);
        return vec;
        
    }
};