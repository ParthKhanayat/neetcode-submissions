class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int area=0;
        while(i<j)
        {
            int b=min(heights[i],heights[j]);
            int l=j-i;
            int curArea=l*b;
            area=max(curArea,area);
            //we should not move the taller line inward, moving the smaller line inward gives the possibility of a taller line in next index, we should lock in the taller line because smaller line is the bottleneck
            if(heights[i]==min(heights[i],heights[j]))
            {
                i++;
            }
            else 
            {
                j--;
            }
        }
        return area;
    }
};
