class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //we will do binary search 2 times
        //first we will binary search and find the row in whiich target is present
        //then we will binary search in that row to find the target
        int rows=matrix.size(), cols=matrix[0].size();
        //binary search row
        int top=0, bottom=rows-1;
        while(top<=bottom)
        {
            int row=(top+bottom)/2;
            if(target>matrix[row][cols-1])
            {
                top=row+1;
            }
            else if(target<matrix[row][0])
            {
                bottom=row-1;
            }
            else //we found the row
            {
                break;
            }
        }
        //there might be a case where we don't find the row,so loop terminates with the condition top>bottom
        if(top>bottom) return false;
        //binary search within row
        int row=(top+bottom)/2;
        int l=0, r=cols-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(target>matrix[row][m])
            {
                l=m+1;
            }
            else if(target<matrix[row][m])
            {
                r=m-1;
            }
            else
            {
                return true; //we found the target
            }

        }
        return false; //we did not found the target
    }
};
