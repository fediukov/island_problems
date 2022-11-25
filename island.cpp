#include "island.h"

int Island::CountIslands(std::vector<std::vector<int>> grid) {
    int count = 0;
    for (int y = 0; y < grid.size(); ++y)
    {
        for (int x = 0; x < grid[y].size(); ++x)
        {
            if (grid[y][x] == 1)
            {
                SinkIsland(grid, x, y);
                ++count;
            }
        }
    }
    return count;
}

int Island::CountSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
    if (!grid1.size() || !grid1[0].size())
    {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < grid1.size(); ++i)
    {
        for (int j = 0; j < grid1[0].size(); ++j)
        {
            if (grid2[i][j] == 1)
            {
                count += IsSubIsland(grid2, grid1, j, i);
            }
        }
    }

    return count;
}

void Island::SinkIsland(std::vector<std::vector<int>>& grid, int x, int y)
{
    grid[y][x] = 0;
    if (x-1 >= 0 && grid[y][x-1])
    {
        SinkIsland(grid, x - 1, y);
    }
    if (x+1 < grid[0].size() && grid[y][x+1])
    {
        SinkIsland(grid, x + 1, y);
    }
    if (y-1 >= 0 && grid[y-1][x])
    {
        SinkIsland(grid, x, y - 1);
    }
    if (y+1 < grid.size() && grid[y+1][x])
    {
        SinkIsland(grid, x, y + 1);
    }
}

bool Island::IsSubIsland(std::vector<std::vector<int>>& sub, std::vector<std::vector<int>>& grid, int x, int y)
{
    bool is_sub = true;
    if (sub[y][x] && grid[y][x] == 0)
    {
        SinkIsland(sub, x, y);
        return false;
    }
    if (sub[y][x] == 1 && grid[y][x] == 1)
    {
        sub[y][x] = 2;
        if (x-1 >= 0 && sub[y][x-1] == 1)
        {
            if (!IsSubIsland(sub, grid, x - 1, y))
            {
                is_sub = false;
            }
        }
        if (x+1 < sub[0].size() && sub[y][x+1] == 1)
        {
            if (!IsSubIsland(sub, grid, x + 1, y))
            {
                is_sub = false;
            }
        }
        if (y-1 >= 0 && sub[y-1][x] == 1)
        {
            if (!IsSubIsland(sub, grid, x, y - 1))
            {
                is_sub = false;
            }
        }
        if (y+1 < sub.size() && sub[y+1][x] == 1)
        {
            if (!IsSubIsland(sub, grid, x, y + 1))
            {
                is_sub = false;
            }
        }
    }
    return is_sub;
}
