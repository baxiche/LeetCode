class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        vector<pair<int,int>> v(nums.size());
        for (int i = 0; i < nums.size(); ++i){
            v[i].first = nums[i];
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi){
            if (v[lo].first + v[hi].first > tar){
                --hi;
            }
            else if (v[lo].first + v[hi].first < tar){
                ++lo;
            }
            else 
                return vector<int>({v[lo].second, v[hi].second});
        }
        return vector<int>({-1,-1});
    }
};