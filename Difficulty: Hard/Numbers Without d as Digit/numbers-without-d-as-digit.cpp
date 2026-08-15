class Solution {
public:
    int countWithout(int n, int d) {
        if (n == 0) return 0;

        string s = to_string(n);
        int len = s.size();

        long long ans = 0;

        // Numbers having fewer digits
        for (int digits = 1; digits < len; digits++) {
            if (d == 0) {
                // First digit: 1-9
                // Remaining digits: 1-9 (0 is forbidden)
                ans += 9LL * pow(9, digits - 1);
            } 
            else {
                // First digit: 1-9 except d => 8 choices
                // Remaining digits: 0-9 except d => 9 choices
                ans += 8LL * pow(9, digits - 1);
            }
        }

        // Numbers having same number of digits as n
        for (int i = 0; i < len; i++) {
            int cur = s[i] - '0';

            if (d == 0) {
                if (i == 0) {
                    // First digit can be 1 to cur-1
                    ans += cur - 1;

                    if (cur == 0)
                        return ans;

                    if (cur == d)
                        return ans;
                } 
                else {
                    // Digits smaller than cur, excluding 0
                    if (cur == 0)
                        return ans;

                    ans += cur - 1;

                    if (cur == d)
                        return ans;
                }
            } 
            else {
                if (i == 0) {
                    // First digit cannot be 0
                    int smaller = cur - 1;

                    if (d < cur)
                        smaller--;

                    ans += smaller * pow(9, len - i - 1);
                } 
                else {
                    // Other digits can include 0
                    int smaller = cur;

                    if (d < cur)
                        smaller--;

                    ans += smaller * pow(9, len - i - 1);
                }

                if (cur == d)
                    return ans;
            }
        }

        // n itself does not contain d
        return ans + 1;
    }
};