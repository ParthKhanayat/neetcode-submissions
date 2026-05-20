class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int> res(2,0);
        while(i<j)
        {
            int currentSum=numbers[i]+numbers[j];
            if(currentSum<target)
            {
                i++;
            }
            else if(currentSum>target)
            {
                j--;
            }
            else if(currentSum==target)
            {
                res[0]=i+1;
                res[1]=j+1;
                break;
            }
        }
        return res;
    }
};
