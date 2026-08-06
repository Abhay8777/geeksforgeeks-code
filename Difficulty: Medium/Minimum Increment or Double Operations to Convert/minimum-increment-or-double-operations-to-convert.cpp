class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        long long increments = 0;   
        int maxDoublings = 0;       // max number of doublings needed
        for (int num : arr) {
            int bitCount = 0;       // count of 1s in binary
            int highestBit = 0;     // position of highest set bit
            int temp = num;
            int pos = 0;
            while (temp > 0) {
                if (temp & 1) bitCount++;   
                temp >>= 1;                 
                pos++;
            }
        
            increments += bitCount;         
            maxDoublings = max(maxDoublings, pos - 1); 
        }
    
    return increments + maxDoublings;
    }
};