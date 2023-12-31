//  Two Sum
vector<int> twoSum(vector<int> &nums, int target)
{

    int size = nums.size();
    map<int, int> mpp;

    for (int i = 0; i < size; i++)
    {
        // Checking if other half exist
        if (mpp.find(target - nums[i]) != mpp.end())
        {
            return {mpp[target - nums[i]], i};
        }
        else
        {
            mpp[nums[i]] = i;
        }
    }

    return {-1, -1};
}