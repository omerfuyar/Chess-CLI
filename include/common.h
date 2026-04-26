#pragma once

#define BOARD_HORIZONTAL_BORDER '-'
#define BOARD_VERTICAL_BORDER '|'
#define BOARD_INTERSECTION_BORDER '+'

#define CELL_WIDTH 3
#define CELL_HEIGHT 1

#define BOARD_WIDTH ((8 * CELL_WIDTH) + 9)
#define BOARD_HEIGHT ((8 * CELL_HEIGHT) + 9)

#define NOTIFICATION_WIDTH BOARD_WIDTH // 2 borders
#define NOTIFICATION_HEIGHT 5          // 1 bottom border
#define NOTIFICATION_MAX_LENGTH ((NOTIFICATION_WIDTH - 2) * (NOTIFICATION_HEIGHT - 2))

#define PIECE_NONE " "
#define PIECE_PAWN "♟"
#define PIECE_KNIGHT "♞"
#define PIECE_BISHOP "♝"
#define PIECE_ROOK "♜"
#define PIECE_QUEEN "♛"
#define PIECE_KING "♚"

typedef enum ChessPiece : unsigned char
{
    ChessPiece_None = 0,

    ChessPiece_WPawn,
    ChessPiece_WKnight,
    ChessPiece_WBishop,
    ChessPiece_WRook,
    ChessPiece_WQueen,
    ChessPiece_WKing,

    ChessPiece_BPawn,
    ChessPiece_BKnight,
    ChessPiece_BBishop,
    ChessPiece_BRook,
    ChessPiece_BQueen,
    ChessPiece_BKing
} ChessPiece;

typedef struct ChessMove
{
    ChessPiece piece;
    unsigned char fromRow;
    unsigned char fromColumn;
    unsigned char toRow;
    unsigned char toColumn;
} ChessMove;