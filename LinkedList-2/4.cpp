// Palindrome Linked List
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

bool isPalindrome(ListNode *head)
{

    if (head == NULL || head->next == NULL)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *newHead = reverseList(slow->next);
    ListNode *first = head;
    ListNode *second = newHead;

    while (second)
    {
        if (first->val != second->val)
        {
            reverseList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseList(newHead);
    return true;
}