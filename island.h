#pragma once

#include <vector>

class Island {
public:
    int CountIslands(std::vector<std::vector<int>> grid);
    int CountSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2);

private:
    void SinkIsland(std::vector<std::vector<int>>& sub, int x, int y);
    bool IsSubIsland(std::vector<std::vector<int>>& sub, std::vector<std::vector<int>>& grid, int x, int y);
};