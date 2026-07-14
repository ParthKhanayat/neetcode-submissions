class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int n: nums)
        {
            if (hashset.contains(n)) return true;
            else hashset.insert(n);

        }
        return false;
    }
};