/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Define custom comparator for min-heap (priority queue)
        // Returns true if a's value is greater than b's value (for min-heap behavior)
        auto compare = [](ListNode* a, ListNode* b) { 
            return a->val > b->val; 
        };
      
        // Create a min-heap to store list nodes
        // The node with smallest value will be at the top
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
      
        // Add the head of each non-empty list to the min-heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }
      
        // Create a dummy head to simplify list construction
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
      
        // Process nodes from the min-heap until it's empty
        while (!minHeap.empty()) {
            // Extract the node with minimum value
            ListNode* minNode = minHeap.top();
            minHeap.pop();
          
            // If this node has a next node, add it to the heap
            if (minNode->next != nullptr) {
                minHeap.push(minNode->next);
            }
          
            // Append the minimum node to the result list
            current->next = minNode;
            current = current->next;
        }
      
        // Return the merged list (skip dummy head)
        return dummyHead->next;
    }
};
