// Rotate a Linked List
ListNode *rotateRight(ListNode *head, int k)
{

    if (!head || !head->next || k == 0)
    {
        return head;
    }

    ListNode *curr = head;
    int len = 1;
    while (curr->next)
    {
        curr = curr->next;
        len++;
    }

    curr->next = head;
    k = k % len;
    k = len - k;

    while (k--)
        curr = curr->next;

    head = curr->next;
    curr->next = NULL;

    return head;
}