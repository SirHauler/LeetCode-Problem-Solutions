class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); 
        int n = matrix[0].size();
        
        int vhi = m - 1, vlo = 0;
        int vmid = vhi / 2;

        // going to search vertically first
        while (vlo <= vhi) {
            vector<int> midarr = matrix[vmid];
            int midlow = midarr[0], midhi = midarr[midarr.size() - 1]; 
            if (target > midhi) {
                vlo = vmid + 1;
                vmid = (vlo + vhi) / 2;
            } else if (target < midlow) {
                vhi = vmid - 1;
                vmid = (vlo + vhi) / 2;
            } else {
                return binarySearch(midarr, target);
            }
        }

        return false;
    }

    bool binarySearch(vector<int>& arr, int target) {
        // used when we know it has to be within one array
        int n = arr.size(); 
        int lo = 0, hi = n - 1;
        int mid = hi / 2;

        while (lo <= hi) {

            if (arr[mid] < target) {
                lo = mid + 1; 
                mid = (lo + hi) / 2; 
            } else if (arr[mid] > target) {
                hi = mid - 1; 
                mid = (lo + hi) / 2;
            } else {
                return true; // must be a match
            }
        }

        return false;
    }
};