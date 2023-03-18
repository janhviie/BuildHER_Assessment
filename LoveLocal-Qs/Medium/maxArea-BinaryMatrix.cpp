#include <bits/stdc++.h>
using namespace std;

// MEDIUM 3
// QUESTION - Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

int maxAreaOfMatrix(vector<vector<char>> &matrix)
{

    int rowLen = matrix.size();
    int colLen = matrix[0].size();

//each element of the DP matrix represents the size of the largest square ending at that position in the input matrix.
    vector<vector<int>> dp(rowLen, vector<int>(colLen, 0));
    int ans = 0;

    for (int i = 0; i < rowLen; i++)
    {
        for (int j = 0; j < colLen; j++)
        {
            if ((i == 0 || j == 0) && matrix[i][j] == '1')
            {
                dp[i][j] = 1;
            }
            else if (i != 0 && j != 0 && matrix[i][j] == '1')
            {
                // finding the min value among top-left diagonal, left and top
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
            }

            ans = max(ans, dp[i][j]);
        }
    }

    return ans * ans;
}

int main()
{

    // Input Format -:
    // First Line consisting of N and M - the number of rows and columns of matrix 
    // Second Line - N*M space-separated integers, the elements of the matrix 
    int n=0,m=0;
    cin>>n>>m;

    vector<vector<char>> matrix(n, vector<char>(m,'0'));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char elem;
            cin>>elem;

            matrix[i][j] = elem;
        }
    }

    cout<<"Area of Max length Square in a Binary Matrix -> "<<maxAreaOfMatrix(matrix)<<endl;
}

// TIME COMPLEXITY - O(N*M) where N and M are number of rows and cols in matrix
// SPACE COMPLEXITY - (N*M)