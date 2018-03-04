#include "Minesweeper.h"
#include "utils.hpp"
#include <iostream>

Minesweeper::Minesweeper(int width, int height, int mines):
width(width), height(height), mines(mines)
 {
    if (width && height)
    {
        tiles = new Tile*[width];
        for (int i = 0; i < width; i++)
        {
            tiles[i] = new Tile[height];
        }
    }
    else exit(1);
    setMines();
    printBoard();
}

Minesweeper::~Minesweeper() {
    if (tiles)
    {
        for (int i = 0; i < width; i++)
        {
            delete tiles[i];
        }
        delete[] tiles;
    }
}

bool
Minesweeper::isGameOver() const 
{
    return game_over;
}

bool
Minesweeper::isTileOpen(int row, int col) const 
{
    return tiles[row][col].open;
}

bool
Minesweeper::isTileMine(int row, int col) const 
{
    return tiles[row][col].mine;
}

void
Minesweeper::openTile(int row, int col) 
{
    if (isTileOpen(row, col)) return;
    else if (isTileMine(row, col)) 
    {
        game_over = true;
        tiles[row][col].open = true;
    }
    else
    {
        tiles[row][col].open = true;
        openAdjacent(row, col);
    }
}

int
Minesweeper::numAdjacentMines(int row, int col) const 
{
    int adj_mines = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && j >= 0 && i < width && j < height)
            {
                if (tiles[i][j].mine) adj_mines++;
            }

        }
    }
    return adj_mines;
}

void
Minesweeper::openAdjacent(int row, int col)
{
    for (int i = row -1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && i < width && j >= 0 && j < height && (i == row || j == col))
            {
                //std::cout << i << ", " << j << std::endl;
                if (!tiles[i][j].mine && !tiles[i][j].open)
                {
                    tiles[i][j].open = true;
                    openAdjacent(i,j);
                }
            }
        }
    }
}

void
Minesweeper::setMines(void)
{
    int x, y;
    for (int i = 0; i < mines;)
    {
        x = randomInt(0,width-1);
        y = randomInt(0, height-1);
        //std::cout << x << "," << y << std::endl;
        if (!tiles[x][y].mine)
        {
            tiles[x][y].mine = true;
            i++;
            //std::cout << "Mine set!" << std::endl;
        }
        else continue;
    }
}

void
Minesweeper::printBoard() const
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            std::cout << (tiles[i][j].mine? "X":"0");
        }
        std::cout << std::endl;
    }
}

void
Minesweeper::toggleFlag(int row, int col)
{
    if (tiles[row][col].flag) tiles[row][col].flag = false;
    else tiles[row][col].flag = true;

}
