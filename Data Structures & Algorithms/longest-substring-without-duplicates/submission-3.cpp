class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //edge case
        if(s=="")
        {
            return 0;
        }
        unordered_set<char> seen;
        int maxLen=1;
        int i=0;
        int j=1;
        int currLen=1;
        seen.insert(s[i]);
        while(j<s.size())
        {
            if(seen.find(s[j])==seen.end())
            {
                currLen=j-i+1;
                seen.insert(s[j]);
                j++;
                maxLen=max(maxLen,currLen);
            }
            else if(seen.find(s[j])!=seen.end())
            {
                seen.erase(s[i]);
                currLen=1;
                i++;
            }
        }
        return maxLen;
    }
};
