class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size()+1);
        for(int n:nums)
        {
            count[n]++; //incrementing the frequencies in hashmap

        }
        for(auto const& [key,value]:count)
        {
            freq[value].push_back(key);
        }

        vector<int> res;
        for(int i=freq.size()-1;i>=0;i--) //freq.size() is +1 the last index of the vector
        {
            for(int n:freq[i])
            {
                // if(freq[i]==nullptr)
                // {
                //     continue;
                // }
                res.push_back(n);
                if(res.size()==k)
                {
                    return res;
                }
            }
        }

            return res; //for compiler warning
        
    }
};
