class Solution {
public:
    void maxHeapify(vector<int>& nums, int i, int heapSize) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < heapSize && nums[l] > nums[largest])
            largest = l;

        if (r < heapSize && nums[r] > nums[largest])
            largest = r;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest, heapSize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        //max heap build kro
        for (int i = (n - 2) / 2; i >= 0; i--) {
            maxHeapify(nums, i, n);
        }

        int heapSize = n;

        // k-1 times upr se element htao aur heap ko maintain krte rho
        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[heapSize - 1]);
            heapSize--;
            maxHeapify(nums, 0, heapSize);
        }

        return nums[0];
    }
};