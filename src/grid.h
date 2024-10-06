#pragma once
#include <vector>
#include <raylib.h>
#include "colors.h"
class Grid
{

public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool isCellEmtpy(int row, int colum);
    int ClearFullRows();
    int grid[20][10];

private:
    bool isRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};