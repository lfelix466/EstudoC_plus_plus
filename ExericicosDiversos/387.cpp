#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> repeticoes;

        for (char c : s) {
            repeticoes[c]++;
        }

        for (int i = 0; i < (int)s.size(); i++) {
            if (repeticoes[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    string s = "aabbcdef";
    cout << sol.firstUniqChar(s) << endl;
}
