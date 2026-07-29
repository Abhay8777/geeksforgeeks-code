class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        sort(begin(arr),end(arr));
        int n = arr.size();
        int count  =0;
        for(int i = 1; i<n;i++){
            if(arr[i]==arr[i-1]+1) continue;
            else count++;
        }
        return count+1;
    }
};
