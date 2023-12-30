//  Majority Element
int majorityElement(vector<int> &v)
{

    int size = v.size();
    if (size == 1)
        return v[0];
    int curr = v[0];
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (count == 0)
        {
            curr = v[i];
            count = 1;
            continue;
        }
        if (v[i] == curr)
            count++;
        else if (v[i] != curr)
            count--;
    }

    return count > 0 ? curr : -1;
}