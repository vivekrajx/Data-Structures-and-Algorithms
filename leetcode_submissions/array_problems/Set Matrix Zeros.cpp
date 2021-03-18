class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
         //if val at any of the 0th col of any given row i
         //is 0 then set col0 as false
        if (matrix[i][0] == 0) col0 = 0;
         //then traversing for the rest of columns
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                //set corres row and col idx to 0
                matrix[i][0] = matrix[0][j] = 0;
    }
    //now traversing from backwards...
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;  //actually modify the matrix in o(1)
        if (col0 == 0) matrix[i][0] = 0;
        }
    }
};