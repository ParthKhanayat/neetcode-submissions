class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        #binary search on row
        l=0
        r=len(matrix)-1
        
        while l<=r :
            m=(l+r)//2
            if matrix[m][0]<=target and matrix[m][-1]>=target:
                L,R=0,len(matrix[m])-1
                #binary search inside the choosen row
                while L<=R :
                    M=(L+R)//2
                    if matrix[m][M]==target :
                        return True
                    elif matrix[m][M] > target :
                        R=M-1
                    elif matrix[m][M] < target :
                        L=M+1
                return False
            elif matrix[m][0]>target :
                r=m-1
            elif matrix[m][-1]<target :
                l=m+1
        return False

