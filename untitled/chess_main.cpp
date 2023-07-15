#include "chess.h"

bool make_move(ChessBoard board, int from_x, int from_y) {
    ChessPiece piece = board[from_x][from_y];
    std::vector<std::pair<int, int>> legal_moves;
    int go;

    switch (piece.piece) {
        case PAWN: {
            legal_moves = find_pawn_moves(board, from_x, from_y, piece.color);
            break;
        }
        case ROOK: {
            legal_moves = find_rook_moves(board, from_x, from_y, piece.color);
            break;
        }
        case KNIGHT: {
            legal_moves = find_knight_moves(board, from_x, from_y, piece.color);
            break;
        }
        case BISHOP: {
            legal_moves = find_bishop_moves(board, from_x, from_y, piece.color);
            break;
        }
        case QUEEN: {
            legal_moves = find_queen_moves(board, from_x, from_y, piece.color);
            break;
        }
        case KING: {
            legal_moves = find_king_moves(board, from_x, from_y, piece.color);
            break;
        }
        default: {
            return false;
        }
    }
    if(legal_moves.empty())
        return false;
    cout << "Legal moves: ";
    for (const auto& move : legal_moves){
        cout << "(" << move.first << ", " << move.second << ") ";
    }
    cout << "\n";
    cout << "Select a move (0-" << legal_moves.size()-1 << "): ";
    cin >> go;
    if (go >= legal_moves.size())
        return false;
    board[from_x][from_y] = {EMPTY, BLANK};
    board[legal_moves[go].first][legal_moves[go].second] = piece;

    return true;
}


int main() {
    ChessBoard board = {
            {{ROOK,   WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE},{KING,  WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK,   WHITE}},
            {{PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,  WHITE}, {PAWN,  WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}},
            {{EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY, BLANK}, {EMPTY, BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}},
            {{EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY, BLANK}, {EMPTY, BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}},
            {{EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY, BLANK}, {EMPTY, BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}},
            {{EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY, BLANK}, {EMPTY, BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}},
            {{PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,  BLACK}, {PAWN,  BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}},
            {{ROOK,   BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK}, {KING,  BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK,   BLACK}}
    };

    print_board(board);
    Color col = WHITE;
    cout << "-- -1 -1 input is game end --\n";
    while (true) {
        int from_x, from_y;
        std::cout << "Select your piece (x y): ";
        std::cin >> from_x >> from_y;
        std::cin.ignore();
        if (from_x == -1 && from_y == -1) break;
        if ( col == board[from_x][from_y].color)
        {
            std::cout << "not your turn!\n";
            continue;
        }

        if (!make_move(board, from_x, from_y)) {
            std::cout << "Illegal move!\n";
            continue;
        }
        col = board[from_x][from_y].color;

        print_board(board);
        if (who_is_win(board)){
            cout << "you win!!\n";
            break;
        }
    }
    cout << "game end!" << endl;

    return 0;
}