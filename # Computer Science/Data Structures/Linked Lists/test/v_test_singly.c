#include <stdio.h>
#include <stdlib.h>
#include "../singly_linked_list.c"

/**
 * @Test
 *
 * To run tests, execute following commands:
 *   $ clang v_test_singly.c -o v_test_singly
 *   $ ./v_test_singly
 * and expected outputs would be showed below each testing part.
 *
 * NOTE: The tester needs to make sure each node would be inserted, and once ONLY.
 */
void testVisually_SinglyLinkedList() {
    SinglyList *singly = createSinglyList();
    ListNode *one = createNode(1);
    ListNode *two = createNode(2);
    ListNode *four = createNode(4);
    ListNode *five = createNode(5);
    insertNodeHead(singly, one);
    insertNodeAfter(one, two);
    insertNodeAfter(two, four);
    insertNodeAfter(four, five);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 4
    //   1 -> 2 -> 4 -> 5 -> NULL

    printf("\n");

    ListNode *three = createNode(3);
    insertNodeAfter(two, three);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 5
    //   1 -> 2 -> 3 -> 4 -> 5 -> NULL

    printf("\n");

    ListNode *zero = createNode(0);
    insertNodeHead(singly, zero);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 6
    //   0 -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    printf("\n");

    printf("Find value 3: %d\n", findValue(singly, 3));
    printf("Find value 7: %d\n", findValue(singly, 7));
    // OUTPUT:
    //   Find value 3: 1
    //   Find value 7: 0

    printf("\n");

    removeNodeHead(singly);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 5
    //   1 -> 2 -> 3 -> 4 -> 5 -> NULL

    printf("\n");

    removeNodeAfter(three);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 4
    //   1 -> 2 -> 3 -> 5 -> NULL

    printf("\n");

    removeNodeAfter(five);
    // OUTPUT:
    //   The node you want to delete does not exist.

    printf("\n");

    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 4
    //   1 -> 2 -> 3 -> 5 -> NULL

    printf("\n");

    removeNodeHead(singly);
    removeNodeAfter(two);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 2
    //   2 -> 5 -> NULL

    printf("\n");

    removeNodeHead(singly);
    removeNodeHead(singly);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 0
    //   The linked list does not exist.

    freeList(singly);
}


int main(void) {
    testVisually_SinglyLinkedList();
    return 0;
}
