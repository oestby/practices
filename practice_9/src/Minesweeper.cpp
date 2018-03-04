#include "Minesweeper.h"
#include "utils.hpp"

Minesweeper::Minesweeper(int width, int height, int mines):
width(width), height(height)
 {
    if (width && height)
    {
    tiles = new Tile*[width];
    for (int i = 0; i < width; i++)
    {
        tiles[i] = new Tile[height];
    }
    }
    else tiles = nullptr;
    setMines();
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

bool Minesweeper::isGameOver() const {
    return false;
}

bool Minesweeper::isTileOpen(int row, int col) const {
    return tiles[row][col].open;
}

bool Minesweeper::isTileMine(int row, int col) const {
    return tiles[row][col].mine;
}

void Minesweeper::openTile(int row, int col) {

}

int Minesweeper::numAdjacentMines(int row, int col) const {
    return 0;
}

void
Minesweeper::setMines(void)
{
    int x, y;
    for (int i = 0; i < mines;)
    {
        x = randomInt(0,width);
        y = randomInt(0, height);
        if (!tiles[x][y].mine)
        {
            tiles[x][y].mine = true;
            i++;
        }
        else continue;
    }
}