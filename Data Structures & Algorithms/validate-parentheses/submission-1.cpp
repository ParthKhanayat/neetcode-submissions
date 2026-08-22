class Solution {
   public:
    bool isValid(string s) {
        unordered_map<char,char> closeToOpen = {{']', '['}, {'}', '{'}, {')', '('}};
        stack<char> st;
        for (char c : s) {
            // If 'c' is a closing bracket (it is a key in the map)
            if (closeToOpen.count(c)) {
                 if (st.size() == 0) {
                    return false;
                }
                if (closeToOpen[c] == st.top()) {
                    st.pop();
                } else  // no match
                {
                    return false;
                }
                
            } else  // closing
            {
               st.push(c);
            }
        }

        return st.size() == 0;
    }
};
