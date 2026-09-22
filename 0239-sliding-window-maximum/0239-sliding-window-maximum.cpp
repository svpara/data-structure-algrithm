class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Max heap to store pairs of (value, negative_index)
        // Using negative index to maintain insertion order for equal values
        priority_queue<pair<int, int>> maxHeap;
      
        int n = nums.size();
      
        // Initialize the heap with first k-1 elements
        for (int i = 0; i < k - 1; ++i) {
            maxHeap.push({nums[i], -i});
        }
      
        vector<int> result;
      
        // Process each window starting from index k-1
        for (int i = k - 1; i < n; ++i) {
            // Add current element to the heap
            maxHeap.push({nums[i], -i});
          
            // Remove elements that are outside the current window
            // The window spans from [i-k+1, i]
            while (-maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }
          
            // The maximum element in current window is at the top of heap
            result.emplace_back(maxHeap.top().first);
        }
      
        return result;
    }
};
