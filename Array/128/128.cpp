#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> h;
        for (int& x : nums) h.insert(x);

    }
};

int main(){
    unordered_set<int> h;
    cout << h.bucket_size();
}