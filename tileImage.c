/* structs for different file types */
#include "fileStructures.h"
/* library for constants and error codes */
#include "constantsAndCodes.h"

void tileImage (pgmFile* file, pgmFile* tempFile, int factor, int xOffset, int yOffset) 
{ /* tileImage() */

    /* tranfer of a section of the input image specified by the x and y offset to a temp buffer */
    int counter = 0;
	for (int i=xOffset; i<xOffset + tempFile->width; i++) 
    {
        for (int j=yOffset; j<yOffset + tempFile->height; j++) 
        {
            file->buffer[counter] = file->imageDataArray[i][j];
            counter++;
        }
    }

    /* transfer the data from the buffer to the output tile */
    counter = 0;
	for (int i=0; i<tempFile->width; i++) 
    {
        for (int j=0; j<tempFile->height; j++) 
        {
            tempFile->imageDataArray[i][j] = file->buffer[counter];
            counter++;
        }
    }
    
} /* tileImage() */