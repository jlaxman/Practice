class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return 0;
        double num= log10(n);
        double den= log10(3);
        
        int p= (int) (num/den);
        // cout<<num<<" "<<den<<" " << p<<endl;
        int f=(pow(3, p)==n);
        int f1= (pow(3, p+1)==n);
        
        return f ||f1;
    }
};