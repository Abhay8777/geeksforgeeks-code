class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_set<char> st;
        int n = s.length();
        int i = 0, j = 0;
        int count = 0;
        while(j<n){
            if(!st.count(s[j])){
                st.insert(s[j]);
                count = max(count,j-i+1);
                j++;
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return count;
    }
};
