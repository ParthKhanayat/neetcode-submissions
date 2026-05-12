class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> m1;
        for(int num:nums)
        {
            if(m1.find(num)!=m1.end())
            {
                return true;
            }
            m1.insert(num);
        }
        return false;
    }
};