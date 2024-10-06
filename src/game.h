#pragma once
#include "grid.h"
#include "blocks.cpp"
class Game
{
public:
    Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;

private:
    void Reset();
    void MoveBlockLeft();
    void MoveBlockRight();
    bool IsBlockOutside();
    void RotateBlock();
    std::vector<Block> GetAllBlocks();
    void LockBlock();
    bool BlockFites();
    Block GetRandomBlock();
    void UpdateScore(int LinesCleared, int moveDownPoints);
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    Sound rotateSound;
    Sound clearSound;
};
