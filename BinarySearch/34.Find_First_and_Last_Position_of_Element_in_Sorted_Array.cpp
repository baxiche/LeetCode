#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        if (nums.size() == 0) return vector<int> {-1, -1};

        vector<int> ans({-1, -1});
        ans[0] = findL(nums, 0, (int)nums.size(), tar);
        if (ans[0] == -1) 
            return ans;
        ans[1] = findR(nums, 0, (int)nums.size(), tar);
        return ans;
    }

    int findL(vector<int>& nums, int l, int r, int tar){
        if (l == r){
            if (l == nums.size()) 
                return -1;
            else {
                if (nums[l] == tar) return l;
                else return -1; 
            }
        }

        int m = l + (r - l) / 2;
        if (nums[m] == tar)
            return findL(nums, l, m, tar);
        else if (nums[m] < tar)
            return findL(nums, m + 1, r, tar);
        else 
            return findL(nums, l, m, tar);
    }

    int findR(vector<int>& nums, int l, int r, int tar){
        if (l == r){
            if (r - 1 < 0) return -1;
            else {
                if (nums[r - 1] == tar) return r - 1;
                else return -1;
            }
        }

        int m = l + (r - l) / 2;
        if (nums[m] == tar)
            return findR(nums, m + 1, r, tar);
        else if (nums[m] < tar)
            return findR(nums, m + 1, r, tar);
        else 
            return findR(nums, l, m, tar);
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size()) 
            return vector<int> {-1,-1};

        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (l == nums.size() || nums[l] != target) return vector<int> {-1, -1};
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return vector<int> {l, r - 1};
    }
};

int main(){
    Solution s;
    int n; cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    int t; cin >> t;
    vector<int> ans = s.searchRange(nums, t);
    cout << ans[0] << ' ' << ans[1];
}