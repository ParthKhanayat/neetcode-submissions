class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 1;
        // edge cases:
         if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        // this ques says, any sequence can be there, like the elements of the array can be arranged
        // any how,it should be sonseuctive statement
        unordered_set<int> dist(nums.begin(), nums.end());  // set containing distinct
        for (int n : nums) {
            // check if this is start of a new sequence
            if (dist.find(n - 1) == dist.end()) {
                int currLen = 1;  // a single number byitself is already a subsequence of len 1.
                while (dist.find(n + 1) != dist.end()) {
                    currLen++;
                    maxLen = max(currLen, maxLen);
                    n++;
                }
            }
        }
        return maxLen;
    }
};
