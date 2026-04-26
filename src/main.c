#include "shunei/shunei.h"
#include "Renderer.h"

int main(int argc, char **argv)
{
    renderBoard();

    if (argc < 2)
    {
        goto usageErr;
    }

    switch (argv[1][0])
    {
    case 'h':
    case 'c':
        break;
    default:
        goto usageErr;
    }

    // char mode = argv[1][0];

    SHU_InitializeNetwork();

    renderMove((ChessMove){
        .piece = ChessPiece_WKnight,
        .fromRow = 0,
        .fromColumn = 1,
        .toRow = 2,
        .toColumn = 2,
    });

    waitKey();

    SHU_TerminateNetwork();
    return 0;

usageErr:
    renderNotification("Usage is: ./Chess-CLI <h/c>(mode, host/client)");
    waitKey();
    return 1;
}
