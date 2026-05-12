class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool flag=false;
        map<int,int> m1;
        for(int i=0;i<nums.size();i++)
        {
            if(m1.find(nums[i])!=m1.end())
            {
                flag=true;
                m1.at(nums[i])=  m1.at(nums[i])+1;
            }
            m1.insert({nums[i],1});
        }
        if(flag)
        {
            return true;
        }
        else return false;
    }
};