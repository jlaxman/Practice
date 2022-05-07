class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> mini;
        int m=nums[0];
        mini.push_back(m);
        for(int i=1; i<nums.size(); i++ ){
            if(nums[i]<m){
                m=nums[i];
                mini.push_back(m);
            }else{
                mini.push_back(m);
            }
        }
        stack<int> st;
        for(int j=nums.size()-1; j>=1; j--){
            if(nums[j]==mini[j]) continue;
            else{
                if(st.empty()){
                    st.push(nums[j]);
                }else{
                    while(!st.empty() && st.top()<=mini[j]){
                        st.pop();
                    }
                    if(st.empty()){
                        st.push(nums[j]);
                    }else{
                        if(st.top()<nums[j]){
                            return 1;
                        }else{
                            st.push(nums[j]);
                        }
                    }
                }
            }
        }
        return 0;
        
        
        
        
        
        
    }
};