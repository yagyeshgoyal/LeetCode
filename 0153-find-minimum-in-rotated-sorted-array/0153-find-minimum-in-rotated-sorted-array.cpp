class Solution {
    int findpivot( int lo, int hi, vector<int>&arr) {
    while (lo < hi) {
      
        if (arr[lo] <= arr[hi])        
            return lo;
        
        int mid = (lo + hi) / 2;

        if (arr[mid] > arr[hi])
            lo = mid + 1;

        else
            hi = mid;
    }

    return lo;
}
public:
    int findMin(vector<int>& nums) {
        int pivot_index = findpivot(0,nums.size()-1,nums);
        return nums[pivot_index];
    }
};