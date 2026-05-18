class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),[](unsigned char c){return tolower(c);});
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            // s[i]=tolower(s[i]);
            // s[j]=tolower(s[j]);
            if(s[i]==' ' || !isalnum(s[i]) )
            {
                i++;
                continue;
            }
            else if( s[j]==' ' || !isalnum(s[j]))
            {
                j--;
                continue;
            }
            else if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else if(s[i]!=s[j])
            {
                return false;
            }
            
        }
        return true;
    }
};
