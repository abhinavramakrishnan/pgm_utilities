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
/* argv[1]: reduction factor       */
/* argv[3]: output file name       */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

int main(int argc, char **argv) 
{ /* main() */

    /* check for correct number of arguments */
	if (argc == 1) 
	{ /* no arguments  */
		/* print a usage message        */
		printf("Usage: %s inputImage.pgm reduction_factor outputImage.pgm\n", argv[0]);
		/* and return 0      */
		return 0;
	} /* no arguments  */

	else if (argc != 4) 
	{ /* wrong number of arguments */
		/* print an error message        */
		printf("ERROR: Bad Argument Count\n");
		/* and return 0      */
		return EXIT_BAD_ARGUMENT_COUNT;
	} /* wrong number of arguments */

	/* Turn the second argument into the reduction factor */
    int factor = atoi(argv[2]);

	if ((factor == 0) || factor < 0) 
	{ /* invalid reduction facotor */
		/* print an error message        */
		printf("ERROR: Miscellaneous (Invalid reduction factor)\n");
		/* and return 0      */
		return EXIT_MISCELLANEOUS;
	} /* invalid reduction facotor */

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

    /* Check the file type */
    int type = fileType(argv[1], file);
	if(type == 0) 
	{ /* file is ascii */
        /* Read from pgm file */
		int fileReadReturn = readASCII(argv[1], file);
		if (fileReadReturn != 0) 
		{ /* read failed */
			/* free memory */
			cleanUp(file);
			/* and return error code */
			return error(argv[1], fileReadReturn);
		} /* read failed */

        /* Reduce the data size*/
        reduceSize(file, factor);

		/* Wrtie to pgm file */
		int fileWriteReturn = writeASCII(argv[3], file);
		if (fileWriteReturn != 0) 
		{ /* write failed */
			/* free memory */
			cleanUp(file);
			/* and return error code */
			return error(argv[3], fileWriteReturn);
		} /* write failed */

        if (fileReadReturn == 0 && fileWriteReturn == 0) 
		{ /* reduction was succeful */
			/* print a success message        */
			printf("REDUCED\n");
			/* print an success code        */
			return EXIT_NO_ERRORS;
		} /* reduction was succeful */
	}/* file is ascii */

	else if(type == 1) 
	{ /* file is binary */
        /* Read from pgm file */
		int fileReadReturn = readBinary(argv[1], file);
		if (fileReadReturn != 0) 
		{ /* read failed */
			/* free memory */
			cleanUp(file);
			/* and return error code */
			return error(argv[1], fileReadReturn);
		} /* read failed */

        /* Reduce the data size*/
        reduceSize(file, factor);

		/* Wrtie to pgm file */
		int fileWriteReturn = writeBinary(argv[3], file);
		if (fileWriteReturn != 0) 
		{ /* write failed */
			/* free memory */
			cleanUp(file);
			/* and return error code */
			return error(argv[3], fileWriteReturn);
		} /* write failed */

        if (fileReadReturn == 0 && fileWriteReturn == 0) 
		{ /* reduction was succeful */
			/* print a success message        */
			printf("REDUCED\n");
			/* print an success code        */
			return EXIT_NO_ERRORS;
		} /* reduction was succeful */
	}/* file is binary */

	/* If an error occurs */
	else {
		cleanUp(file);
		return error(argv[1], type);
	}

	/* exit with a success code */
	cleanUp(file);
	return EXIT_NO_ERRORS;

} /* main() */

