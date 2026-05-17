class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set1(nums.begin(),nums.end());
        int longest=0;
        for(int n:nums)
        {
           
            //check if it's the start of a sequence
            if(set1.find(n-1)==set1.end())
            {
                int length=0; //reset the length for this sequence(clear the previous checked sequence length)
                while(set1.find(n+length)!=set1.end())
                {
                    length++; //checks the length of current sequence
                    if(length>longest)
                    {
                        longest=length; //take the max(longest,length)
                    }

                }
            }
        }
        return longest;
    }
};
