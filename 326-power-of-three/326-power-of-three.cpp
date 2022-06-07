class Solution {
public:
    bool isPowerOfThree(int n) {
        int c= pow(3, 19);
        return n>0 && !(c%n);
    }
};