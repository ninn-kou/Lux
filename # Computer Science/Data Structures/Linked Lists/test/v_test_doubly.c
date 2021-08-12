#include <stdio.h>
#include <stdlib.h>
#include "../doubly_linked_list.c"

/**
 * @Test
 *
 * To run tests, execute following commands:
 *   $ clang v_test_doubly.c -o v_test_doubly
 *   $ ./v_test_doubly
 * and expected outputs would be showed below each testing part.
 *
 * NOTE: The tester needs to make sure each node would be inserted, and once ONLY.
 */
void testVisually_DoublyLinkedList() {
    DoublyList *doubly =  createDoublyList();
    ListNode *one = createNode(1);
    ListNode *five = createNode(5);
    ListNode *ten = createNode(10);
    ListNode *twenty = createNode(20);
    ListNode *thirty = createNode(30);
    ListNode *fifty = createNode(50);

    // Error Case: The linked list is empty.
    //
    // Expected Output:
    //     Size: 0
    //     printDoublyListForwards(): DNE ERROR
    //     printDoublyListBackwards(): DNE ERROR

    printf("Size: %d\n", size(doubly));
    printDoublyListForwards(doubly);
    printDoublyListBackwards(doubly);
    printf("\n");

    // Testing: insertNodeHead();
    // Normal Case
    //
    // Expected Output:
    //     Size: 1
    //     NULL <-> 5 <-> NULL
    //     NULL <-> 5 <-> NULL

    insertNodeHead(doubly, five);
    printf("Size: %d\n", size(doubly));
    printDoublyListForwards(doubly);
    printDoublyListBackwards(doubly);
    printf("\n");

    // Testing: insertNodeTail();
    // Normal Case
    //
    // Expected Output:
    //     Size: 2
    //     NULL <-> 5 <-> 30 <-> NULL
    //     NULL <-> 30 <-> 5 <-> NULL
    insertNodeTail(doubly, thirty);
    printf("Size: %d\n", size(doubly));
    printDoublyListForwards(doubly);
    printDoublyListBackwards(doubly);
    printf("\n");

    // Testing: insertNodeHead();
    // Head Existed Case
    //
    // Expected Output:
    //     Size: 3
    //     NULL <-> 1 <-> 5 <-> 30 <-> NULL
    //     NULL <-> 30 <-> 5 <-> 1 <-> NULL
    insertNodeHead(doubly, one);
    printf("Size: %d\n", size(doubly));
    printDoublyListForwards(doubly);
    printDoublyListBackwards(doubly);
    printf("\n");

    // Testing: insertNodeTail();
    // Tail Existed Case
    //
    // Expected Output:
    //     Size: 4
    //     NULL <-> 1 <-> 5 <-> 30 <-> 50 <-> NULL
    //     NULL <-> 50 <-> 30 <-> 5 <-> 1 <-> NULL
    insertNodeTail(doubly, fifty);
    printf("Size: %d\n", size(doubly));
    printDoublyListForwards(doubly);
    printDoublyListBackwards(doubly);
    printf("\n");

    // Testing: insertNodeAfter();
    // Testing: insertNodeBefore();
    // Normal Case
    //
    // Expected Output:
    //     Size: 6
    //     NULL <-> 1 <-> 5 <-> 10 <-> 20 <-> 30 <-> 50 <-> NULL
    //     NULL <-> 50 <-> 30 <-> 20 <-> 10 <-> 5 <-> 1 <-> NULL
    insertNodeAfter(doubly, five, ten);
    insertNodeBefore(doubly, thirty, twenty);
    printf("Size: %d\n", size(doubly));
    printDoublyListForwards(doubly);
    printDoublyListBackwards(doubly);
    printf("\n");

    // Testing: insertNodeAfter();
    // Testing: insertNodeBefore();
    // Head and Tail Case
    //
    // Expected Output:
    //     Size: 8
    //     NULL <-> -1 <-> 1 <-> 5 <-> 10 <-> 20 <-> 30 <-> 50 <-> 100 <-> NULL
    //     NULL <-> 100 <-> 50 <-> 30 <-> 20 <-> 10 <-> 5 <-> 1 <-> -1 <-> NULL
    ListNode *min = createNode(-1);
    ListNode *max = createNode(100);
    insertNodeAfter(doubly, fifty, max);
    insertNodeBefore(doubly, one, min);
    printf("Size: %d\n", size(doubly));
    printDoublyListForwards(doubly);
    printDoublyListBackwards(doubly);
    printf("\n");

    // Testing: search();
    // Testing: insertNodeAfter();
    // Testing: insertNodeBefore();
    // Dumps Case
    //
    // Expected Output:
    //     Search five: 5
    //     Size: 12
    //     NULL <-> -1 <-> 5 <-> 1 <-> 5 <-> 5 <-> 10 <-> 20
    //          <-> 30 <-> 5 <-> 50 <-> 5 <-> 100 <-> NULL
    //     NULL <-> 100 <-> 5 <-> 50 <-> 5 <-> 30 <-> 20 <-> 10
    //          <-> 5 <-> 5 <-> 1 <-> 5 <-> -1 <-> NULL
    ListNode *five_dump1 = createNode(5);
    ListNode *five_dump2 = createNode(5);
    ListNode *five_dump3 = createNode(5);
    ListNode *five_dump4 = createNode(5);
    insertNodeAfter(doubly, min, five_dump1);
    insertNodeAfter(doubly, one, five_dump2);
    insertNodeBefore(doubly, max, five_dump3);
    insertNodeBefore(doubly, fifty, five_dump4);
    printf("Search five: %d\n", search(doubly, 5));
    printf("Size: %d\n", size(doubly));
    printDoublyListForwards(doubly);
    printDoublyListBackwards(doubly);

    // Testing: removeNode();
    // Head, Tail and Normal Cases
    //
    // Expected Output:
    //     Size: 6
    //     NULL <-> 1 <-> 5 <-> 10 <-> 20 <-> 30 <-> 50 <-> NULL
    //     NULL <-> 50 <-> 30 <-> 20 <-> 10 <-> 5 <-> 1 <-> NULL
    removeNode(doubly, doubly->head);
    removeNode(doubly, doubly->tail);
    removeNode(doubly, five_dump1);
    removeNode(doubly, five_dump2);
    removeNode(doubly, five_dump3);
    removeNode(doubly, five_dump4);
    printf("Size: %d\n", size(doubly));
    printDoublyListForwards(doubly);
    printDoublyListBackwards(doubly);

    // Testing: removeNode();
    // node->prev and node->next Cases
    //
    // Expected Output:
    //     Size: 2
    //     NULL <-> 1 <-> 50 <-> NULL
    //     NULL <-> 50 <-> 1 <-> NULL
    removeNode(doubly, ten->prev);
    removeNode(doubly, ten->next);
    removeNode(doubly, ten->next);
    removeNode(doubly, ten);
    printf("Size: %d\n", size(doubly));
    printDoublyListForwards(doubly);
    printDoublyListBackwards(doubly);

    freeList(doubly);
}


int main(void) {
    testVisually_DoublyLinkedList();
    return 0;
}
