#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int similarPairs(vector<string>& words) {
        // count记录遍历过程中每种相似字符串出现的次数
        std::unordered_map<int, int> count;
        int total = 0;

        // 将出现字母的序号对应的位置1来生成hash 相似字符串的hash相同
        for (const auto& word : words) {
            int hash = 0;
            for (const auto& letter : word) {
                hash |= 1 << (letter - 'a');
            }
            total += count[hash]++;
        }
        
        return total;
    }
};
