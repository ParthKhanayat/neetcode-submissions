class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>res; //key is char count array and value is list of anagrams
        for(string s: strs)
        {
            vector<int> count(26,0);
            
            for(char c: s)
            {
                count[c-'a']++;
            }
            // Push the current string into the list associated with this character count
            res[count].push_back(s);
        }

        vector<vector<string>> result;
        for(auto const& [key,val]:res)
        {
            result.push_back(val);
        }
        return result;
    }
};
