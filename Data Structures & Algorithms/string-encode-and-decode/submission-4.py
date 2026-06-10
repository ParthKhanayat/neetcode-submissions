class Solution:

    def encode(self, strs: List[str]) -> str:
        res=""
        for s in strs :
            res+=str(len(s))+"#"+s
        return res

    def decode(self, s: str) -> List[str]:
        res=[]
        i=j=0
        length=0
        string=""
        while i< len(s) :
            j=i
            while s[j]!='#':
                j+=1
            
            length=int(s[i:j])
            string=s[j+1:j+length+1] # j='#' so start just after j until j+length
            res.append(string)
            i=j+1+length
            
        return res
