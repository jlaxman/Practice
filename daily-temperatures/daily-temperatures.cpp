class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int, int>> st;
        int i=0;
        vector<int> ans(t.size(), 0);
        while(i<t.size()){
            
           if(st.empty()){
           }else{
               
               if(st.top().first< t[i]){
                   int curr=t[i];
                   while(!st.empty() && st.top().first<curr){
                       int ind=st.top().second;
                       ans[ind]= i-ind;
                       st.pop();
                   }
               }
           }
            st.push({t[i], i});  
            i++;
        }
        return ans;
    }
};