#include <vector>
#include <algorithm>

class Solution {
   public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;

        // Sort the array first, just like nums.sort() in Python
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate elements for the first position
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Two pointers: left and right
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int threeSum = nums[i] + nums[l] + nums[r];

                if (threeSum > 0) {
                    r -= 1;
                } else if (threeSum < 0) {
                    l += 1;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l += 1;

                    // Skip duplicate elements for the left pointer
                    while (nums[l] == nums[l - 1] && l < r) {
                        l += 1;
                    }
                }
            }
        }

        return res;
    }
};