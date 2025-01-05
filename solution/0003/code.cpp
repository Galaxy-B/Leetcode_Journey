#include <string>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int maxlen = 0;
        
        // 当尾指针无法前进时 从窗口中逐出头指针指向的元素 直至尾指针可以继续探测
        for (int head = 0, tail = 0; head < s.size(); head++) {
            while (tail < s.size() && !window.contains(s[tail])) {
                window.emplace(s[tail++]);
            }

            // 内层循环退出时 [head,tail)为一个无重复字符的子串
            maxlen = max(maxlen, tail - head);
            window.erase(s[head]);                          
        }

        return maxlen;
    }
};
