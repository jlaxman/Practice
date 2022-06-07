class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        map<int, string> mpp;
        mpp[3]="Fizz";
        mpp[5]="Buzz";
        for(int i=1; i<=n; i++){
            string temp;
            for(auto m: mpp){
                if(i%m.first==0){
                    temp+=m.second;
                }
            }
            if(temp==""){
                temp+=to_string(i);
            }
            
            
            ans.push_back(temp);
        }
        return ans;
        
    }
};