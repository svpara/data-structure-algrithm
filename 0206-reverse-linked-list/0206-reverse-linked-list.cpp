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
    /**
     * Reverses a singly linked list iteratively.
     * Uses a dummy node to simplify the reversal process.
     * 
     * @param head The head of the original linked list
     * @return The head of the reversed linked list
     */
    ListNode* reverseList(ListNode* head) {
        // Create a dummy node to act as the new list's predecessor
        ListNode* dummyNode = new ListNode();
      
        // Pointer to traverse the original list
        ListNode* currentNode = head;
      
        // Iterate through each node in the original list
        while (currentNode != nullptr) {
            // Store the next node before we break the link
            ListNode* nextNode = currentNode->next;
          
            // Insert current node at the beginning of the new list
            // Point current node to what dummy is pointing to
            currentNode->next = dummyNode->next;
            // Make dummy point to the current node
            dummyNode->next = currentNode;
          
            // Move to the next node in the original list
            currentNode = nextNode;
        }
      
        // Return the head of the reversed list (node after dummy)
        return dummyNode->next;
    }
};
