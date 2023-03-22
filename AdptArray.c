#include "AdptArray.h"
#include <stdio.h>
#include <stdlib.h>

struct AdptArray_ {
    PElement *elementArray;
    int size;
    PRINT_FUNC printFun;
    COPY_FUNC copyFun;
    DEL_FUNC deleteFun;
};

