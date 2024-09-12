#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> avgs(n, -1); // Initialize result with -1
        if (k == 0) {
            // If k is 0, the k-radius average of each element is the element itself
            return nums;
        }
        
        if (2 * k + 1 > n) {
            // If the window size is larger than the array, return the result as all -1
            return avgs;
        }
        
        // Step 1: Create a prefix sum array
        std::vector<long long> prefix(n + 1, 0); // Use long long to avoid overflow
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        // Step 2: Calculate the k-radius average for each valid index
        for (int i = k; i < n - k; ++i) {
            // Subarray sum from index (i - k) to (i + k)
            long long subarray_sum = prefix[i + k + 1] - prefix[i - k];
            avgs[i] = subarray_sum / (2 * k + 1); // Integer division
        }
        
        return avgs;
    }
};

// Helper function to print the result
void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;
    
    // Example 1
    std::vector<int> nums1 = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k1 = 3;
    std::vector<int> result1 = sol.getAverages(nums1, k1);
    printVector(result1); // Expected output: [-1, -1, -1, 5, 4, 4, -1, -1, -1]

    // Example 2
    std::vector<int> nums2 = {100000};
    int k2 = 0;
    std::vector<int> result2 = sol.getAverages(nums2, k2);
    printVector(result2); // Expected output: [100000]

    // Example 3
    std::vector<int> nums3 = {8};
    int k3 = 100000;
    std::vector<int> result3 = sol.getAverages(nums3, k3);
    printVector(result3); // Expected output: [-1]

    return 0;
}

