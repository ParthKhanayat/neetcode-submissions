class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l,r=0,1 #l-buy r-sell
        maxProfit=0
        
        while r < len(prices) :
            if prices[l]<prices[r] :
                profit=prices[r]-prices[l]
                maxProfit=max(profit,maxProfit)
            else :
                l=r #p[r]<p[l] : we got a lower price than our l(buy) then go to r, becuase we want to buy cheapest
            r+=1 #r will always be incremented no matter the condition
        return maxProfit
