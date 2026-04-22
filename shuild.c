#define SHUILD_IMPLEMENTATION
#define SHUC_ENABLE_INCREMENTAL
#define SHUC_NO_RUN_LOG
#define SHUC_SHORT_LOG
#include "dependencies/shuild/shuild.h"

int main(int argc, char **argv)
{
    SHU_CompilerTryConfigure("gcc");
    SHU_UtilAutomate(argc, argv);

    SHU_ModuleBegin("Chess-CLI", NULL);
    SHU_ModuleAddSourceFile("src/");
    SHU_ModuleAddIncludeDirectory("include/");
    SHU_ModuleCompile("build/", SHUM_MODULE_EXECUTABLE);

    return 0;
}
