class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        bool pal=true;
        while(i<j)
        {
            s[i]=tolower(s[i]);
            s[j]=tolower(s[j]);
            if(!isalnum(s[i])||s[i]==' ')
            {
                i++;
                continue; //so it doesn't go and copanre s[i] and s[j]
            }
            if(!isalnum(s[j])||s[j] ==' ')
            {
                j--;
                continue;
            }
            if(s[i]==s[j])
            {
                i++;
                j--;
                continue;
            }
            else
            {
                pal=false;
                break;
            }
        }
        return pal;
    }
};
