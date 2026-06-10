class Solution:
    def isValid(self, s: str) -> bool:
        closeToOpen = {")": "(", "]": "[", "}": "{"}
        stack = []
        for c in s:
            if c in closeToOpen : #if we receive closing bracket
                if stack and stack[-1]==closeToOpen[c] : #stack is non empty and top element is the correct opening bracket of c
                    stack.pop()
                else:
                    return False
            else: #if we receive opening bracket
                stack.append(c)

        if not stack : return True
        else: return False