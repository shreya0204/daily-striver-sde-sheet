// Search in a 2d matrix

/*
    bool search(vector<int> &row, int target){
        int low = 0;
        int high = row.size();

        while(low<=high){
            int mid = (low + high)/2;
            if(target == row[mid]) return true;
            if(target < row[mid]) high = mid-1;
            else low = mid+1;
        }

        return false;
    }
*/

// The intuition -> think a 2D matrix as a 1D matrix and then apply BS
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int l = 0, r = m * n - 1;
    while (l != r)
    {
        int mid = (l + r - 1) >> 1;
        if (matrix[mid / m][mid % m] < target)
            l = mid + 1;
        else
            r = mid;
    }
    return matrix[r / m][r % m] == target;

    /*
            for(int i=0;i<m;i++){
                if(target>= matrix[i][0] && target<= matrix[i][n-1]){
                    return search(matrix[i], target);
                }
            }

            return false;
    */
}