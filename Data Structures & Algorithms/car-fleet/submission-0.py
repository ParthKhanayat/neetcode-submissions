class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair=[[p,s] for p,s in zip(position,speed)] #combining position array and speed array into a array of pairs using list comprehension
        stack=[]
        for p,s in sorted(pair)[::-1] : #reverse sorted order
            stack.append((target-p)/s) #appending the exact time each car reaches destination
            if len(stack)>=2 and stack[-1]<=stack[-2] : #if frontmost two cars become fleet(one car reaching before the car ahead)
                stack.pop() #popping the behind car
            #we are using if instead of while because we are doing it in reverse so other possibilities are already hadn;ed before we reached a car that is behind
        return len(stack)