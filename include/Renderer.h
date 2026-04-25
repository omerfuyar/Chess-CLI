#pragma once
#include "common.h"

// initialize
void renderBoard(void);

void renderMove(ChessMove move);

void renderNotification(const char *message);

void waitKey(void);
