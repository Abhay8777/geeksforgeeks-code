class Solution {
public:
    long long countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int i = 0, j = 0;
        long long sum = 0, cnt = 0;
        while (j < n) {
            sum += arr[j];
            while (sum > x) {
                sum -= arr[i];
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
    long long countSubarray(vector<int>& arr, int l, int r) {
        return countLessEqual(arr, r) - countLessEqual(arr, l - 1);
    }
};