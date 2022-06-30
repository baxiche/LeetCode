#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;

#define all(x) x.begin(), x.end()

class Solution {
public:
    static bool cmp(const string& s, const string& t){
        for (int i = 0; i < (int)min(s.size(), t.size()); ++i){
            if (s[(int)s.size() - i - 1] != t[(int)t.size() - i - 1]) 
                return s[(int)s.size() - i - 1] < t[(int)t.size() - i - 1];
        }
        return s.size() < t.size();
    }

    bool isSuffix(const string& s, const string& t){
        if (s.size() > t.size()) 
            return false;

        for (int i = 0; i < (int)min(s.size(), t.size()); ++i){
            if (t[(int)t.size() - i - 1] != s[(int)s.size() - i - 1])
                return false;
        }
        return true;
    }

    int minimumLengthEncoding(vector<string>& words) {
        sort(all(words), cmp);
        int sum = 0;
        for (int i = 0; i < (int)words.size() - 1; ++i){
            if (!isSuffix(words[i], words[i + 1]))
                sum += words[i].size() + 1;
        }
        sum += words[(int)words.size() - 1].size() + 1;
        return sum;
    }

    #define all(x) x.begin(), x.end()
    int minimumLengthEncoding1(vector<string>& words) {
        for (int i = 0; i < (int)words.size(); ++i)
            reverse(all(words[i]));
        sort(all(words));
        int res = 0;
        for (int i = 0; i < (int)words.size() - 1; ++i){
            res += (words[i] == words[i+1].substr(0, words[i].size()))? 0 : words[i].size() + 1;
        }
        return res + words[(int)words.size() - 1].size() + 1;   
    }
};

int main(){
    vector<string> w;
    w.push_back("time");
    w.push_back("lime");
    w.push_back("hell");
    w.push_back("sometime");
    w.push_back("me");
    Solution s;
    s.minimumLengthEncoding(w);
    string suf;
    for (int i = 0; i < w.size(); ++i){
        suf.push_back(w[i][(int)w[i].size() - 1]);
    }
    char c = suf[0];
    string::iterator i = upper_bound(suf.begin(), suf.end(), 'l');
    assert(i == suf.end());

    string ss("s");
    int ii = upper_bound(ss.begin(), ss.end(), 's') - ss.begin() - 1;
    assert(ii == 0);
}