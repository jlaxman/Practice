class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        // if(k>)
        string temp;
        int ans=0;
        vector<int> vec(pow(2, k), 0);
        for(int i=0; i<s.size(); i++){
            int curr=s[i]-'0';
            ans= (ans*2+curr);
            if(i>= k-1){
                vec[ans]++;
                ans &= ~(1<<k-1);
            }   
        }
        // for(int a: vec){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        int mini=*min_element(vec.begin(), vec.end());
        // cout<< mini;
        return mini;
        
    }
};