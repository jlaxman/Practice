class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=accumulate(arr.begin(), arr.end(), 0);
        if(sum%3) return 0;
        int x=sum/3;
        int ls=0;
        int ifound=-1;
        int jfound=-1;
        for(int i=0; i<arr.size(); i++){
            ls+=arr[i];
            if(ls==x && ifound==-1){
                ifound=i;
            }
            else if(ls==2*x && ifound!=-1){
                jfound=i;
                break;
            }
        }
        if(jfound==-1 || jfound==arr.size()-1) return 0;
        else return 1; 
        
    }
};