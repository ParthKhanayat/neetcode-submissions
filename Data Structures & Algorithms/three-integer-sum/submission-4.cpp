class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end()); //sorting the array to make this logic work
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            vector<int> res;
            if(i>0 && nums[i-1]==nums[i])
            {
                continue;
            }
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else if(sum==0)
                {
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[k]);
                    result.push_back(res);
                    res.clear();
                    //increment
                    j++;
                    k--;
                    //skip duplicates for j and k also
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }

        }
        return result;
    }
    
};
