#include "Renderer.h"
#include "shucio/shucio.h"

void renderBoard()
{
    SHU_InitializeConsole();
    SHU_CursorSetVisibility(0);
    SHU_TerminalSetAlternate(1);
}

void renderMove(ChessMove move)
{
    (void)move;
}

void renderNotification(const char *message)
{
    SHU_TerminalPutString(message);
}
