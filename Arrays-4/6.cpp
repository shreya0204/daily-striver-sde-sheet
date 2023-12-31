// Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string arr)
{
    int n = arr.size();
    set<int> s;
    int ans = 0;
    int start = 0;
    int end = 0;

    while (end < n)
    {

        while (s.count(arr[end]) != 0)
        {
            s.erase(arr[start]);
            start++;
        }

        s.insert(arr[end]);
        ans = max(ans, end - start + 1);
        end++;
    }
    return ans;
}