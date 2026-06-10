class MinStack:

    def __init__(self):
        self.stack=[] #use self to create and use a variable that can be accessed in the whole class

    def push(self, val: int) -> None:
        self.stack.append(val)

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return min(self.stack)
