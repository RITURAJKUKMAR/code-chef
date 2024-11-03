typedef struct LinkedList {
    Node* head;
    
    // Create the Node tail
    Node* tail;
    
    
} LinkedList;

// Function to insert a node at the end of the linked list
void insertAtEnd(LinkedList* list, int value) {
    Node* newNode = createNode(value);
    Node* t;
    // If there are no nodes in the linked list
    // Set the new node as head and tail
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;
    }
    else
    {
        t=list->tail;
        t->next=newNode;
        newNode->next=NULL;
        list->tail=newNode;
    }
    // Set next of tail to the new Node
    // Set new Node as the new tail
}