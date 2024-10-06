#include "grid.h"
#include <iostream>
#include "colors.h"
Grid::Grid() // constructor
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print()
{

    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {

            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

// loop that draws the base grid
void Grid::Draw()
{

    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }

    return true;
}

bool Grid::isCellEmtpy(int row, int colum)
{
    if (grid[row][colum] == 0)
    {
        return true;
    }

    return false;
}

int Grid::ClearFullRows()
{
    int compleated = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (isRowFull(row))
        {
            ClearRow(row);
            compleated++;
        }
        else if (compleated > 0)
        {
            MoveRowDown(row, compleated);
        }
    }
    return compleated;
}

bool Grid::isRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }

    return true;
}
void Grid::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
