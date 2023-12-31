// Count Subarray with given XOR
int subarraysXor(vector<int> &arr, int x)
{
    int xr = 0;
    int count = 0;
    int n = arr.size();
    unordered_map<int, int> mp;
    mp[xr]++;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int want = xr ^ x;
        count += mp[want];
        mp[xr]++;
    }

    return count;
}