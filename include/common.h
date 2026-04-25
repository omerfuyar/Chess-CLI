#pragma once

#define BOARD_HORIZONTAL_BORDER '-'
#define BOARD_VERTICAL_BORDER '|'

// borders inclusive
#define NOTIFICATION_WIDTH 17
#define NOTIFICATION_HEIGHT 5

#define CELL_WIDTH 3
#define CELL_HEIGHT 1

#define BOARD_WIDTH ((8 * CELL_WIDTH) + 9)
#define BOARD_HEIGHT ((8 * CELL_HEIGHT) + 9)

#define PIECE_NONE ' '
#define PIECE_PAWN "♙"
#define PIECE_KNIGHT "♘"
#define PIECE_BISHOP "♗"
#define PIECE_ROOK "♖"
#define PIECE_QUEEN "♕"
#define PIECE_KING "♔"

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