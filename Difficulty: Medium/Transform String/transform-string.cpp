class Solution {
public:
    int transform(string &s1, string &s2) {
        int n = s1.size();

        // Different lengths -> impossible
        if (n != s2.size())
            return -1;

        // Check character frequencies
        vector<int> freq(256, 0);

        for (char c : s1)
            freq[c]++;

        for (char c : s2)
            freq[c]--;

        for (int x : freq) {
            if (x != 0)
                return -1;
        }

        // Match from the end
        int i = n - 1;
        int j = n - 1;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                j--;
            }

            i--;
        }

        // Characters not matched need to be moved
        return j + 1;
    }
};