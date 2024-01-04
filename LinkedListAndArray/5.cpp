// Remove Duplicates from Sorted Array

int removeDuplicates(vector<int> &nums)
{

    int size = nums.size();
    if (size == 1)
        return 1;

    int left = 0;
    int itr = 1;

    while (itr < size)
    {
        if (nums[left] != nums[itr])
        {
            left++;
            nums[left] = nums[itr];
        }
        itr++;
    }
    return left + 1;
}