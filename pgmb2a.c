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
/* argv[1]: Binary file name       */
/* argv[2]: ASCII file name        */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

int main(int argc, char **argv) 
{ /* main() */

	/* check for correct number of arguments */
	if (argc == 1) 
	{ /* no arguments */
		/* print a usage message        */
		printf("Usage: %s inputImage.pgm outputImage.pgm\n", argv[0]);
		/* and return 0      */
		return 0;
	} /* no arguments */

	else if (argc != 3) 
	{ /* wrong arg count  */
		/* print an error message        */
		printf("ERROR: Bad Argument Count\n");
		/* and return 0  */
		return EXIT_BAD_ARGUMENT_COUNT;
	} /* wrong arg count  */

    /* Create a pgm file structure */
	pgmFile *file = (pgmFile *) malloc(sizeof(pgmFile));

	if (file == NULL) 
	{ /* malloc failed */
		printf("ERROR: Image Malloc Failed\n");
		/* free memory */
		free(file);
		/* and return error code */
		return EXIT_IMAGE_MALLOC_FAILED;
	} /* malloc failed */

	/* Initialise values in the pgm file structure */
	initialise(file);

	/* Read from pgm Binary file */
	int fileReadReturn = readBinary(argv[1], file);
	if (fileReadReturn != 0) 
	{ /* read failed */
		/* free memory */
		cleanUp(file);
		/* and return error code */
		return error(argv[1], fileReadReturn);
	} /* read failed */

	/* Write to pgm ASCII file */
	int fileWriteReturn = writeASCII(argv[2], file);
	if (fileWriteReturn != 0) 
	{ /* write failed */
		/* free memory */
		cleanUp(file);
		/* and return error code */
		return error(argv[2], fileWriteReturn);
	} /* write failed */

	/* Check if writing and reading was succesful */
	if (fileReadReturn == 0 && fileWriteReturn == 0) 
	{ /* conversion was succesful */
		/* print an success message        */
		printf("CONVERTED\n");
		/* print an success code        */
		return EXIT_NO_ERRORS;
	} /* conversion was succesful */
	
	/* free memory */
	cleanUp(file);
	/* exit with a success code */
	return EXIT_NO_ERRORS;
}