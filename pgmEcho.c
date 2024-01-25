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
/* argv[1]: input file name        */
/* argv[2]: output file name       */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

int main(int argc, char **argv) 
{ /* main() */

	/* check for correct number of arguments */
	if (argc == 1) 
	{ /* no arguments  */
		/* print a usage message */
		printf("Usage: %s inputImage.pgm outputImage.pgm\n", argv[0]);
		/* and return 0 */
		return 0;
	} /* no arguments  */
	else if (argc != 3) 
	{ /* wrong arg count */
		/* print an error message */
		printf("ERROR: Bad Argument Count\n");
		/* and return 0 */
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

	/* Check if pgm file is ASCII or Binary */
	int type = fileType(argv[1], file);

	if (type == 0 || type == 1) 
	{ /* file type is valid */
		/* echo the file and return the error code */
		return echoFile (type, file, argv[1], argv[2]);
	} /* file type is valid */

	/* free memory */
	cleanUp(file);
	/* return error code */
	return error(argv[1], type);

} /* main() */
