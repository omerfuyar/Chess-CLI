#pragma once

#define BOARD_HORIZONTAL_BORDER '-'
#define BOARD_VERTICAL_BORDER '|'

#define PIECE_P "♙"
#define PIECE_N "♘"
#define PIECE_B "♗"
#define PIECE_R "♖"
#define PIECE_Q "♕"
#define PIECE_K "♔"

typedef enum ChessPiece : char
{
    ChessPiece_None = 0,
    ChessPiece_Pawn = 'p',
    ChessPiece_Knight = 'n',
    ChessPiece_Bishop = 'b',
    ChessPiece_Rook = 'r',
    ChessPiece_Queen = 'q',
    ChessPiece_King = 'k'
} ChessPiece;

typedef struct ChessMove
{
    ChessPiece piece;
    unsigned char fromRow;
    unsigned char fromColumn;
    unsigned char toRow;
    unsigned char toColumn;
} ChessMove;