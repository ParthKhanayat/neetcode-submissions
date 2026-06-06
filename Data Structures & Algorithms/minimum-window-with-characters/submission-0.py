class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # edge case
        if t == "":
            return ""

        countT, window = {}, {}  # initialise two hashmaps
        for c in t:
            countT[c] = 1 + countT.get(c, 0)

        have, need = 0, len(countT)  # setting lengths, which will decide
        res, resLen = (
            [-1, -1],
            float("infinity"),
        )  # for saving indices and length of the result string
        l = 0  # left pointer
        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c, 0)  # update the window hashmap

            if c in countT and window[c] == countT[c]:
                have += 1  # increment have only if it is present in t(the chars we only care about) and the frequency exactlt matches

            while have == need:  # when it is valid, i.e have=need
                # update our result
                if (r - l + 1) < resLen:
                    resLen = r - l + 1
                    res = [l, r]
                # pop from the left of our window,because we want the smallest string
                window[s[l]] -= 1
                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    # if a valid character is reduced from the window and it is less than the frequency in t
                    # reduce the have
                    have -= 1
                l += 1  # move left pointer forward
        l, r = res  # unpack the res array
        return (
            s[l : r + 1] if resLen != float("infinity") else ""
        )  # while returning also checking whether the string is actually presnt, if not then the length remins infinty
