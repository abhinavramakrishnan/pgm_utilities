/* library for I/O routines */
#include <stdio.h>
/* library for memory routines */
#include <stdlib.h>
/* structs for different file types */
#include "fileStructures.h"
/* library for constants and error codes */
#include "constantsAndCodes.h"

/****************************************/
/* Parameters:	                        */
/* 1: Pointer to the first file struct  */
/* 2: Pointer to the second file struct */
/* returns 0 on success                 */
/* returns 1 on fail                    */
/****************************************/

int logicallyEqual(pgmFile* filename1, pgmFile* filename2) 
{ /* logicallyEqual() */

    /* check if the dimensions of both the files are the same */
    if (filename1->height != filename2->height || filename1->width != filename2->width) 
    { /* dimensions are different */
        /* return error code */
        return 1;
    } /* dimensions are different */

    /* check if the data of both the files are the same */
    for (int i=0; i<filename1->width; i++) 
    { /* data is different */
        for (int j=0; j<filename1->height; j++) {
            if (filename1->imageDataArray[i][j] != filename2->imageDataArray[i][j]) 
            { /* data doesn't match */
                /* return error code */
                return 1;
            } /* data doesn't match */
        }
    } /* data is different */

    /* return succes code */
    return 0;

} /* logicallyEqual() */