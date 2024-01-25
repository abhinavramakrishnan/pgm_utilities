/* library for I/O routines */
#include <stdio.h>
/* library for memory routines */
#include <stdlib.h>
/* structs for different file types */
#include "fileStructures.h"
/* library for constants and error codes */
#include "constantsAndCodes.h"

int writeASCII(char* filename, pgmFile* file) 
{ /* writeASCII() */

	/* open a file for writing               */
	FILE *outputFile = fopen(filename, "w");

	/* check whether file opening worked     */
	if (outputFile == NULL) 
	{ /* NULL output file */
		/* return an error code          */
		return EXIT_OUTPUT_FAILED;
	} /* NULL output file */

	/* write magic number, size & gray value */
	size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", file->width, file->height, file->maxGray);

	/* check that header wrote correctly */
	if (nBytesWritten < 0) 
	{ /* header write failed    */
		/* return an error code          */
		return EXIT_OUTPUT_FAILED;
	} /* header write failed    */

	/* write the data of the pgm file */
    for (int i=0; i<file->width; i++) 
	{
		for (int j=0; j<file->height; j++) 
		{	
			/* fprint to write in ascii */
			fprintf(outputFile, "%u ", file->imageDataArray[i][j]);
		}
		fprintf(outputFile, "\n");
	}

	/* close the file */
	fclose(outputFile);
	/* and return a success code */
	return EXIT_NO_ERRORS;

} /* writeASCII() */