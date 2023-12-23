// Kadane's Algorithms

int maxSubArray(vector<int> &nums)
{
    int size = nums.size();
    int maxi = nums[0];
    int curr = nums[0];

    for (int i = 0; i < size; i++)
    {
        if (curr < 0)
            curr = 0;
        curr = curr + nums[i];
        maxi = max(curr, maxi);
    }

    return maxi;
}