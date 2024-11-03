
void deleteNode(struct LinkedList* list, int value) {
    if (list->head->value == value) {
        struct Node* targetNode = list->head;
        list->head = targetNode->next;
        free(targetNode);
    } else {
        struct Node* iter = list->head;
        struct Node* t;
        
        // Traverse the list
        // When next element is our target element, eliminate it
        while (iter->next != NULL) {
            if (iter->next->value == value) {
                // Set next of iter
                // To next to next of iter
                t=iter->next;
                iter->next=iter->next->next;
                free(t);
                
                break;
            }
            iter = iter->next;
        }
    }
}
