// Delete Node in Linked List
void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}