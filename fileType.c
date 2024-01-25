/* library for I/O routines        */
#include <stdio.h>
/* library for memory routines     */
#include <stdlib.h>
/* structs for different file types */
#include "fileStructures.h"
/* library for constants and error codes */
#include "constantsAndCodes.h"

int fileType(char* filename, pgmFile* file) 
{ /* fileType() */

	/* open the file for text I/O in ASCII mode b/c the header is text  */
	FILE *inputFile = fopen(filename, "r");

	/* check file */
	if (inputFile == NULL) 
	{ /* opening file fails */
		return EXIT_BAD_FILE_NAME;
	} /* opening file fails */

	/* read in the magic number              */
	file->magic_number[0] = getc(inputFile);
	file->magic_number[1] = getc(inputFile);

	/* check on the magic number      */
	if (*file->magic_Number == MAGIC_NUMBER_ASCII_PGM) 
	{ /* file is ascii */
		/* close the file */
		fclose(inputFile);
		/* and return */
		return 0;
	} /* file is ascii */

    else if (*file->magic_Number == MAGIC_NUMBER_RAW_PGM) 
	{ /* file is binary */
        /* close the file */
		fclose(inputFile);
		/* and return  */
		return 1;
    } /* file is binary */

	/* if magic number is invalid */
	/* close the file */
    fclose(inputFile);
	/* and return an error code */
    return EXIT_BAD_MAGIC_NUMBER;

} /* fileType() */