#include "Renderer.h"
#include "shucio/shucio.h"
#include <string.h>

#define BORDER_ATTRIBUTES SHUAttribute_ColorBGBlack
#define BORDER_NUMBER_ATTRIBUTES SHUAttribute_ColorBGBlack, SHUAttribute_ColorFGCyan

#define CELL_WHITE_ATTRIBUTES SHUAttribute_ColorBGWhite
#define CELL_BLACK_ATTRIBUTES SHUAttribute_ColorBrightBGBlack

#define PIECE_WHITE_ATTRIBUTES SHUAttribute_ColorFGRed
#define PIECE_BLACK_ATTRIBUTES SHUAttribute_ColorFGBlue

#define NOTIFICATION_ATTRIBUTES SHUAttribute_ColorBGBlack, SHUAttribute_ColorBrightFGCyan

static char *PIECES[] = {PIECE_NONE, PIECE_PAWN, PIECE_KNIGHT, PIECE_BISHOP, PIECE_ROOK, PIECE_QUEEN, PIECE_KING};

void renderBoard()
{
    SHU_InitializeConsole();
    SHU_CursorSetVisibility(0);
    SHU_TerminalSetAlternate(1);

    // board
    SHU_TerminalSetAttributes(SHUAttribute_Reset);
    SHU_TerminalSetAttributes(BORDER_ATTRIBUTES);

    for (int y = 0; y < 8; y++)
    {
        SHU_CursorSetPosition(0, y * (CELL_HEIGHT + 1));

        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            SHU_TerminalSetAttributes(SHUAttribute_Reset);
            SHU_TerminalSetAttributes(BORDER_ATTRIBUTES);
            SHU_TerminalPutCharacter(x % (CELL_WIDTH + 1) == 0 ? BOARD_INTERSECTION_BORDER : BOARD_HORIZONTAL_BORDER);
        }

        for (int r = 0; r < CELL_HEIGHT; r++)
        {
            int rowPos = 1 + y * (CELL_HEIGHT + 1) + r;
            SHU_CursorSetPosition(0, rowPos);

            SHU_TerminalSetAttributes(SHUAttribute_Reset);
            SHU_TerminalSetAttributes(BORDER_NUMBER_ATTRIBUTES);
            SHU_TerminalPutCharacter(49 + 7 - y);

            for (int x = 0; x < 8; x++)
            {
                SHU_TerminalSetAttributes(SHUAttribute_Reset);
                SHU_TerminalSetAttributes((x + y) % 2 == 0 ? CELL_WHITE_ATTRIBUTES : CELL_BLACK_ATTRIBUTES);

                for (int c = 0; c < CELL_WIDTH; c++)
                {
                    SHU_TerminalPutCharacter(*PIECE_NONE);
                }

                SHU_TerminalSetAttributes(SHUAttribute_Reset);
                SHU_TerminalSetAttributes(BORDER_ATTRIBUTES);
                SHU_TerminalPutCharacter(BOARD_VERTICAL_BORDER);
            }
        }
    }

    SHU_CursorSetPosition(0, BOARD_HEIGHT - 1);
    for (int x = 0; x < 8; x++)
    {
        SHU_TerminalSetAttributes(SHUAttribute_Reset);
        SHU_TerminalSetAttributes(BORDER_ATTRIBUTES);
        SHU_TerminalPutCharacter(BOARD_INTERSECTION_BORDER);

        for (int c = 0; c < CELL_WIDTH; c++)
        {
            if (c == CELL_WIDTH / 2)
            {
                SHU_TerminalSetAttributes(SHUAttribute_Reset);
                SHU_TerminalSetAttributes(BORDER_NUMBER_ATTRIBUTES);
                SHU_TerminalPutCharacter(97 + x);
            }
            else
            {
                SHU_TerminalSetAttributes(SHUAttribute_Reset);
                SHU_TerminalSetAttributes(BORDER_ATTRIBUTES);
                SHU_TerminalPutCharacter(BOARD_HORIZONTAL_BORDER);
            }
        }
    }

    SHU_TerminalSetAttributes(SHUAttribute_Reset);
    SHU_TerminalSetAttributes(BORDER_ATTRIBUTES);
    SHU_TerminalPutCharacter(BOARD_INTERSECTION_BORDER);

    // notification
    SHU_TerminalSetAttributes(SHUAttribute_Reset);
    SHU_TerminalSetAttributes(BORDER_ATTRIBUTES);
    for (int y = 0; y < NOTIFICATION_HEIGHT - 1; y++)
    {
        SHU_CursorSetPosition(0, BOARD_HEIGHT + y);
        SHU_TerminalPutCharacter(BOARD_VERTICAL_BORDER);
        SHU_CursorSetPosition(NOTIFICATION_WIDTH - 1, BOARD_HEIGHT + y);
        SHU_TerminalPutCharacter(BOARD_VERTICAL_BORDER);
    }

    SHU_CursorSetPosition(0, BOARD_HEIGHT + NOTIFICATION_HEIGHT - 1);
    SHU_TerminalPutCharacter(BOARD_INTERSECTION_BORDER);

    for (int x = 1; x < NOTIFICATION_WIDTH - 1; x++)
    {
        SHU_TerminalPutCharacter(BOARD_HORIZONTAL_BORDER);
    }

    SHU_CursorSetPosition(NOTIFICATION_WIDTH - 1, BOARD_HEIGHT + NOTIFICATION_HEIGHT - 1);
    SHU_TerminalPutCharacter(BOARD_INTERSECTION_BORDER);
}

void renderMove(ChessMove move)
{ // todo
    int toX = move.toColumn * (CELL_WIDTH + 1) + (CELL_WIDTH / 2);
    int toY = move.toRow * (CELL_HEIGHT + 1) + (CELL_HEIGHT / 2);

    SHU_TerminalSetAttributes(SHUAttribute_Reset);
    SHU_TerminalSetAttributes(move.piece <= ChessPiece_WKing ? PIECE_WHITE_ATTRIBUTES : PIECE_BLACK_ATTRIBUTES);
    SHU_CursorSetPosition(toX, toY);
    SHU_TerminalPutString("%s", PIECES[move.piece <= ChessPiece_WKing ? move.piece : move.piece - ChessPiece_BPawn + ChessPiece_WPawn]);
}

void renderNotification(const char *message)
{
    SHU_TerminalSetAttributes(SHUAttribute_Reset);
    for (int y = 0; y < NOTIFICATION_HEIGHT - 1; y++)
    {
        SHU_CursorSetPosition(1, BOARD_HEIGHT + y);

        for (int x = 0; x < NOTIFICATION_WIDTH - 2; x++)
        {
            SHU_TerminalPutCharacter(' ');
        }
    }

    int textLength = (int)strnlen(message, NOTIFICATION_MAX_LENGTH);
    int textIndex = 0;

    SHU_TerminalSetAttributes(NOTIFICATION_ATTRIBUTES);
    while (textIndex < textLength)
    {
        SHU_CursorSetPosition(1, BOARD_HEIGHT + (textIndex / (NOTIFICATION_WIDTH - 2)));
        textIndex += SHU_TerminalPutString("%.*s", NOTIFICATION_WIDTH - 2, message + textIndex);
    }
}

void waitKey(void)
{
    SHU_InputKey();
}
