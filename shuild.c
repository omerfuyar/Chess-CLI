#define SHUILD_IMPLEMENTATION
#define SHUC_ENABLE_INCREMENTAL
#define SHUC_NO_RUN_LOG
#define SHUC_SHORT_LOG
#include "dependencies/shuild/shuild.h"

int main(int argc, char **argv)
{
    SHU_CompilerTryConfigure("gcc");
    SHU_UtilAutomate(argc, argv);

    SHU_CompilerAddFlags(SHUM_FLAGS_STANDARD_C23 " -static -fno-stack-protector");

    if (argc > 1) // debug
    {
        SHU_CompilerAddFlags(SHUM_FLAGS_WARNING_HIGH SHUM_FLAGS_DEBUG);
        SHU_CompilerAddFlags("-Wno-missing-declarations");
        // SHU_CompilerAddFlags(SHUM_FLAGS_DEBUG SHUM_FLAGS_WARNING_ERROR " -Wno-missing-declarations -Wno-switch -Wno-format-truncation -Wno-unused-function -DDEBUG -Wno-format-nonliteral");
    }
    else // release
    {
        SHU_CompilerAddFlags(SHUM_FLAGS_OPTIMIZATION_HIGH);
    }

    SHU_ModuleBegin("Chess-CLI", NULL);
    SHU_ModuleAddSourceFile("src/");
    SHU_ModuleAddIncludeDirectory("include/");
    SHU_ModuleCompile("build/", SHUM_MODULE_EXECUTABLE);

    return 0;
}
