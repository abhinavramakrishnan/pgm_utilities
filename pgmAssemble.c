/* library for I/O routines */
#include <stdio.h>
/* library for memory routines */
#include <stdlib.h>
/* structs for different file types */
#include "fileStructures.h"
/* library for constants and error codes */
#include "constantsAndCodes.h"
/* utilites for manupilating pgm files */
#include "pgmUtilities.h"

/***********************************/
/* Main Routine                    */
/*                                 */
/* CLI parameters:                 */
/* argv[0]: executable name        */
/* argv[1]: output file name       */
/* argv[2]: width of output file   */
/* argv[3]: height of output file  */
/* argv[i]: triples of:            */
/*			3i+1. row at which the subimage starts        */
/*			3i+2. column at which the subimage starts	  */
/*			3i+3. The subimage to insert at that location */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

int main(int argc, char **argv) 
{ /* main() */

	//////////////// check number of arguments ////////////////
	if (argc == 1) 
	{ /* no arguments */
		/* print a usage message        */
		printf("Usage: %s outputImage.pgm width height (row column inputImage.pgm)+\n", argv[0]);
		/* and return 0      */
		return 0;
	}  /* no arguments */

	else if ((argc == 4) || (argc - 4) % 3 != 0) 
	{  /* wrong number of arguments */
		/* print an error message        */
		printf("ERROR: Bad Argument Count\n");
		/* and return 0      */
		return EXIT_BAD_ARGUMENT_COUNT;
	} /* wrong number of arguments */

	/* Create a pgm file structure */
	pgmFile *assembledFile = (pgmFile *) malloc(sizeof(pgmFile));	
	if (assembledFile == NULL) 
	{ /* malloc failed */
		printf("ERROR: Image Malloc Failed\n");
		/* free memory */
		free(assembledFile);
		/* and return error code */
		return EXIT_IMAGE_MALLOC_FAILED;
	} /* malloc failed */

	pgmFile *tempFile = (pgmFile *) malloc(sizeof(pgmFile));
	if (tempFile == NULL) 
	{ /* malloc failed */
		printf("ERROR: Image Malloc Failed\n");
		/* free memory */
		free(tempFile);
		/* and return error code */
		return EXIT_IMAGE_MALLOC_FAILED;
	} /* malloc failed */

	/* Initialise values in the pgm file structure */
	initialise(assembledFile);
    initialise(tempFile);

	/* find the file type of the tiles */
	int type = fileType(argv[6], tempFile);

	/* calculate how many tiles there are */
    int repeat = 0;
    repeat = ((argc - 4) / 3);

	/* set the width and height of the output file */
	assembledFile->width = atoi(argv[2]);
    assembledFile->height = atoi(argv[3]);

	/* x and y offset when writing the file */
	int xOffset = 0;
    int yOffset = 0;

	/* variabes to keep track of when tile the program is on */
    int filenNumber = 6;
    int row = 4;
    int col = 5;

	if(type == 0) 
	{ /* file is ASCII */
		for (int i=0; i<repeat; i++) 
		{
			/* Read from pgm file */
			int fileReadReturn = readASCII(argv[filenNumber], tempFile);
			/* update offsets using the row and col */
			xOffset = atoi(argv[row]) * tempFile->width;
			yOffset = atoi(argv[col]) * tempFile->height;
			if (fileReadReturn != 0) 
			{ /* read failed */
				/* free memory */
				cleanUp(tempFile);
				cleanUp(assembledFile);
				/* and return error code */
				return error(argv[filenNumber], fileReadReturn);
			} /* read failed */

			/* Add tile to the final image */
			for (int i=xOffset, a=0; i<xOffset + tempFile->width; i++, a++) 
			{
				for (int j=yOffset, b=0; j<yOffset + tempFile->height; j++, b++) 
				{
					assembledFile->imageDataArray[i][j] = tempFile->imageDataArray[a][b];
				}
			}
			/* move to the next tile */
			filenNumber = filenNumber + 3;
			row = row + 3;
			col = col + 3;
		}

		/* Wrtie to pgm file */
		int fileWriteReturn = writeASCII(argv[1], assembledFile);
		if (fileWriteReturn != 0) 
		{ /* write failed */
			/* free memory */
			cleanUp(assembledFile);
			cleanUp(tempFile);
			/* and return error code */
			return error(argv[1], fileWriteReturn);
		} /* write failed */

		if (fileWriteReturn == 0) 
		{ /* assembling was successful */
			/* print an success message        */
			printf("ASSEMBLED\n");
			/* free memory */
			cleanUp(assembledFile);
			cleanUp(tempFile);
			/* and print an success code        */
			return EXIT_NO_ERRORS;
		} /* assembling was successful */
	} /* file is ASCII */

	if(type == 1) 
	{ /* file is binary */
		for (int i=0; i<repeat; i++) 
		{
			/* Read from pgm file */
			int fileReadReturn = readBinary(argv[filenNumber], tempFile);
			/* update offsets using the row and col */
			xOffset = atoi(argv[row]) * tempFile->width;
			yOffset = atoi(argv[col]) * tempFile->height;
			if (fileReadReturn != 0) 
			{ /* read failed */
				/* free memory */
				cleanUp(tempFile);
				cleanUp(assembledFile);
				/* and return error code */
				return error(argv[filenNumber], fileReadReturn);
			} /* read failed */

			/* Add tile to the final image */
			for (int i=xOffset, a=0; i<xOffset + tempFile->width; i++, a++) 
			{
				for (int j=yOffset, b=0; j<yOffset + tempFile->height; j++, b++) 
				{
					assembledFile->imageDataArray[i][j] = tempFile->imageDataArray[a][b];
				}
			}
			/* move to the next tile */
			filenNumber = filenNumber + 3;
			row = row + 3;
			col = col + 3;
		}

		/* Wrtie to pgm file */
		int fileWriteReturn = writeBinary(argv[1], assembledFile);
		if (fileWriteReturn != 0) 
		{ /* write failed */
			/* free memory */
			cleanUp(assembledFile);
			cleanUp(tempFile);
			/* and return error code */
			return error(argv[1], fileWriteReturn);
		} /* write failed */

		if (fileWriteReturn == 0) 
		{ /* assembling was successful */
			/* print an success message        */
			printf("ASSEMBLED\n");
			/* free memory */
			cleanUp(assembledFile);
			cleanUp(tempFile);
			/* and print an success code        */
			return EXIT_NO_ERRORS;
		} /* assembling was successful */
	} /* file is binary */

	else 
	{ /* error occurs */
		/* free memory */
		cleanUp(assembledFile);
		cleanUp(tempFile);
		return error(argv[filenNumber], type);
	} /* error occurs */

} /* main() */
