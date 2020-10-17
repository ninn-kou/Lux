// Hao Ren
// 18 October, 2020
// 876. Middle of the Linked List

/*
Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 */

// Fast and slow pointers to obtain the 1/2 route.
struct ListNode *middleNode(struct ListNode *head) {
    struct ListNode *fastPointer = head;
    struct ListNode *slowPointer = head;
    // Because the fast pointer moves to the next two nodes at once, so we need
    // to make sure both of these two nodes are not NULL.
    while (fastPointer->next != NULL && fastPointer->next->next != NULL) {
        fastPointer = fastPointer->next->next;
        slowPointer = slowPointer->next;
    }
    // Return the pointer by parity of the total number of elements.
    if (fastPointer->next != NULL) {
        return slowPointer->next;
    } else {
        return slowPointer;
    }
}
