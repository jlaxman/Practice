class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m=b.size();
        int n=a.size();
        int k= 5+ (m/n);
        string s;
        for(int i=0; i<k; i++){
            s+=a;
        }
        cout<<s<<endl;
        int i;
        for(i=0; i<n; i++){
            if(s.substr(i, m)==b){
               break; 
            }
        }
        if(i==n) return -1;
        else{
            return ((i+m+n-1)/n);
        }
        
    }
};