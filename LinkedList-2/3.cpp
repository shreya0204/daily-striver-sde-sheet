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

ListNode *getKthNode(ListNode *temp, int k)
{
    k -= 1;
    while (temp != NULL && k > 0)
    {
        temp = temp->next;
        k--;
    }

    return temp;
}

ListNode *reverseKGroup(ListNode *head, int k)
{

    ListNode *temp = head;
    ListNode *prevLast = NULL;

    while (temp)
    {

        ListNode *kthNode = getKthNode(temp, k);

        if (kthNode == NULL)
        {
            if (prevLast)
                prevLast->next = temp;
            break;
        }

        ListNode *nextNode = kthNode->next;
        kthNode->next = NULL;

        // reversing the list
        reverseList(temp);

        if (head == temp)
        {
            head = kthNode;
        }
        else
        {
            prevLast->next = kthNode;
        }

        prevLast = temp;
        temp = nextNode;
    }

    return head;
}