class Solution {
    int binarySearch(vector<int> &arr, int lo, int hi, int x) {
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
int findPivot(vector<int> &arr, int lo, int hi) {
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
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
    int pivot = findPivot(nums, 0, n - 1);

    // If we found a pivot, then first compare with pivot
    // and then search in two subnumsays around pivot
    if (nums[pivot] == target)
        return pivot;
  
    // If the minimum element is present at index
    // 0, then the whole numsay is sorted
    if (pivot == 0)
        return binarySearch(nums, 0, n - 1, target);

    if (nums[0] <= target)
        return binarySearch(nums, 0, pivot - 1, target);
    return binarySearch(nums, pivot + 1, n - 1, target);

        
    }
};