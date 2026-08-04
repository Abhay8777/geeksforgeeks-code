class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(begin(arr),end(arr));
        int n =arr.size();
        int i = 0,j=0;
        int count = 0;
        while(j<n){
            while(i<j && abs(arr[j]-arr[i])>=k){
                i++;
            }
            count+=(j-i);
            j++;
        }
        return count;
    }
};