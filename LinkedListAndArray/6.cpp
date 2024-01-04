// Max consecutive ones

int findMaxConsecutiveOnes(vector<int> &nums)
{

    int size = nums.size();
    int count = 0;
    int maxcount = 0;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] == 1)
            count++;
        else if (nums[i] == 0)
        {
            maxcount = max(count, maxcount);
            count = 0;
        }
    }

    return max(maxcount, count);
}