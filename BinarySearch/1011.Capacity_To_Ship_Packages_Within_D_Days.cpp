#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int left = *max_element(w.begin(), w.end());
        int right = accumulate(w.begin(), w.end(), 0);

        while (left < right){
            int m = left + (right - left) / 2;
            if (days == f(w, m))
                right = m;
            else if (days < f(w, m))
                left = m + 1;
            else 
                right = m;
        }
        return left;
    }

    int f(vector<int>& weights, int capa){
        int day = 1;
        int ship = 0;
        for (int weight : weights){
            if (ship + weight > capa){
                ++day;
                ship = 0;
            }
            ship += weight;
        }
        return day;
    }
};



int main(){
    vector<int> w({3,2,4,1,4});
    Solution s;
    cout << s.shipWithinDays(w, 3);
}