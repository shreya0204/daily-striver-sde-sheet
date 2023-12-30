// Majority Element II
vector<int> majorityElement(vector<int> &nums)
{

    int size = nums.size();
    unordered_map<int, int> mp;
    vector<int> ans;

    for (int i = 0; i < size; i++)
    {
        mp[nums[i]]++;
        if (mp.size() == 3)
        {
            for (auto it = mp.begin(); it != mp.end();)
            {
                if (--it->second == 0)
                {
                    it = mp.erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }
    }

    if (mp.size() == 0)
        return ans;

    for (auto n : mp)
    {
        int num = n.first;
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == num)
                count++;
        }

        if (count > size / 3)
            ans.push_back(num);
    }

    return ans;
}