// Copy List with Random Pointer
Node *copyRandomList(Node *head)
{

    Node *node = head;
    while (node)
    {
        Node *temp = node->next;
        Node *copyNode = new Node(node->val);
        node->next = copyNode;
        copyNode->next = temp;
        node = temp;
    }

    node = head;
    while (node)
    {
        if (node->random)
        {
            node->next->random = node->random->next;
        }
        node = node->next->next;
    }

    Node *dummy = new Node(0);
    Node *temp = dummy;
    Node *newHead = head;

    while (newHead)
    {
        temp->next = newHead->next;
        temp = temp->next;

        newHead->next = newHead->next->next;
        newHead = newHead->next;
    }

    return dummy->next;
}