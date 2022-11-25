#pragma once

#include <cassert>
#include <iostream>
#include <vector>

#include "island.h"

void TestCountIslands()
{
    Island s;
    {
        std::vector<std::vector<int>> v = {};
        assert(s.CountIslands(v) == 0);
    }
    {
        std::vector<std::vector<int>> v = { {0,0,0,0,0} };
        assert(s.CountIslands(v) == 0);
    }
    {
        std::vector<std::vector<int>> v = { {0,0,0,1,0} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {0,0,1,1,0} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {0,0,1,1,1} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {0,0,0,0,1} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {0,0,0,0,1} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {1,0,0,0,} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {1,1,0,0,0} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {0,1,0,0,1} };
        assert(s.CountIslands(v) == 2);
    }
    {
        std::vector<std::vector<int>> v = { {1,1,0,1,1} };
        assert(s.CountIslands(v) == 2);
    }
    {
        std::vector<std::vector<int>> v = { {0},{0},{0},{0},{0} };
        assert(s.CountIslands(v) == 0);
    }
    {
        std::vector<std::vector<int>> v = { {0},{0},{0},{1},{0} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {0},{0},{0},{0},{1} };
        assert(s.CountIslands(v) == 1);
        assert(v == std::vector<std::vector<int>>({{0},{0},{0},{0},{1}}));
    }
    {
        std::vector<std::vector<int>> v = { {0},{0},{0},{1},{1} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {1},{0},{0},{0},{0} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {1},{1},{0},{0},{0} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = { {0},{1},{0},{1},{0} };
        assert(s.CountIslands(v) == 2);
    }
    {
        std::vector<std::vector<int>> v = { {1},{1},{0},{1},{1} };
        assert(s.CountIslands(v) == 2);
    }
    {
        std::vector<std::vector<int>> v = {
            {1,1,1,1,0} ,
            {1,1,0,1,0} ,
            {1,1,1,0,0} ,
            {0,0,0,0,0} };
        assert(s.CountIslands(v) == 1);
    }
    {
        std::vector<std::vector<int>> v = {
            {1,0,1,0,1} ,
            {0,1,0,1,0} ,
            {1,0,1,0,1} ,
            {0,1,0,1,1} };
        assert(s.CountIslands(v) == 9);
    }
    {
        std::vector<std::vector<int>> v = {
            {1,1,1,0,0,0} ,
            {1,1,0,0,0,0} ,
            {1,0,0,0,0,1} ,
            {0,0,0,0,1,1} ,
            {0,0,0,1,1,1} };
        assert(s.CountIslands(v) == 2);
    }
    {
        std::vector<std::vector<int>> v = {
            {1,1,1,0,0,0} ,
            {1,1,0,0,0,0} ,
            {1,0,1,1,0,1} ,
            {0,0,0,0,1,1} ,
            {0,0,0,1,1,1} };
        assert(s.CountIslands(v) == 3);
    }
    {
        std::vector<std::vector<int>> v = {
            {1,1,1,0,0,0} ,
            {1,1,0,1,0,0} ,
            {1,0,1,1,0,1} ,
            {0,0,1,0,1,1} ,
            {0,0,0,1,1,1} };
        assert(s.CountIslands(v) == 3);
    }
    {
        std::vector<std::vector<int>> v = {
            {1,1,1,0,1,1} ,
            {1,1,0,1,1,0} ,
            {1,0,1,1,0,1} ,
            {0,1,1,0,1,1} ,
            {1,1,0,1,1,1} };
        assert(s.CountIslands(v) == 3);
    }
    {
        std::vector<std::vector<int>> v = {
            {0,0,0,0,0,0} ,
            {0,1,1,0,1,0} ,
            {0,1,0,0,1,0} ,
            {0,0,0,1,1,0} ,
            {0,0,0,0,0,0} };
        assert(s.CountIslands(v) == 2);
    }
    {
        std::vector<std::vector<int>> v = {
            {0,0,0,0,0,0} ,
            {0,1,1,1,1,1} ,
            {0,1,0,0,0,1} ,
            {0,1,0,1,0,1} ,
            {0,1,0,0,0,1} ,
            {0,1,1,1,1,1} };
        assert(s.CountIslands(v) == 2);
    }
    {
        std::vector<std::vector<int>> v = {
            {1,1,0,0,0,0} ,
            {1,0,0,1,1,1} ,
            {0,0,0,0,0,1} ,
            {0,1,0,1,0,1} ,
            {0,1,0,0,0,1} ,
            {0,1,1,1,1,1} };
        assert(s.CountIslands(v) == 3);
    }

	std::cout << "CountIslands test is OK!" << std::endl;
}

void TestCountSubIslands()
{
    /*{
    Solution s;
    vector<vector<int>> island1, island2;
    island1 = {
        {1,0,1,0,1},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {1,1,1,1,1},
        {1,0,1,0,1} };
    island2 = {
        {0,0,0,0,0},
        {1,1,1,1,1},
        {0,1,0,1,0},
        {0,1,0,1,0},
        {1,0,0,0,1} };
    assert(s.CountSubIslands(island1, island2) == 2);
    island1 = {
        {1, 1, 1, 1, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 0} };
    island2 = {
        {1, 1, 1, 1, 0, 1},
        {0, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0} };
    assert(s.CountSubIslands(island1, island2) == 0);
}//*/
}

void AllTests()
{
	TestCountIslands();

	std::cout << "All the tests are OK!" << std::endl;

}