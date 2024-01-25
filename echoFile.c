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
/* Parameters:	                   */
/* 1: File type (binary or ASCII)  */
/* 2: Pointer to the file struct   */
/* 3: input file name  		       */
/* 4: output file name  		   */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

int echoFile (int type, pgmFile* file, char* inputFile, char* outputFile) 
{ /* echo() */

	if(type == 0) 
	{ /* file is ASCII */
		/* read from pgm file */
		int fileReadReturn = readASCII(inputFile, file);
		if (fileReadReturn != 0) 
		{ /* read failed */
			/* free memory */
			cleanUp(file);
			/* and return error code */
			return error(inputFile, fileReadReturn);
		}/* read failed */

		/* write to pgm file */
		int fileWriteReturn = writeASCII(outputFile, file);
		if (fileWriteReturn != 0) 
		{ /* write failed */
			/* free memory */
			cleanUp(file);
			/* and return error code */
			return error(outputFile, fileWriteReturn);
		} /* write failed */

		if (fileReadReturn == 0 && fileWriteReturn == 0) 
		{ /* echo was succesful */
			/* print a success message */
			printf("ECHOED\n");
			/* and return a success code */
			return EXIT_NO_ERRORS;
		} /* echo was succesful */
	} /* file is ASCII */

	else if(type == 1) 
	{ /* file is Binary */
		/* Read from pgm file */
		int fileReadReturn = readBinary(inputFile, file);
		if (fileReadReturn != 0) 
		{ /* read failed */
			/* free memory */
			cleanUp(file);
			/* and return error code */
			return error(inputFile, fileReadReturn);
		} /* read failed */

		/* Wrtie to pgm file */
		int fileWriteReturn = writeBinary(outputFile, file);
		if (fileWriteReturn != 0) 
		{ /* write failed */
			/* free memory */
			cleanUp(file);
			/* and return error code */
			return error(outputFile, fileWriteReturn);
		} /* write failed */
		
		if (fileReadReturn == 0 && fileWriteReturn == 0) 
		{ /* echo was succesful */
			/* print a success message        */
			printf("ECHOED\n");
			/* and return succsess code */
			return EXIT_NO_ERRORS;
		} /* echo was succesful */
	} /* file is Binary */

	return EXIT_NO_ERRORS;
} /* echoFile() */
