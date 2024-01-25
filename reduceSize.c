/* structs for different file types */
#include "fileStructures.h"
/* library for constants and error codes */
#include "constantsAndCodes.h"

int reduceSize(pgmFile* file, int factor) 
{ /* reduceSize() */

    int counter = 0;
    /* loop through the array to see which elements should be kept acording to the reduction factor */
	for (int i=0; i<file->width; i++) 
    {
        for (int j=0; j<file->height; j++) 
        {
            /* check if this elemt should be kept */
            if (i%factor==0 && j%factor==0) 
            { /* elemetn should be kept */
                file->buffer[counter] = file->imageDataArray[i][j];
                counter++;
            } /* elemetn should be kept */
            else
            { /* next element */
                continue;
            } /* next element */
        }
    }

    /* reduce the diemsnions of the file */
    file->height = (file->height / factor) + (file->height % factor > 0);
    file->width = (file->width / factor) + (file->width % factor > 0);

    /* transfer data from the buffer to the array */
    counter = 0;
	for (int i=0; i<file->width; i++) 
    {
        for (int j=0; j<file->height; j++) 
        {
            file->imageDataArray[i][j] = file->buffer[counter];
            counter++;
        }
    }

    /* return success code */
    return EXIT_NO_ERRORS;

} /* reduceSize() */