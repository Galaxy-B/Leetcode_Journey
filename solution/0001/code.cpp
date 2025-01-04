#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val2idx;
        
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            // 记录出现过的元素 便于直接通过差值索引其下标
            if (val2idx.contains(diff)) {
                return {val2idx[diff], i};
            } else {
                val2idx.emplace(nums[i], i);
            }
        }

        return {0, 0};  // unreachable   
    }
};
