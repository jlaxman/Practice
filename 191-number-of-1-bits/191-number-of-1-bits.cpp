class Solution {
public:
    int hammingWeight(uint32_t n) {
        long long ans=n;
        return __builtin_popcountll(ans);
    }
};