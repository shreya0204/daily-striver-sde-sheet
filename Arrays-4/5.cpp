// Subarray Sum Equals K

int subarraySum(vector<int> &nums, int k)
{

    int size = nums.size();
    long long sum = 0;
    int maxLen = 0;
    map<long long, int> mpp;
    int count = 0;

    for (int i = 0; i < size; i++)
    {

        sum += nums[i];
        if (sum == k)
        {
            count++;
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - k;
        if (mpp.find(rem) != mpp.end())
        {
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);

            count += mpp[rem];
        }

        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = 1;
        }
        else
        {
            mpp[sum]++;
        }
    }

    return count;
}