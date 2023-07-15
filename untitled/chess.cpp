#include <algorithm>
#include "chess.h"


void print_board(ChessBoard const board){
    cout << " ";
    for (int i=0;i<BOARD_SIZE;i++)
        cout << " " << i << " ";
    cout << "\n";
    for (int row =0; row < BOARD_SIZE; row++){
        cout << row << " ";
        for (int col=0;col < BOARD_SIZE; col++){
            if (board[row][col].piece == EMPTY)
                cout << "  " <<" ";
            else if (board[row][col].piece == PAWN && board[row][col].color == WHITE)
                cout << "Pw"  <<" ";
            else if (board[row][col].piece == ROOK && board[row][col].color == WHITE)
                cout << "Rw" <<" ";
            else if (board[row][col].piece == KNIGHT && board[row][col].color == WHITE)
                cout << "Nw" <<" ";
            else if (board[row][col].piece == BISHOP && board[row][col].color == WHITE)
                cout << "Bw" <<" ";
            else if (board[row][col].piece == QUEEN && board[row][col].color == WHITE)
                cout << "Qw" <<" ";
            else if (board[row][col].piece == KING && board[row][col].color == WHITE)
                cout << "Kw" <<" ";
            else if (board[row][col].piece == PAWN && board[row][col].color == BLACK)
                cout << "Pb"  <<" ";
            else if (board[row][col].piece == ROOK && board[row][col].color == BLACK)
                cout << "Rb" <<" ";
            else if (board[row][col].piece == KNIGHT && board[row][col].color == BLACK)
                cout << "Nb" <<" ";
            else if (board[row][col].piece == BISHOP && board[row][col].color == BLACK)
                cout << "Bb" <<" ";
            else if (board[row][col].piece == QUEEN && board[row][col].color == BLACK)
                cout << "Qb" <<" ";
            else if (board[row][col].piece == KING && board[row][col].color == BLACK)
                cout << "Kb" <<" ";
        }
        cout << "\n";
    }
}
vector<pair<int,int>> find_bishop_moves(ChessBoard board, int x, int y, Color color){
    vector<pair<int,int>> legal_moves;

    for (int i=1; x- i >= 0 && y - i >= 0; i++){
        if (board[x - i][y - i].piece == EMPTY){
            legal_moves.push_back(make_pair(x-i,y-i));
        }else{
            if (board[x-i][y-i].color != color){
                legal_moves.push_back(make_pair(x-i,y-i));
            }
            break;
        }
    }

    for (int i=1; x- i >= 0 && y + i < BOARD_SIZE; i++){
        if (board[x - i][y + i].piece == EMPTY){
            legal_moves.push_back(make_pair(x-i,y+i));
        }else{
            if (board[x-i][y+i].color != color){
                legal_moves.push_back(make_pair(x-i,y+i));
            }
            break;
        }
    }
    for (int i=1; x + i < BOARD_SIZE && y - i >= 0; i++){
        if (board[x + i][y - i].piece == EMPTY){
            legal_moves.push_back(make_pair(x+i,y-i));
        }else{
            if (board[x+i][y-i].color != color){
                legal_moves.push_back(make_pair(x+i,y-i));
            }
            break;
        }
    }
    for (int i=1; x + i < BOARD_SIZE && y + i < BOARD_SIZE; i++){
        if (board[x + i][y + i].piece == EMPTY){
            legal_moves.push_back(make_pair(x+i,y+i));
        }else{
            if (board[x+i][y+i].color != color){
                legal_moves.push_back(make_pair(x+i,y+i));
            }
            break;
        }
    }
    std::sort(legal_moves.begin(),legal_moves.end());
    return legal_moves;
}
vector<pair<int,int>> find_knight_moves(ChessBoard board, int x, int y, Color color){
   vector<pair<int,int>> legal_moves;

   int dx[] = {-2,-1,1,2,-2,-1,1,2};
   int dy[] = {-1,-2,-2,-1,1,2,2,1};
   for (int i=0;i<8;i++){
       int nx = x + dx[i];
       int ny = y + dy[i];
       if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE){
           if (board[nx][ny].piece == EMPTY || board[nx][ny].color != color){
               legal_moves.push_back(make_pair(nx,ny));
           }
       }
   }
   std::sort(legal_moves.begin(),legal_moves.end());
   return legal_moves;
}
vector<pair<int,int>> find_pawn_moves(ChessBoard board, int x, int y, Color color){
    vector<pair<int,int>> legal_moves;
    int direction = (color == WHITE) ? 1 : -1;
    int nx = x + direction;
    if (nx >= 0 && nx < BOARD_SIZE && board[nx][y].piece == EMPTY){
        legal_moves.push_back(make_pair(nx,y));
    }

    if ((color == BLACK && x == 6) || (color == WHITE && x == 1)){
        int nx2 = x + 2 * direction;
        if (nx2 >= 0 && nx2 < BOARD_SIZE && board[nx2][y].piece == EMPTY){
            legal_moves.push_back(make_pair(nx2, y));
        }
    }
    int directions[] = {-1,1};
    for (int i=0;i<2;i++){
        int ny = y + directions[i];
        if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE) {
            if (board[nx][ny].piece != EMPTY && board[nx][ny].color!=color){
                legal_moves.push_back(make_pair(nx,ny));
            }
        }
    }

    return legal_moves;
}
vector<pair<int,int>> find_rook_moves(ChessBoard board, int x, int y, Color color){
    vector<pair<int,int>> legal_moves;

    for(int i=x-1;i>=0;i--){
        if (board[i][y].piece == EMPTY){
            legal_moves.push_back(make_pair(i,y));
        } else{
            if (board[i][y].color != color){
                legal_moves.push_back(make_pair(i,y));
            }
            break;
        }
    }
    for (int i=x+1;i<BOARD_SIZE;i++){
        if (board[i][y].piece == EMPTY){
            legal_moves.push_back(make_pair(i,y));
        }else{
            if (board[i][y].color != color){
                legal_moves.push_back(make_pair(i,y));
            }
            break;
        }
    }
    for (int j=y-1;j>=0;j--){
        if (board[x][j].piece == EMPTY){
            legal_moves.push_back(make_pair(x,j));
        }else{
            if (board[x][j].color != color){
                legal_moves.push_back(make_pair(x,j));
            }
            break;
        }
    }
    for (int j = y + 1;j<BOARD_SIZE;j++){
        if (board[x][j].piece == EMPTY){
            legal_moves.push_back(make_pair(x,j));
        } else{
            if ( board[x][j].color != color){
                legal_moves.push_back(make_pair(x,j));
            }
            break;
        }
    }
    std::sort(legal_moves.begin(),legal_moves.end());
    return legal_moves;
}
vector<pair<int,int>> find_king_moves(ChessBoard board, int x, int y, Color color){
    vector<pair<int,int>> legal_moves;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE){
            if (board[nx][ny].piece == EMPTY || board[nx][ny].color != color){
                legal_moves.push_back(make_pair(nx, ny));
            }
        }
    }
    return legal_moves;
}

vector<pair<int,int>> find_queen_moves(ChessBoard board, int x, int y, Color color){
    vector<pair<int,int>> legal_moves;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++){
        for (int j = 1; j < BOARD_SIZE; j++){
            int nx = x + j * dx[i];
            int ny = y + j * dy[i];
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE){
                if (board[nx][ny].piece == EMPTY){
                    legal_moves.push_back(make_pair(nx, ny));
                } else{
                    if (board[nx][ny].color != color){
                        legal_moves.push_back(make_pair(nx, ny));
                    }
                    break;
                }
            } else{
                break;
            }
        }
    }
    return legal_moves;
}
bool who_is_win(ChessBoard board){
    int cnt = 0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[i][j].piece == KING){
                cnt ++;
            }
        }
    }
    if (cnt < 2)
        return true;
    else
        return false;
}