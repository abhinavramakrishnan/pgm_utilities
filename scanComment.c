/* library for I/O routines */
#include <stdio.h>
/* library for memory routines */
#include <stdlib.h>
/* structs for different file types */
#include "fileStructures.h"
/* library for constants and error codes */
#include "constantsAndCodes.h"
/* library for string routines */
#include <string.h>

int scanComment(FILE* inputFile, pgmFile* file) 
{ /* scanComment() */

	/* scan whitespace if present            */
	fscanf(inputFile, " ");
	/* check for a comment line              */
	char nextChar = fgetc(inputFile);
	
	if (nextChar == '#') 
	{ /* comment line                */
		/* allocate buffer               */
		file->commentLine = (char *) malloc(MAX_COMMENT_LINE_LENGTH * sizeof(char));
		
		/* check for memory allocation    */
		if (file->commentLine == NULL) 
		{ /* malloc failed */
			/* close file pointer            */
			fclose(inputFile);
			/* return error code             */
			return EXIT_IMAGE_MALLOC_FAILED;
		} /* malloc failed */

		/* fgets() reads a line          */
		/* capture return value          */
		char *commentString = fgets(file->commentLine, MAX_COMMENT_LINE_LENGTH + 2, inputFile);

		/* NULL means failure            */
		if (commentString == NULL) 
		{ /* NULL comment read   */
			/* close file            */
			fclose(inputFile);
			/* and return            */
			return EXIT_BAD_COMMENT_LINE;
		} /* NULL comment read   */

		if (strlen(commentString) > MAX_COMMENT_LINE_LENGTH) 
		{ /* NULL comment read   */
			/* close file            */
			fclose(inputFile);
			/* and return            */
			return EXIT_BAD_COMMENT_LINE;
		} /* NULL comment read   */

	} /* comment line */

	else 
	{ /* not a comment line */
		/* put character back            */
		ungetc(nextChar, inputFile);
	} /* not a comment line */

	return EXIT_NO_ERRORS;

} /* scanComment() */