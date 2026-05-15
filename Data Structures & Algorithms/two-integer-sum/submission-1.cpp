class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,0);
        unordered_map<int,int> prevValue;
        for(int i=0;i<nums.size();i++)
        {
            int diff=target-nums[i];
            if(prevValue.find(diff)!=prevValue.end())
            {
                res[0]=prevValue.at(diff);
                res[1]=i;
                return res;
            }
            prevValue.insert({nums[i],i});
        }
        return res;
    }
};
