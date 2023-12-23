// Next Permutation

void nextPermutation(vector<int> &nums)
{
    int size = nums.size();
    int peekIndex = -1;
    int index = size - 1;

    // finding the peek from r->l
    while (index > 0)
    {
        if (nums[index] > nums[index - 1])
        {
            peekIndex = index;
            break;
        }
        index--;
    }

    // if peek is not found, then the array is in descending order
    if (peekIndex == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // If peek element is found -> swap the element with just the greater element than that.
    int elementToBeSwapped = nums[peekIndex - 1];
    for (int i = size - 1; i >= peekIndex; i--)
    {
        if (nums[i] > elementToBeSwapped)
        {
            swap(nums[i], nums[peekIndex - 1]);
            break;
        }
    }

    // reverse the array from peekIndex to end
    reverse(nums.begin() + peekIndex, nums.end());
}

/*
    Space Complexity = O(1)
    Time Complexity = O(N)
*/