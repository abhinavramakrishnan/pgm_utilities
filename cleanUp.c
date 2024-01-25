/* library for memory routines */
#include <stdlib.h>
/* structs for different file types */
#include "fileStructures.h"

void cleanUp (pgmFile* file) 
{ /* cleanUp() */ 
    free(file->commentLine);
    free(file->imageData);
    free(file);
} /* cleanUp() */