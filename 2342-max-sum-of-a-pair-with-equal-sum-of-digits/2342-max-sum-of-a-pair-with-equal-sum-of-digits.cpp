class Solution {
public:
    // void print(vector<int> vec){
    //     for(auto k: vec){
    //         cout<< k<< " ";
    //     }
    //     cout<<endl;
    //     return ;
    // }
    int maximumSum(vector<int>& nums) {
     
        // unordered_map<int, pair<int,int> > mpp;
        // vector<pair<int, int> >vec;
        unordered_map<int, int> mpp;
        int ans=-1;
        for(auto k: nums){
            string s=to_string(k);
            int sum=0;
            for(auto ch: s){
                sum+= (ch-'0');
            }
            // vec.push_back({sum, k});
//             if(mpp.find(sum)!=mpp.end()){
//                 if(k>=mpp[sum].first){
//                     mpp[sum].second=mpp[sum].first;
//                     mpp[sum].first=k;
//                 }else{
//                     if(k>mpp[sum].second){
//                         mpp[sum].second=k;
//                     }
//                 }
                
//             }else{
//                 mpp[sum].first=k;
//                 mpp[sum].second=-1;
                
//             }
            
            if(mpp.find(sum)!=mpp.end()){
                ans=max(mpp[sum]+k, ans);
            }else mpp[sum]=k;
            
            if(mpp[sum]<k){
                mpp[sum]=k;
            }
            
           
        }
//           int ans=-1;
//         for(auto m: mpp){
//             // cout<< m.first<<endl;
//             auto st= m.second;
            
//             // sort(st.begin(), st.end());
//             // print(st);
            
//             if(st.second!=-1){
//                 ans= max(st.first+st.second, ans);
//             }
            
//         }
        // cout<<endl;
        // auto comp=[](auto& x, auto& y){
        //     return x.first==y.first? x.second> y.second: x.first< y.first;
        // };
        // sort(vec.begin(), vec.end(), comp);
        // for(int i=0; i<vec.size(); i++){
        //     int s= vec[i].first;
        //     if(i!=vec.size()-1){
        //         if(vec[i+1].first==s){
        //             ans= max(vec[i].second+ vec[i+1].second, ans);
        //             while(i<vec.size() && vec[i].first==s){
        //                 i++;
        //             }
        //             i--;
        //         }
        //     }
        // }
        return ans;
        
    }
};