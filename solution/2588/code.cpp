#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    long long beautifulSubarrays(vector<int>& nums) {
        // count记录遍历过程中每个异或值出现的次数 初始化时考虑空串
        std::unordered_map<int, int> count{{0, 1}};
        long long ans = 0;

        // 若nums[0,i)的异或为x 且nums[0,j)的异或为x 则nums[i,j)是美丽子数组
        for (int val = 0, i = 0; i < nums.size(); i++) {
            val ^= nums[i];
            ans += count[val]++;
        }

        return ans;
    }
};