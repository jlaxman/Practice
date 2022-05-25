// class Solution {
// // public:
// //     int fun(int i, vector<int>& dp, vector<vector<int>>& enve, int n ){
       
// //         if(dp[i]!=-1) return dp[i];
// //         int h= enve[i][1];
// //         int ind=upper_bound(enve.begin()+i, enve.end(), {0, h})-enve.begin();
// //         for(int k=ind; k<n; k++){
// //             if
// //         }
      
        
    
      
// //     }
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
// //         auto comp=[](auto& x, auto& y){
// //             return x[0]==y[0]? x[1]>y[1]: x[0]< y[0];
            
// //         };
// //        sort(enve.begin(), enve.end(), comp);
// //        int n= enve.size();
// //         vector<int> dp(n, -1);
// //         int ans=0;
// //         for(int i=0; i<n; i++){
// //             ans= max(fun(i, dp, enve, n), ans);
// //         }
// //         return ans;
        
//     int size = envelopes.size();
// 	if(!size) return 0;
// 	sort(envelopes.begin(), envelopes.end());
// 	vector<int> maxrolls(size, 0); int maxroll = 1;
// 	maxrolls[0] = 1;
// 	for(int i = 1; i < size; ++i)
// 	{
// 		maxrolls[i] = 1;
// 		for(int j = i-1; j >= 0; --j)
// 			if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1])
// 				maxrolls[i] = max(maxrolls[i], maxrolls[j]+1);
// 		maxroll = max(maxroll, maxrolls[i]);
// 	}
// 	return maxroll;
//     }
// };

class Solution {
public:
    static bool compare(vector<int>&a , vector<int>& b)
    {
      return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>&a) {
      sort(a.begin(),a.end(),compare);
      vector<int>dp;
      for(auto i:a)
      {
        auto it=lower_bound(dp.begin(),dp.end(),i[1]);
        if(it==dp.end())
          dp.push_back(i[1]);
        else
          *it=i[1];
      }
      return dp.size();
    }
};