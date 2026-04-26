#pragma once
#include "common.h"

// initialize
void renderBoard(void);

void renderMove(ChessMove move);

// dont use special escape sequences like \n, \t etc.
void renderNotification(const char *message);

void waitKey(void);
