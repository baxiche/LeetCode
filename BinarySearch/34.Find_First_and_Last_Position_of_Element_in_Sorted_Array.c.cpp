#include <iostream>
#include <vector>
using namespace std;

class Solution {
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

int main(){
    Solution s;
    vector<int> n({2,2});
    vector<int> t = s.searchRange(n, 3);
    cout << t[0] << ' ' << t[1];
}