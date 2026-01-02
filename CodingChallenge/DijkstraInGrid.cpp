#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

// each number represents a weight to this point
const vector<vector<char>> grid = { {'1', '0', '1', '1', '#', '#'},
                                    {'1', 'T', '4', '1', '0', '1'},
                                    {'2', '1', '3', '0', '2', '2'},
                                    {'3', '2', '#', '3', '1', '#'},
                                    {'#', '0', '3', '2', '1', '7'},
                                    {'#', '1', '4', '1', 'S', '1'},
                                    {'#', '#', '#', '#', '#', '#'} };

unsigned int DijkstraShortestPath(const vector<vector<char>>& grid,
    pair<unsigned int, unsigned int> start,
    pair<unsigned int, unsigned int> target)
{
	if (grid.empty())
	{
        return -1;
	}
    unsigned int nRow = grid.size();
    unsigned int nCol = grid[0].size();

    // reference because copy grid can be expensive
    auto isInRange = [&](auto row, auto col)
    {
	    if (row < 0 || row >= nRow || col < 0 || col >= nCol)
	    {
            return false;
	    }
        return true;
    };

    auto isAccessible = [&](auto row, auto col)
    {
        if (grid[row][col] == '#')
        {
            return false;
        }
        return true;
    };

    auto getWeight = [&](auto r, auto c)
	{
        char ch = grid[r][c];
        if (ch >= '0' && ch <= '9')
            return ch - '0';
        // S, E or other chars: no candy
        return 0;
    };

    auto startRow = start.first;
    auto startCol = start.second;
    constexpr unsigned int inf = std::numeric_limits<unsigned int>::max();

    struct Node {
        unsigned int row, col;
        unsigned int dist;
    };
    struct Cmp
    {
	    bool operator() (const Node& a, const Node& b) const
	    {
	        return a.dist > b.dist;
	    }
    };

    // to enable the search of dist status by index
    vector distGrid(nRow, vector(nCol, inf));
    distGrid[startRow][startCol] = 0;

    priority_queue<Node, vector<Node>, Cmp> pq;
    pq.emplace(start.first, start.second, 0);

    const int directions[5] = {0, 1, 0, -1, 0};
	while (!pq.empty())
	{
        auto currentNode = pq.top();
        pq.pop();
        auto currentRow = currentNode.row;
        auto currentCol = currentNode.col;

        // duplicate stale nodes ignored
        if (currentNode.dist != distGrid[currentRow][currentCol])
	        continue;
        
        // popped target definitely has shortest path
        if (currentRow == target.first && currentCol == target.second)
			break;

        for (int i = 0; i < 4; ++i)
        {
            auto newRow = currentRow + directions[i];
            auto newCol = currentCol + directions[i + 1];

            if (!isInRange(newRow, newCol))
                continue;
			// accessiblity check
            if (!isAccessible(newRow, newCol))
                continue;

            auto oldDist = distGrid[newRow][newCol];
            auto newDist = distGrid[currentRow][currentCol] + getWeight(newRow, newCol);
	                
            if (newDist < oldDist)
            {
                // relaxation update: store the improved best-known distance
                distGrid[newRow][newCol] = newDist;
	            // in case of update, priority queue can contain multiple nodes with different dist
				pq.emplace(newRow, newCol, newDist);
            }
        }
	}

    // to visualize the result
	/*for (int i = 0; i < nRow; ++i)
	{
		for (int j = 0; j < nCol; ++j)
		{
            cout << std::right << std::setw(10) << distGrid[i][j] << '\t';
		}
        cout << '\n';
	}*/
    return distGrid[target.first][target.second];
}

int main()
{
    DijkstraShortestPath(grid, { 5, 4 }, { 1, 1 });
}
