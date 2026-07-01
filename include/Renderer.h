#pragma once
#include "common.h"

// initialize
void renderBoard(void);

// indexed 1-8 for rows and a-h for columns directly as characters, not as integers
void renderMove(ChessMove move);

// dont use special escape sequences like \n, \t etc.
void renderNotification(const char *message);

void waitKey(void);
