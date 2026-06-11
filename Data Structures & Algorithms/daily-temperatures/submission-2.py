class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []  # monotonic stack containing indexes in decresing order of temperatures
        temp = temperatures
        res = [0] * len(temp)
        for i in range(len(temp)):
            while stack and temp[stack[-1]] < temp[i]:
                res[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        return res
