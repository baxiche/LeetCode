class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; ++i){
            pq.push(nums[i]);
        }
        for (int i = k; i < (int)nums.size(); ++i){
            pq.push(nums[i]);
            pq.pop();
        }
        return pq.top();
    }

    int findKthLargest1(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq(nums.begin(), nums.end());
        while (pq.size() > nums.size() - k + 1) 
            pq.pop();
        return pq.top();
    }

    
};