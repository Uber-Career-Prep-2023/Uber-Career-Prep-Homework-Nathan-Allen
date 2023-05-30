// Given a binary matrix in which 1s represent land and 0s represent water. 
// Return the number of islands (contiguous 1s surrounded by 0s or the edge of the matrix).

// Technique: Generic traversal (DFS)
// Thoughts: We know that an island is a contiguous set of 1's. 
// We can use a depth first search to traverse the matrix and mark all contiguous 1's as visited.
// How do we know that a 1 is visited? By simply setting it to 0, it eliminates the need for a set.
// DFS has to be done in four directions: up, down, left, right to check for contiguous 1's
// DFS can return false when out of bounds, or when the current cell is 0 (land found)
// When it returns, an island is formed


// Time complexity: O(m*n)
// Space complexity: O(m*n) - recursive stack
// Time taken: ~35 minutes

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& grid, int i, int j, int m, int n)
{   
    // if out of bounds or current cell is 0, return false
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        return false;

    // set current cell to 0, also the same as marking a cell as visited
    grid[i][j] = 0;


    // dfs in four different directions
    dfs(grid, i + 1, j, m, n);
    dfs(grid, i - 1, j, m, n);
    dfs(grid, i, j + 1, m, n);
    dfs(grid, i, j - 1, m, n);

    return true;
}   


int numofIslands(vector<vector<int>>& grid)
{
    // m = row length, n = column length
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if current cell is 1, check all 4 directions for contiguous 1's
            if (grid[i][j] == 1)
            {   
                // when dfs returns, increment island count
                dfs(grid, i, j, m, n);
                count++;
            }
        }
    }

    return count;   
}

int main() {

    vector<vector<int>> grid = {{1,0,1,1,1},
                                {1,1,0,1,1},
                                {0,1,0,0,0},
                                {0,0,0,1,0},
                                {0,0,0,0,0}};

    vector<vector<int>> grid2 = {{1,0,0},
                                {0,0,0}};


    cout << numofIslands(grid) << endl;
    // outputs 3

    cout << numofIslands(grid2) << endl;
    // outputs 1

    return 0;
}
