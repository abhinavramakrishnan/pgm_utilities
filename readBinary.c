/* library for I/O routines        */
#include <stdio.h>
/* library for memory routines     */
#include <stdlib.h>
/* structs for different file types */
#include "fileStructures.h"
/* library for constants and error codes */
#include "constantsAndCodes.h"
/* library for pgm utilites */
#include "pgmUtilities.h"

int readBinary(char* filename, pgmFile* file) 
{ /* readBinary() */

	/* Try to open the file for text I/O b/c the header is text  */
	FILE *inputFile = fopen(filename, "rb");
	/* if it fails, return error code        */
	if (inputFile == NULL) 
	{ /* opening file fails */
		return EXIT_BAD_FILE_NAME;
	} /* opening file fails */

	/* check file */
	if (inputFile == NULL) 
	{ /* opening file fails */
		return EXIT_BAD_FILE_NAME;
	} /* opening file fails */

	/* read in the magic number              */
	file->magic_number[0] = getc(inputFile);
	file->magic_number[1] = getc(inputFile);
	/* sanity check on the magic number      */
	if (*file->magic_Number != MAGIC_NUMBER_RAW_PGM) 
	{ /* failed magic number check */
		/* close the file */
		fclose(inputFile);
		/* and return */
		return EXIT_BAD_MAGIC_NUMBER;
	} /* failed magic number check   */

	if (scanComment(inputFile, file) != 0) 
	{ /* scaning comment fails */
		return EXIT_BAD_COMMENT_LINE;
	} /* scaning comment fails */

	/* read in width and height */
	int scanCount = fscanf(inputFile, "%u %u", &(file->width), &(file->height));

	/* sanity checks on size */
	/* must read exactly two values */
	if 	((scanCount != 2) || 
		(file->width < MIN_IMAGE_DIMENSION) || (file->width >= MAX_IMAGE_DIMENSION) || 
		(file->height < MIN_IMAGE_DIMENSION) ||(file->height >= MAX_IMAGE_DIMENSION))
	{ /* failed dimensions check    */
		/* close file pointer   */
		fclose(inputFile);
		/* and return                    */
		return EXIT_BAD_DIMENSIONS;
	} /* failed dimensions check    */

	if (scanComment(inputFile, file) != 0) 
	{ /* scaning comment fails */
		return EXIT_BAD_COMMENT_LINE;
	} /* scaning comment fails */

	/* read in gray value      */
	/* must read exactly one value */
	scanCount = fscanf(inputFile, "%u", &(file->maxGray));
	if (file->maxGray != 255 || scanCount != 1) 
	{ /* failed gray value check    */
		/* close file pointer   */
		fclose(inputFile);
		/* and return                    */
		return EXIT_BAD_MAX_GRAY_VALUE;
	} /* failed grav value check    */	

	if (scanComment(inputFile, file) != 0) 
	{ /* scaning comment fails */
		return EXIT_BAD_COMMENT_LINE;
	} /* scaning comment fails */

	/* Temp buffer to hold data read in from the file */
	unsigned char inputBuffer[file->width*file->height] ;

	/* Read the binary image date from the file */
	fread(inputBuffer, sizeof(unsigned char), file->width*file->height, inputFile);

	/* transfer data from the buffer to the array */
	int counter = 0;
	for (int i=0; i<file->width; i++) 
	{
		for (int j=0; j<file->height; j++) 
		{
			file->imageDataArray[i][j] = inputBuffer[counter];
			counter ++;
		}
	}

	/* close the file */
	fclose(inputFile);
	/* and return a success code */
	return EXIT_NO_ERRORS;

} /* readBinary() */