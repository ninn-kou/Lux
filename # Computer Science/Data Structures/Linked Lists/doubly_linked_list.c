/**
 * Doubly linked list in C programming language.
 *
 * @Date    12 August, 2021
 * @Author  Hao Ren, <haoren.2906@gmail.com>
 * @GitHub  <https://github.com/flying-yogurt>
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
} ListNode;

typedef struct list {
    ListNode *head;
    ListNode *tail;
} DoublyList;

/**
 * Initializing.
 */

DoublyList *createDoublyList() {
    DoublyList *list = (DoublyList *)malloc(sizeof(DoublyList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

ListNode *createNode(int value) {
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    new->val = value;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

/**
 * Node inserting.
 */

void insertNodeAfter(DoublyList *linkedList, ListNode *node, ListNode *new) {
    new->prev = node;
    if (node->next != NULL) {
        new->next = node->next;
        new->next->prev = new;
    } else {
        linkedList->tail = new;
    }
    node->next = new;
}

void insertNodeBefore(DoublyList *linkedList, ListNode *node, ListNode *new) {
    new->next = node;
    if (node->prev != NULL) {
        new->prev = node->prev;
        new->prev->next = new;
    } else {
        linkedList->head = new;
    }
    node->prev = new;
}

void insertNodeHead(DoublyList *linkedList, ListNode *new) {
    if (linkedList->head != NULL) {
        insertNodeBefore(linkedList, linkedList->head, new);
    } else {
        linkedList->head = new;
        linkedList->tail = new;
    }
}

void insertNodeTail(DoublyList *linkedList, ListNode *new) {
    if (linkedList->tail != NULL) {
        insertNodeAfter(linkedList, linkedList->tail, new);
    } else {
        insertNodeHead(linkedList, new);
    }
}

/**
 * Node removing.
 */

void removeNode(DoublyList *linkedList, ListNode *node) {
    if (node != NULL) {
        if (node->prev != NULL) {
            node->prev->next = node->next;
        } else {
            linkedList->head = node->next;
        }
        if (node->next != NULL) {
            node->next->prev = node->prev;
        } else {
            linkedList->tail = node->prev;
        }
        free(node);
        node = NULL;
    } else {
        printf("removeNode(): DNE ERROR\n");
    }
}

/**
 * It returns the number of element occurs in the linked list.
 * If no corrsponding value found, it returns 0.
 */

int search(DoublyList *linkedList, int value) {
    int isFound = 0;
    ListNode *current = linkedList->head;
    while (current != NULL) {
        if (current->val == value) {
            isFound += 1;
        }
        current = current->next;
    }
    return isFound;
}

int size(DoublyList *linkedList) {
    int size = 0;
    ListNode *current = linkedList->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void printDoublyListForwards(DoublyList *linkedList) {
    if (linkedList->head != NULL) {
        ListNode *current = linkedList->head;
        printf("NULL <-> ");
        while (current != NULL) {
            printf("%d <-> ", current->val);
            if (current->next == NULL) {
                printf("NULL\n");
            }
            current = current->next;
        }
    } else {
        printf("printDoublyListForwards(): DNE ERROR\n");
    }
}

void printDoublyListBackwards(DoublyList *linkedList) {
    if (linkedList->tail != NULL) {
        ListNode *current = linkedList->tail;
        printf("NULL <-> ");
        while (current != NULL) {
            printf("%d <-> ", current->val);
            if (current->prev == NULL) {
                printf("NULL\n");
            }
            current = current->prev;
        }
    } else {
        printf("printDoublyListBackwards(): DNE ERROR\n");
    }
}

void freeList(DoublyList *linkedList) {
    ListNode *current = linkedList->head;
    while (current != NULL) {
        ListNode *destory = current;
        current = current->next;
        free(destory);
        destory = NULL;
    }
    free(linkedList);
    linkedList = NULL;
}


/**
 * @Test
 *
 * To run tests, execute following commands:
 *   $ clang doubly_linked_list.c -o doubly_linked_list
 *   $ ./doubly_linked_list
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

    freeList(doubly);
}


int main(void) {
    testVisually_DoublyLinkedList();
    return 0;
}
