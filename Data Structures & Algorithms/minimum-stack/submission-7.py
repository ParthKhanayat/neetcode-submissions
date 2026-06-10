class MinStack:
    def __init__(self):
        self.stack = []  # use self to create and use a variable that can be accessed in the whole class
        self.mini = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if self.mini:
            currMin = min(self.mini[-1], val)
        else:
            currMin = val
        self.mini.append(currMin)

    def pop(self) -> None:
        self.stack.pop()
        self.mini.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        # return min(self.stack)  this is O(N) time
        return self.mini[-1]
