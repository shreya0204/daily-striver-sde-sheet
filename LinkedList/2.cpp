//  Middle of the Linked List

ListNode *middleNode(ListNode *head)
{
    if (head == NULL)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}