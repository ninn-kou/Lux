// Hao Ren
// 18 October, 2020
// 237. Delete Node in a Linked List

/*
Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
*/

// Replace the next node with next->next one, and then free the required node.
void deleteNode(struct ListNode* node) {
    struct ListNode* delete_node = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    free(delete_node);
}
