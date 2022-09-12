#include <vector>
#include <string>
#include <deque>
#include <unordered_set>

using namespace std;

class Solution {
private:
    string spinUp(string str, int idx){
        str[idx] = (str[idx] == '9')? '0' : str[idx] + 1;
        return str; 
    }
    string spinDown(string str, int idx){
        str[idx] = (str[idx] == '0')? '9' : str[idx] - 1;
        return str;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis = {"0000"};
        deque<string> q;
        q.push_back("0000");
        int step = 0;
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; ++i){
                string cur = q.front(); q.pop_front();
                if (cur == target) return step;
                if (dead.count(cur)) continue;
                
                for (int j = 0; j < 4; ++j){
                    string s;
                    s = spinUp(cur, j);
                    if (!vis.count(s)) q.push_back(s);
                    s = spinDown(s, j);
                    if (!vis.count(cur, j)) q.push_back(s);
                }
            }
            ++step;
        }
        return -1;
    }
};

int main(){

}