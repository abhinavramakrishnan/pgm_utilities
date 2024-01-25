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

int readASCII(char* filename, pgmFile* file) 
{ /* readASCII() */

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
	/* sanity check on the magic number      */
	if (*file->magic_Number != MAGIC_NUMBER_ASCII_PGM) 
	{ /* failed magic number check   */
		/* close the file       */
		fclose(inputFile);
		/* and return                    */
		return EXIT_BAD_MAGIC_NUMBER;
	} /* failed magic number check   */

	if (scanComment(inputFile, file) != 0) 
	{ /* scaning comment fails */
		return EXIT_BAD_COMMENT_LINE;
	} /* scaning comment fails */

	/* read in width, height */
	/* whitespace to skip blanks */
	int scanCount = fscanf(inputFile, "%u %u", &(file->width), &(file->height));

	/* sanity checks on size */
	/* must read exactly two values */
	if 	((scanCount != 2)	||
		(file->width 	< MIN_IMAGE_DIMENSION	) 	|| (file->width 	>= MAX_IMAGE_DIMENSION	) ||
		(file->height < MIN_IMAGE_DIMENSION		) 	|| (file->height >= MAX_IMAGE_DIMENSION		))
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

	/* allocate the data pointer */
	long nImageBytes = (file->width) * (file->height) * sizeof(unsigned char);
	file->imageData = (unsigned char *) malloc(nImageBytes);

	/* sanity check for memory allocation    */
	if (file->imageData == NULL) { /* malloc failed */
		/* close file pointer            */
		fclose(inputFile);
		/* return error code             */
		return EXIT_IMAGE_MALLOC_FAILED;
	} /* malloc failed */

	int counter = 0;
	/* pointer for efficient read code */
	for (unsigned char *nextGrayValue = file->imageData;
		nextGrayValue < file->imageData + nImageBytes; nextGrayValue++) 
		{ /* per gray value */

		if (scanComment(inputFile, file) != 0) 
		{ /* bad comment */
			return EXIT_BAD_COMMENT_LINE;
		} /* bad comment */

		/* read next value  */
		int grayValue = -1;
		int scanCount = fscanf(inputFile, " %u", &grayValue);

		/* sanity check	  */
		if ((scanCount != 1) || (grayValue < 0) || (grayValue > 255)) 
		{ /* fscanf failed */
			/* close file            */
			fclose(inputFile);
			/* and return            */
			return EXIT_BAD_DATA;
		} /* fscanf failed */

		/* set the pixel value           */
		*nextGrayValue = (unsigned char) grayValue;
		file->buffer[counter] = (unsigned char) grayValue;
		counter++;

	} /* per gray value */

	/* check if another value exists               */
	int grayValue = -1;
	scanCount = fscanf(inputFile, " %u", &grayValue);

	/* sanity check	                 */
	if ((scanCount != 1) || (grayValue < 0) || (grayValue > 255)) 
	{ /* there isn't more data */
		/* transfer data from the buffer to the array*/
		counter = 0;
		for (int i=0; i<file->width; i++) 
		{
			for (int j=0; j<file->height; j++) 
			{
				file->imageDataArray[i][j] = file->buffer[counter];
				counter++;
			}
		}
		/* return success code */
		return EXIT_NO_ERRORS;

	} /* there isn't more data */
	
	else 
	{ /* there is extra data */
		/* close file            */
		fclose(inputFile);
		/* and return            */
		return EXIT_BAD_DATA;
	} /* there is extra data */

} /* readASCII() */