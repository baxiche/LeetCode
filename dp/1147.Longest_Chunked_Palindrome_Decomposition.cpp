#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestDecomposition(string s) {
        return rec(s, 0, (int)s.size() - 1);
    }
    
    int rec(string s, int l, int r){
        if (l > r) return 0;

        int len = (r - l + 1) / 2;
        for (int i = 1; i <= len; ++i){
            if (s.substr(l, i) == s.substr(r - i + 1, i)){
                return 2 + rec(s, l + i, r - i);
            }
        }
        return 1;
    }
};

int main(){
    string s; cin >> s;
    Solution sol;
    cout << sol.longestDecomposition(s);
}