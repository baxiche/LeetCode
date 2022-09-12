class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lo = 0, hi = 0;
        while (hi < nums.size()){
            if (nums[lo] != nums[hi]){
                ++lo;
                nums[lo] = nums[hi];
            }
            ++hi;
        }
        return lo + 1;
    }
};