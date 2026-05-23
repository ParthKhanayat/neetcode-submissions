class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        int water=0;
        int i=0;
        int j=height.size()-1;
        int maxL=height[i];
        int maxR=height[j];
        
        while(i<j)
        {
            if(maxL<=maxR)
            {
                i++;
                maxL=max(maxL,height[i]);
                water+=maxL-height[i];

            }
            else
            {
                j--;
                maxR=max(maxR,height[j]);
                water+=maxR-height[j];
            }
        }
        return water;
    }
};
