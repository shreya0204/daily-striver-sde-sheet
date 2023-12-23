//  Pascal's Triangle

vector<int> helper(vector<int> prev, int n)
{
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            v.push_back(1);
        else if (i == n - 1)
            v.push_back(1);
        else
            v.push_back((prev[i - 1] + prev[i]));
    }

    return v;
}

vector<vector<int>> generate(int numRows)
{

    vector<vector<int>> tri;
    tri.push_back(vector<int>(1, 1));
    int index = 1;

    while (index < numRows)
    {
        vector<int> row;
        row = helper(tri[index - 1], index + 1);
        tri.push_back(row);
        index++;
    }

    return tri;
}

/*

    numRows = n
    first iteration -> O(n)
    in every iteration -> we are iterating over above array -> O(n)
    total -> O(n^2)
*/