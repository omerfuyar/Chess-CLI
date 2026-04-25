#include "shunei/shunei.h"
#include "Renderer.h"

int main(int argc, char **argv)
{
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

    renderBoard();

    SHU_TerminateNetwork();
    return 0;

usageErr:
    renderNotification("Usage is:\n\tapp <h/c>(mode, host/client)");
    return 1;
}
