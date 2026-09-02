class Solution {
  public:
    int solve(int n, string s) {
        bool seen[26] = {};
        bool hasComputer[26] = {};
        int occupied = 0;
        int ans = 0;
        for (char ch : s) {
            int id = ch - 'A';
            if (!seen[id]) {

                seen[id] = true;

                if (occupied < n) {
                    occupied++;
                    hasComputer[id] = true;
                }
                else {
                    ans++;
                }
            }
            else {
                if (hasComputer[id]) {
                    occupied--;
                    hasComputer[id] = false;
                }
            }
        }

        return ans;
    }
};
