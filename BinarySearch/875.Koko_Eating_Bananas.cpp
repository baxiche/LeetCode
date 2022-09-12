#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left < right){
            int mid = left + (right - left) / 2;
            int time = getTime(piles, mid);
            if (time <= h){
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    int getTime(vector<int>& piles, int speed){
        int time = 0;
        for (int pile : piles){
            time += pile / speed;
            if (pile % speed > 0) 
                ++time;
        }
        return time;
    }
};

int main(){
    int n, h;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; ++i) cin >> piles[i];
    cin >> h;

    Solution s;
    cout << s.minEatingSpeed(piles, h);
}