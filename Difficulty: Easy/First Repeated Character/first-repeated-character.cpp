class Solution {
  public:
    string firstRepChar(string s) {
        int n = s.length();
        vector<char>freq(26,0);
        for(char ch: s){
            freq[ch-'a']++;
            if(freq[ch-'a']==2){
                return string(1,ch);
                break;
            }
        }
        return "-1";
    }
};