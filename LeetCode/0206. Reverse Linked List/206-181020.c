// Hao Ren
// 18 October, 2020
// 206. Reverse Linked List

/*
Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
*/

// Use 3 pointers to update the linked list.
// Refer to the diagram.
struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *succ = NULL;
    while (curr != NULL) {
        succ = curr->next;
        curr->next = prev;
        prev = curr;
        curr = succ;
    }
    // Now the pointer `prev` is the new head.
    return prev;
}
