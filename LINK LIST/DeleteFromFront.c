
void deleteNode(struct LinkedList* list, int value) {
    if (list->head->value == value) {
        struct Node* targetNode = list->head;
        // Set head to the next of targetNode
        list->head=targetNode->next;
        // Delete the target node
        
    }
}
