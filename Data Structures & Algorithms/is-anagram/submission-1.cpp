class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        int n=s.length();
        int m=t.length();
        if(n!=m)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            c1[s[i]-'a']++;
            c2[t[i]-'a']++;
        }
        if(c1==c2)
        {
            return true;
        }
        return false;
    }
};
