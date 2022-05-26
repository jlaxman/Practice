class Solution {

    
      

public:
    int maxEnvelopes(vector<vector<int>>& enve) {
        auto comp=[](auto& x, auto& y){
            return x[0]==y[0]? x[1]>y[1]: x[0]< y[0];
            
        };
        int n=enve.size();
       sort(enve.begin(), enve.end(), comp);
       vector<int> seq;
        for(int i=0; i<n; i++){
            int a=enve[i][1];
            
            int ind= lower_bound(seq.begin(), seq.end(), a)-seq.begin();
            if(ind==seq.size()){
                seq.push_back(a);
            }else{
                seq[ind]=a;
            }
            
        }
        return seq.size();
    }
        
    
};

