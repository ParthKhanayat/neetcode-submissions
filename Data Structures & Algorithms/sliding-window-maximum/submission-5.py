class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # we are storing indices in the deque
        # 1) The front of the queue always gives the maximum element
        # 2) The queue will always remain in a decreasing order
        # 3) If the incoming element is smaller than the immediate last one ,keep it in queue
        # 4) If the incoming element is larger than the immediate last one,remove all smaller
        # 5) Remove the front element if it gets out of the window

        output = []
        q = collections.deque()  # stores index
        l = r = 0

        while r < len(nums):
            # pop smaller values from queue (4)
            while ( q and nums[q[-1]] < nums[r] ):  # while q is not empty AND last element is less than this number
                q.pop()  # q[-1] is shortcut to check the last element(in Python)

            q.append(r)

            #remove left most value from window when it goes out of our current group(out of bounds)
            if l>q[0] :
                q.popleft()

            if(r+1) >= k : #k is window size and r is index, we need to see if the count element reached that size,to return maximum, to do that we +1 because at index 2 means we have seen 3 elements [0,1,2]
                output.append(nums[q[0]]) #leftmost is the max always
                l+=1 #left only incremented when our window is atleast size k
            r+=1 #right is incremented in each iteration

        return output
