//  Add Two Numbers
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *dummy = new ListNode(-1, l1);
    ListNode *temp = dummy;
    int carry = 0;

    while (l1 || l2 || carry)
    {
        int sum = 0;

        // checking if l1 list exists
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        // checking if l2 list exists
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        ListNode *node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }

    return dummy->next;
}