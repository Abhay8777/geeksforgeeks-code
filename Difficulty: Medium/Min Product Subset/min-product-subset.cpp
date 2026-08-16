class Solution {
public:
    int minProd(vector<int>& arr) {
        int negCount = 0;
        int zeroCount = 0;

        int maxNeg = INT_MIN;
        int minPos = INT_MAX;

        int product = 1;

        for (int x : arr) {
            if (x == 0) {
                zeroCount++;
                continue;
            }

            product *= x;

            if (x < 0) {
                negCount++;
                maxNeg = max(maxNeg, x);
            }
            else {
                minPos = min(minPos, x);
            }
        }

        // All elements are zero
        if (zeroCount == arr.size())
            return 0;

        // No negative numbers
        if (negCount == 0) {
            // If zero exists, 0 is smaller than any positive number
            if (zeroCount > 0)
                return 0;

            // All positive
            return minPos;
        }

        // Odd number of negatives -> product is negative
        if (negCount % 2 == 1)
            return product;

        // Even number of negatives -> remove largest negative
        return product / maxNeg;
    }
};