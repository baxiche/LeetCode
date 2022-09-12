#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define all(x) (x).begin(), (x).end()

class Solution {
public:
    // O(NlogN)
    int minMoves2(vector<int>& nums) {
        sort(all(nums));
        int med = nums[(int)nums.size() / 2];
        int sum = 0;
        for (int x : nums){
            sum += abs((x - med));
        }
        return sum;
    }
    // O(N) average
    int minMoves22(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + (int)nums.size() / 2, nums.end());
        int sum = 0;
        int med = *(nums.begin() + (int)nums.size() / 2);
        for (int x : nums){
            sum += abs(x - med);
        }
        return sum;
    }

};

class Random{
public:
    inline void static shuffle(vector<int>& v, vector<int>& check){
        for (int i = 0; i < (int)v.size(); ++i){
            int j = rand() % ((int)v.size() - i + 1) + i;
            cout << j;
        }
    }
};

int main(){
    vector<int> v{1,0,0,0,0}, check(5,0);
    //for (int& x : v) cin >> x;
    Random::shuffle(v);
}