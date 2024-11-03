
void deleteNode(struct LinkedList* list, int value) {
    struct Node* targetNode = list->head;
    while (targetNode && targetNode->value != value) {
        targetNode = targetNode->next;
    }

    if (targetNode == NULL)
        return;

    // Update A and B
    struct Node* A = targetNode -> prev;
    struct Node* B = targetNode -> next;
    
    // A could be null if target is head
    if (A != NULL) {
        A -> next = B;
    }

    // B could be null if target is tail
    if (B != NULL) {
        B -> prev = A;
    }

    if (targetNode == list->head) {
        list->head = B;
    }

    free(targetNode);
}