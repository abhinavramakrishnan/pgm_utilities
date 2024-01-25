/* library for I/O routines */
#include <stdio.h>
/* library for memory routines */
#include <stdlib.h>
/* structs for different file types */
#include "fileStructures.h"
/* library for constants and error codes */

void initialise(pgmFile* file) 
{ /* initialse() */

    /* the magic number stored as two bytes to avoid problems with endianness */
    /* Raw:    0x5035 or P5		         */
    /* ASCII:  0x5032 or P2		         */
    file->magic_number[0] = '0';
    file->magic_number[1] = '0';
    file->magic_Number = (unsigned short *) file->magic_number;

    /* we will store ONE comment	         */
    file->commentLine = NULL;

    /* the logical width & height	         */
    file->width = 0;
    file->height = 0;

    /* maximum gray value (assumed)	         */
    file->maxGray = 255;

    /* pointer to raw image data	         */
    file->imageData = NULL;

} /* initialse() */