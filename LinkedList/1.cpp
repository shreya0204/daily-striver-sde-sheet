// Reverse a 1D linked list
ListNode *reverseList(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *prev = NULL;
    ListNode *temp = head;

    while (temp != NULL)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

// Recursive
ListNode *reverseList(ListNode *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    ListNode *newhead = reverseList(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;

    return newhead;
}