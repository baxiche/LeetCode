#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // sol1. 維護一個遞減的單調stack，只要出現破壞遞減的元素，就可以更新res
    vector<int> dailyTemperatures1(vector<int>& tmp){
        int n = tmp.size();
        vector<int> res(n);
        vector<int> st;
        for (int i = n - 1; i >= 0; i--){
            //相等的時候也要pop掉，因為要找的是大於當天的氣溫
            while (!st.empty() && tmp[st.back()] <= tmp[i]){
                st.pop_back();
            }
            res[i] = (st.empty())? 0 : i - st.back();
            st.push_back(i);
        }    
        return res;
    }

    // sol2. 維護一個遞減的單調stack，因為只要出現遞增，就可以更新res
    vector<int> dailyTemperatures(vector<int>& tmp){
        int n = tmp.size();
        vector<int> res(n, 0);
        vector<int> st;
        for (int i = 0; i < n; ++i){
            //相等的時候不能pop掉要留著，因為還沒找到大於當天的氣溫
            while (!st.empty() && tmp[st.back()] < tmp[i]){
                res[st.back()] = st.back() - i;
                st.pop_back();
            }
            st.push_back(i);
        }
        return res;
    }
};