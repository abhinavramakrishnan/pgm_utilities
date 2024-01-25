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
/* argv[1]: first input file name  */
/* argv[2]: second input file name */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

int main(int argc, char **argv) 
{ /* main() */

	//////////////// check number of arguments ////////////////
	if (argc == 1) 
	{ /* no arguments  */
		/* print a usage message        */
		printf("Usage: %s inputImage.pgm inputImage.pgm\n", argv[0]);
		/* and return 0      */
		return 0;
	} /* no arguments  */

	else if (argc != 3) 
	{ /* wrong arg count */
		/* print an error message        */
		printf("ERROR: Bad Argument Count\n");
		/* and return 0      */
		return EXIT_BAD_ARGUMENT_COUNT;
	} /* wrong arg count */

	//////////////// Initialising ////////////////
	/* Create two pgm file structure  to store each file */
	pgmFile *file1 = (pgmFile *) malloc(sizeof(pgmFile));
    pgmFile *file2 = (pgmFile *) malloc(sizeof(pgmFile));

	if (file1 == NULL) 
	{ /* malloc failed */
		printf("ERROR: Image Malloc Failed\n");
		/* free memory */
		free(file1);
		/* and return error code */
		return EXIT_IMAGE_MALLOC_FAILED;
	} /* malloc failed */

	if (file2 == NULL) 
	{ /* malloc failed */
		printf("ERROR: Image Malloc Failed\n");
		/* free memory */
		free(file2);
		/* and return error code */
		return EXIT_IMAGE_MALLOC_FAILED;
	} /* malloc failed */

	/* Initialise values in the pgm file structures */
	initialise(file1);
    initialise(file2);

	/*Check the file types of both files */
	int file1Type = fileType(argv[1], file1);
	int file2Type = fileType(argv[2], file2);

	/////////////////// Read File 1 ///////////////////
	if (file1Type == 0) 
	{ /* file 1 is ASCII */
		/* Read from pgm file */
		int fileReadReturn = readASCII(argv[1], file1);
		if (fileReadReturn != 0) 
		{ /* read failed */
			/* free memory */
			cleanUp(file1);
			/* and return error code */
			return error(argv[1], fileReadReturn);
		} /* read failed */
	}/* file 1 is ASCII */

	else if (file1Type == 1) 
	{ /* file 1 is binary */
		/* Read from pgm file */
		int fileReadReturn = readBinary(argv[1], file1);
		if (fileReadReturn != 0) 
		{ /* read failed */
			/* free memory */
			cleanUp(file1);
			/* and return error code */
			return error(argv[1], fileReadReturn);
		} /* read failed */
	} /* file 1 is binary */

	else 
	{ /* invalid file type */
		cleanUp(file1);
		return error(argv[1], file1Type);
	} /* invalid file type */

	/////////////////// Read File 2 ///////////////////
	if (file2Type == 0) 
	{ /* file 2 is ASCII */
		/* Read from pgm file */
		int fileReadReturn = readASCII(argv[2], file2);
		if (fileReadReturn != 0) 
		{ /* read failed */
			/* free memory */
			cleanUp(file2);
			/* and return error code */
			return error(argv[2], fileReadReturn);
		} /* read failed */
	}/* file 2 is ASCII */

	else if (file2Type == 1) 
	{ /* file 2 is binary */
		/* Read from pgm file */
		int fileReadReturn = readBinary(argv[2], file2);
		if (fileReadReturn != 0) 
		{ /* read failed */
			/* free memory */
			cleanUp(file2);
			/* and return error code */
			return error(argv[2], fileReadReturn);
		} /* read failed */
	} /* file 2 is binary */

	else 
	{ /* invalid file type */
		cleanUp(file2);
		return error(argv[2], file2Type);
	} /* invalid file type */

	//////////////// Compare both files  ////////////////
	/* check if files are loggicaly equal */
	int equal = logicallyEqual(file1, file2);

	if (equal) 
	{ /* files are different */
		printf("DIFFERENT\n");
		/* free memory */
		cleanUp(file1);
		cleanUp(file2);
		/* and return success code */
		return EXIT_NO_ERRORS;
	} /* files are different */

	else if (!equal) 
	{ /* files are logically identical */
		printf("IDENTICAL\n");
		/* free memory */
		cleanUp(file1);
		cleanUp(file2);
		/* and return success code */
		return EXIT_NO_ERRORS;
	} /* files are logically identical */

} /* main() */
