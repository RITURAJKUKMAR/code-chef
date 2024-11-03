
void deleteNode(struct LinkedList* list, int value) {
    // If there is only one element and it is the value to be deleted, remove it
    if (list->head == list->tail && list->head->value == value) {
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    // if the target is at head set head to second element and set tail's next to the new head
    struct Node* iter = list->head;
    struct Node* t;
    if (list->head->value == value) {
        list->head = list->head->next;
        list->tail->next = list->head;
        return;
    }

    // Now iterate over the linked list till you reach the tail and check if the next node is target
    // If it is, set current nodes next to the next of the next node and break.
    while (iter->next != NULL && iter != list->tail) {
        if (iter->next->value == value) {
            // If we found the value
            // Set current node's next to the next of the next node
            t=iter->next;
            iter->next=iter->next->next;
            free(t);
            // And break
            break;
        }
        iter = iter->next;  
    }
}