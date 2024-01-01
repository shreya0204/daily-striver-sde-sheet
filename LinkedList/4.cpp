// Remove Nth Node From End of List

ListNode *removeNthFromEnd(ListNode *head, int n)
{

    ListNode *dummy = new ListNode(-1, head);
    ListNode *start = dummy;
    ListNode *mover = head;

    while (n > 0)
    {
        mover = mover->next;
        n--;
    }

    while (mover)
    {
        mover = mover->next;
        start = start->next;
    }

    start->next = start->next->next;

    return dummy->next;
}