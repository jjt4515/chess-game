
#include <vector>
#include <iostream>
using namespace std;
const int BOARD_SIZE = 8;

enum Piece {
    EMPTY,
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

enum Color {
    BLANK,
    WHITE,
    BLACK
};

struct ChessPiece {
    Piece piece;
    Color color;
};

typedef ChessPiece ChessBoard[BOARD_SIZE][BOARD_SIZE];


void print_board(ChessBoard const board);
std::vector<std::pair<int, int>> find_bishop_moves(ChessBoard board, int x, int y, Color color) ;
std::vector<std::pair<int, int>> find_knight_moves(ChessBoard board, int x, int y, Color color);
std::vector<std::pair<int, int>> find_pawn_moves(ChessBoard board,int x, int y, Color color);
std::vector<std::pair<int, int>> find_rook_moves(ChessBoard board,int x, int y, Color color);
vector<pair<int,int>> find_king_moves(ChessBoard board, int x, int y, Color color);
vector<pair<int,int>> find_queen_moves(ChessBoard board, int x, int y, Color color);
bool who_is_win(ChessBoard board);
