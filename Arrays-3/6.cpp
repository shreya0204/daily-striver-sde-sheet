//  Reverse pairs
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

long long countPairs(vector<int> &arr, int low, int mid, int high)
{
    long long int count = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && ((double)arr[i] / 2.0) > arr[right])
            right++;

        count += (right - (mid + 1));
    }

    return count;
}

long long mergeSort(vector<int> &arr, int low, int high)
{
    long long cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    return mergeSort(nums, 0, n - 1);
}