#include "constantsAndCodes.h"
typedef struct _pgmFile 
{
	/* store the magic number */
    unsigned char magic_number[2];
	unsigned short *magic_Number;

	/* store ONE comment	         */
	char *commentLine;

	/* the logical width & height	         */
	/* note: cannot be negative	         */
	unsigned int width, height;

	/* maximum gray value (assumed)	         */
	/* make it an integer for ease	         */
	unsigned int maxGray;

	/* pointer to raw image data	         */
	unsigned char *imageData;

	/*Buffer for image being read in */
	unsigned char buffer[424288125];

	/* 2D array for image data*/
	unsigned char imageDataArray[MAX_IMAGE_DIMENSION][MAX_IMAGE_DIMENSION];

} pgmFile;
