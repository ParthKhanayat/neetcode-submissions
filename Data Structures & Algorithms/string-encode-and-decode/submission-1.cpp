class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string s:strs)
        {
            res+=to_string(s.length())+"#"+s;

        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>res;
        string a="";
        int i=0;
        while(i<s.length())
        {
            int j=i;
           while(s[j]!='#')
           {
                j++;
           }
           int length=stoi(s.substr (i,j-i)); //extractes the length (i-->j)
           res.push_back(s.substr(j+1,length)); //extract the actual word and add to res

           //move the pointer i to the start of next chunk
           i=j+1+length; 
        }
        return res;
    }
};
