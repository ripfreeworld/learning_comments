#include <queue>
#include <vector>
#include <utility>

using namespace std;

const vector<vector<char>> grid = { {'1', '0', '1', '1', '#', '#'},
                                    {'1', 'T', '#', '1', '0', '1'},
                                    {'2', '1', '3', '0', '2', '2'},
                                    {'3', '2', '#', '#', '1', '#'},
                                    {'#', '0', '1', '#', '1', '#'},
                                    {'#', '#', '4', '1', 'S', '#'},
                                    {'#', '#', '#', '#', '#', '#'} };

int CatchCandyOnTheWay(const vector<vector<char>>& grid,
    pair<int, int> start,
    pair<int, int> target)
{
	if (grid.empty())
	{
        return -1;
	}

    auto nRow = grid.size();
    auto nCol = grid[0].size();

    // reference because copy grid can be expensive
    auto isInRange = [&](std::integral auto row, std::integral auto col)
    {
	    if (row < 0 || row >= nRow || col < 0 || col >= nCol)
	    {
            return false;
	    }
        return true;
    };

    auto isAccessible = [&](std::integral auto row, std::integral auto col)
    {
        if (grid[row][col] == '#')
        {
            return false;
        }
        return true;
    };

    auto getCandy = [&](int r, int c) -> int
	{
        char ch = grid[r][c];
        if (ch >= '0' && ch <= '9')
            return ch - '0';
        // S, E or other chars: no candy
        return 0;
    };

    int startRow = start.first;
    int startCol = start.second;
    vector<vector<int>> distGrid(nRow, vector<int>(nCol, -1));
    vector<vector<int>> candyGrid(nRow, vector<int>(nCol, -1));
    candyGrid[startRow][startCol] = getCandy(startRow, startCol);

    queue<pair<int, int>> q;
    q.emplace(startRow, startCol);

    distGrid[startRow][startCol] = 0;

    const int directions[5] = {0, 1, 0, -1, 0};
	while (!q.empty())
	{
        auto currentElement = q.front();
        int currentRow = currentElement.first;
        int currentCol = currentElement.second;

        q.pop();

        // current popped point must have non-default value of distance
        if (distGrid[currentRow][currentCol] == distGrid[target.first][target.second])
			continue;

        for (int i = 0; i < 4; ++i)
        {
            int newRow = currentRow + directions[i];
            int newCol = currentCol + directions[i + 1];

            if (!isInRange(newRow, newCol))
                continue;
			// accessiblity check
            if (!isAccessible(newRow, newCol))
                continue;

            // standard BFS update: the first acccess
            if (distGrid[newRow][newCol] == -1)
            {
                distGrid[newRow][newCol] = distGrid[currentRow][currentCol] + 1;
                candyGrid[newRow][newCol] = candyGrid[currentRow][currentCol] + getCandy(newRow, newCol);
                q.emplace(newRow, newCol);
            }
            // distance/path exists, try more candy
            else if (distGrid[newRow][newCol] == distGrid[currentRow][currentCol] + 1 &&
                candyGrid[currentRow][currentCol] + getCandy(newRow, newCol) > candyGrid[newRow][newCol])
            {
                candyGrid[newRow][newCol] = candyGrid[currentRow][currentCol] + getCandy(newRow, newCol);
                // in case of updating with more candy, [newRow][newCol] already exists in the queue, no need to enqueue
            }
        }
	}
    return candyGrid[target.first][target.second];
}

int main()
{
    CatchCandyOnTheWay(grid, { 5, 4 }, { 1, 1 });
}
