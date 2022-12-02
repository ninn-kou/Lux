// Hao Ren
// 3 December, 2022
// 61. Rotate List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (head == NULL) return NULL;

    int length = 0;
    struct ListNode *curr = head;
    struct ListNode *last = curr;
    while (curr != NULL) {
        length++;
        last = curr;
        curr = curr->next;
    }

    curr = head;
    for (int i = 0; i < length - (k % length) - 1; i++) {
        curr = curr->next;
    }

    last->next = head;

    struct ListNode *pt = curr->next;
    curr->next = NULL;
    return pt;
}
