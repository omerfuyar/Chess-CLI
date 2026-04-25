#include "Renderer.h"
#include "shucio/shucio.h"

#define BORDER_ATTRIBUTES SHUAttribute_ColorBGBlack

#define CELL_WHITE_ATTRIBUTES SHUAttribute_ColorBGWhite
#define CELL_BLACK_ATTRIBUTES SHUAttribute_ColorBGCyan

#define PIECE_WHITE_ATTRIBUTES SHUAttribute_ColorFGWhite
#define PIECE_BLACK_ATTRIBUTES SHUAttribute_ColorFGBlack

void renderBoard()
{
    SHU_InitializeConsole();
    SHU_CursorSetVisibility(0);
    SHU_TerminalSetAlternate(1);

    SHU_TerminalSetAttributes(SHUAttribute_Reset);
    SHU_TerminalSetAttributes(BORDER_ATTRIBUTES);

    SHU_CursorSetPosition(0, 0);
    for (int x = 0; x < BOARD_WIDTH; x++)
    {
        SHU_TerminalPutCharacter(BOARD_HORIZONTAL_BORDER);
    }

    for (int y = 0; y < 8; y++)
    {
        for (int r = 0; r < CELL_HEIGHT; r++)
        {
            int rowPos = 1 + y * (CELL_HEIGHT + 1) + r;
            SHU_CursorSetPosition(0, rowPos);

            for (int x = 0; x < 8; x++)
            {
                SHU_TerminalSetAttributes(SHUAttribute_Reset);
                SHU_TerminalSetAttributes(BORDER_ATTRIBUTES);
                SHU_TerminalPutCharacter(BOARD_VERTICAL_BORDER);

                // Alternating checkerboard color
                if ((x + y) % 2 == 0)
                {
                    SHU_TerminalSetAttributes(CELL_WHITE_ATTRIBUTES); // Light square
                }
                else
                {
                    SHU_TerminalSetAttributes(CELL_BLACK_ATTRIBUTES); // Dark square
                }

                // Draw cell content
                for (int c = 0; c < CELL_WIDTH; c++)
                {
                    SHU_TerminalPutCharacter(' '); // Blank space fills the BG color
                }
            }

            // Rightmost border of the entire board for this row
            SHU_TerminalSetAttributes(SHUAttribute_Reset);
            SHU_TerminalPutCharacter(BOARD_VERTICAL_BORDER);
        }

        // Draw bottom border for the current row of cells
        int bottomBorderRow = 1 + y * (CELL_HEIGHT + 1) + CELL_HEIGHT;
        SHU_CursorSetPosition(0, bottomBorderRow);

        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            SHU_TerminalSetAttributes(SHUAttribute_Reset);
            SHU_TerminalPutCharacter(BOARD_HORIZONTAL_BORDER);
        }
    }
}

void renderMove(ChessMove move)
{
    (void)move;
}

void renderNotification(const char *message)
{
    SHU_TerminalPutString(message);
}

void waitKey(void)
{
    SHU_InputKey();
}
