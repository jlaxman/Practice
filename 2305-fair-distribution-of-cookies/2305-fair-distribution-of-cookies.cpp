class Solution {

public:
    int mini;
    void dCookies(int i, vector<int>& cookies, vector<int>& bag, int k){
        if(i==cookies.size()){
            mini= min(*max_element(bag.begin(), bag.end()), mini);
            return ;
        }
        for(int j=0; j<k; j++){
            bag[j]+=cookies[i];
            dCookies(i+1, cookies, bag, k);
            bag[j]-=cookies[i];
        }
        return ;
        
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        mini=INT_MAX;
        vector<int> bag(k, 0);
        dCookies(0, cookies, bag, k);
        return mini;
        
    }
        
};