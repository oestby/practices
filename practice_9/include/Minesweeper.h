#ifndef MINESWEEPER_HPP
#define MINESWEEPER_HPP


struct Tile
{
    bool open, mine, flag;
    Tile(): open(false), mine(false), flag(false) {}
};

class Minesweeper {
private:
    // Legg til de medlemsvariablene og hjelpefunksjonene du trenger
    int width, height, mines;
    bool game_over = false;
    Tile** tiles;
    void setMines(void);
    void openAdjacent(int row, int col);

public:
    Minesweeper(int width, int height, int mines);
    ~Minesweeper();

    bool isGameOver() const;

    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;

    void openTile(int row, int col);
    void toggleFlag(int row, int col);

    void printBoard() const;

    int numAdjacentMines(int row, int col) const;

    // Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};

#endif // MINESWEEPER_HPP
