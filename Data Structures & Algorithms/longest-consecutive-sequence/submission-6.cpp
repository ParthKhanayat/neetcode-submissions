class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set1(nums.begin(),nums.end());
        {
            int longest=0;
            for(int n:set1)
            {
                if(set1.find(n-1)==set1.end())
                {
                    int length=1;
                    while(set1.find(n+1)!=set1.end())
                    {
                        length++;
                        n++;
                    }
                    if(length>longest)
                    {
                        longest=length;
                    }
                }
            }
            return longest;
        }
    }
};