#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        qsort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
    
    void qsort(vector<int>& nums, int l, int r){
        if (l >= r) return;
        int p = partition(nums, l, r);
        qsort(nums, l, p - 1);
        qsort(nums, p + 1, r);
    }
    
    int partition(vector<int>& nums, int l, int r){
        int p = rand() % (r - l + 1) + l;
        
    }
};