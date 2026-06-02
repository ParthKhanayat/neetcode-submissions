class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //edge case of empty string
        if(s=="")
        {
            return 0;
        }
        unordered_set<char> seen;
        int currLen=1;
        int maxLen=1;
        int l=0; //left pointer
        for(int r=0 /*right pointer*/;r<s.size();r++)
        {
            while(seen.find(s[r])!=seen.end()) //WHILE char is duplicate
            {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            currLen=r-l+1;
            maxLen=max(maxLen,currLen);
        }
        return maxLen;
    }
    
};
