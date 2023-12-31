//  Longest consecutive Sequence

int longestConsecutive(vector<int> &nums)
{

    int size = nums.size();
    if (size == 0)
        return 0;
    unordered_set<int> s;

    for (int num : nums)
    {
        s.insert(num);
    }

    int maxLen = 1;
    for (int num : nums)
    {
        if (s.find(num - 1) == s.end())
        {

            int curr = num;
            int currLen = 1;

            while (s.find(curr + 1) != s.end())
            {
                curr = curr + 1;
                currLen++;
            }

            maxLen = max(maxLen, currLen);
        }
    }

    return maxLen;
}