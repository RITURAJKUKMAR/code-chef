/*
// Node structure for the doubly linked list
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// LinkedList structure
typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

*/
// Function to insert a node at a specific index
void insertAtIndex(LinkedList* list, int index, int value) {
    // Complete this function
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (index == 0) {
        // To insert at head, make this new node the head
        newNode->next = list->head;
        if (list->head != NULL) {
            list->head->prev = newNode;
        }
        list->head = newNode;
    } else {
        struct Node* iter = list->head;
        for (int i = 0; i < index - 1; i++) {
            iter = iter->next;
        }
        
        struct Node* A = iter;
        struct Node* B = iter->next;
        
        A->next = newNode;
        if (B != NULL) {
            B->prev = newNode;
        }
        
        newNode->next = B;
        newNode->prev=A;
    }
}