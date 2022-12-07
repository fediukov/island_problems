# Problems with Islands

Интересные логические задачки про острова (решение на C++).

## Содержание

  + [Задача 1: Подсчитать количество островов](https://github.com/fediukov/problems_with_islands#%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-1-%D0%BF%D0%BE%D0%B4%D1%81%D1%87%D0%B8%D1%82%D0%B0%D1%82%D1%8C-%D0%BA%D0%BE%D0%BB%D0%B8%D1%87%D0%B5%D1%81%D1%82%D0%B2%D0%BE-%D0%BE%D1%81%D1%82%D1%80%D0%BE%D0%B2%D0%BE%D0%B2)
  + [Задача 2: Подсчитать количество суб-островов](https://github.com/fediukov/problems_with_islands#%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-2-%D0%BF%D0%BE%D0%B4%D1%81%D1%87%D0%B8%D1%82%D0%B0%D1%82%D1%8C-%D0%BA%D0%BE%D0%BB%D0%B8%D1%87%D0%B5%D1%81%D1%82%D0%B2%D0%BE-%D1%81%D1%83%D0%B1-%D0%BE%D1%81%D1%82%D1%80%D0%BE%D0%B2%D0%BE%D0%B2)

## Задача 1: Подсчитать количество островов

### Условие

Дан двумерный массив чисел размером `m x n`, который представляет собой карту, где `1` - это земля и `0` - это вода. Необходимо вернуть количество островов.

Остров окружен водой и образован путём соединения соседних земель по горизонтали или вертикали. За пределами карты находится вода.

### Ограничения

  + `m == grid.length`
  + `n == grid[i].length`
  + `1 <= m`, `n <= 300`
  + `grid[i][j]` равен либо `0`, либо `1`
  
### Объяснение

Чтобы подсчитать количество островов, необходимо пробежаться по карте и при обнаружении острова учесть его один раз. Для этого "утопим" его, т.е. поменяем все его ```1``` на ```0```. Меняем клетку, где мы обнаружили остров, с ```1``` на ```0```. Далее проверяем соседние клетки во всех 4-х направлениях, и если сосед тоже ```1```, то принадлежит обнаруженному острову, и меняем его на ```0```. С соседом соседа поступаем так же. Когда все клетки острова "утоплены", он исчёз с карты и следующая ```1``` будет принадлежать уже другому острову.

![alt text](https://github.com/fediukov/island_problems/blob/main/images/picture_1.png "Example")

Для решения понадобится дополнительная функция ```SinkIsland(vector<vector<int>>& grid, int x, int y)```, которая меняет клетку с ```1``` на ```0``` в координатах ```{x,y}``` и рекурсивно вызывает саму себя для соседних ```1```.

### Решение

```
    class Island {
    public:
        int CountIslands(std::vector<std::vector<int>> grid) {
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
        
    private:    
        void SinkIsland(std::vector<std::vector<int>>& grid, int x, int y)
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
    };
    
    int main()
    {
        Island i;
        
        std::vector<std::vector<int>> v = {
            {0,1,1,0,1} ,
            {0,1,1,1,1} ,
            {0,0,0,0,0} ,
            {1,0,0,0,0} ,
            {1,1,0,1,1} };
            
        assert(i.CountIslands(v) == 3);
    }
 ```
 
 ## Задача 2: Подсчитать количество суб-островов

### Условие

Даны два двумерных массива чисел `grid1` и `grid2`, каждый из которых размером ```m x n```. Оба массива представляет собой карту, где ```1``` - это земля и ```0``` - это вода. Необходимо вернуть количество островов в `grid2`, которые считаются суб-островами в `grid1`.

Остров окружен водой и образован путём соединения соседних земель по горизонтали или вертикали. За пределами карты находится вода.

Остров в `grid2` считается суб-островом, если в `grid1` есть остров, содержащий все ячейки, составляющие этот остров в `grid2`.

### Ограничения

  + `m == grid1.length == grid2.length`
  + `n == grid1[i].length == grid2[i].length`
  + `1 <= m`, `n <= 500`
  + `grid1[i][j]` и `grid2[i][j]` равен либо `0`, либо `1`
  
### Объяснение

Чтобы подсчитать количество островов `grid2`, являющимися суб-островами `grid1`, необходимо пробежаться по `grid2`. При обнаружении острова в `grid2` нужно понять является ли он суб-островом или нет. Если все клетки острова `grid2` (то есть все `1` этого острова в `grid2`) лежат на земле в `grid1` (то есть на `1` в `grid1`), то найденный остров является суб-остров. Если хотя бы одна клетка острова `grid2` лежит на воде (то есть на `0`), то остров суб-островом не является. Таким образом, обнаружив остров в `grid2`, "утопим" его, то есть поменяем клетку, в которой нашли остров, с `1` на `0`, а также поменяем все соседние `1` на `0`, попутно проверяя, чтобы все `1` также были `1` в `grid1`.

***Пример 1:***

![alt text](https://github.com/fediukov/island_problems/blob/main/images/picture_2.png "Example")

*Ответ: 3*

*Объясниение: Слева - grid1, справа - grid2. Единицы, окрашенные в красный цвет в grid2, считаются частью суб-острова. Есть три суб-острова.*

***Пример 2:***

![alt text](https://github.com/fediukov/island_problems/blob/main/images/picture_3.png "Example")

*Ответ: 2*

*Объясниение: Слева - grid1, справа - grid2. Единицы, окрашенные в красный цвет в grid2, считаются частью суб-острова. Есть два суб-острова.*

Для решения понадобится дополнительная функция `bool IsSubIsland(vector<vector<int>>& sub, vector<vector<int>>& grid, int x, int y);`, которая в grid2 меняет клетку с `1` на `0` в координатах `{x,y}`, проверяя, чтобы grid1 в этих же координатах `{x,y}` тоже была `1`. Возвращяет `true`, если это так, и `false`, если нет, и рекурсивно вызывает саму себя для соседних клеток. Если какая-то рекурсия возвращает `false`, то и первый вызов `IsSubIsland()` возвращает `false`.

### Решение


```
    class Island {
    public:
        int Island::CountSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2)
        {
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
        
    private:    
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
                sub[y][x] = 0;
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
    };
    
    int main()
    {
        Island i;
        
        std::vector<std::vector<int>> island1 = {
            {1,1,1,0,0},
            {0,1,1,1,1},
            {0,0,0,0,0},
            {1,0,0,0,0},
            {1,1,0,1,1} };
        std::vector<std::vector<int>> island2 = {
            {1,1,1,0,0},
            {0,0,1,1,1},
            {0,1,0,0,0},
            {1,0,1,1,0},
            {0,1,0,1,0} };
        assert(i.CountSubIslands(island1, island2) == 3);
    }
 ```
