/* library for I/O routines */
#include <stdio.h>
/* library for memory routines */
#include <stdlib.h>
/* structs for different file types */
#include "fileStructures.h"
/* library for constants and error codes */
#include "constantsAndCodes.h"

int writeBinary(char* filename, pgmFile* file) 
{ /* writeBinary() */

	/* open a file in binary mode for writing */
	FILE *outputFile = fopen(filename, "wb");

	/* check whether file opening worked     */
	if (outputFile == NULL) 
	{ /* NULL output file */
		/* return an error code          */
		return EXIT_OUTPUT_FAILED;
	} /* NULL output file */

	/* write magic number, size & gray value in ascii */
	size_t nBytesWritten = fprintf(outputFile, "P5\n%d %d\n%d\n", file->width, file->height, file->maxGray);

	/* check that header wrote correctly */
	if (nBytesWritten < 0) 
	{ /* header write failed    */
		/* return an error code          */
		return EXIT_OUTPUT_FAILED;
	} /* header write failed    */

	/* creat a temporary buffer to hold data before its writen to the output file */
	unsigned char outputBuffer[file->width*file->height];

	/* transfer data from the array to the buffer */
	int counter = 0;
	for (int i=0; i<file->width; i++) 
	{
		for (int j=0; j<file->height; j++) 
		{
			outputBuffer[counter] = file->imageDataArray[i][j];
			counter ++;
		}
	}

	/* write the buffer to the output file */
	fwrite(outputBuffer, sizeof(unsigned char), file->width*file->height, outputFile);

	/* close the file */
	fclose(outputFile);
	/* and return a success code */
	return EXIT_NO_ERRORS;
	
} /* writeBinary() */