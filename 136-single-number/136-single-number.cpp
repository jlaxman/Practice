class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto comp=[](auto& x, auto& y){
            return x^y;
        };
        return accumulate(nums.begin(), nums.end(), 0, comp);
    }
};