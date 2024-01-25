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
/* library for string routines */
#include <string.h>


/********************************************/
/* Main Routine                    			*/
/*                                 			*/
/* CLI parameters:                 			*/
/* argv[0]: executable name        			*/
/* argv[1]: input file name        			*/
/* argv[3]: tiling factor       			*/
/* argv[4]: template for output files      	*/
/* returns 0 on success           			*/
/* non-zero error code on fail     			*/
/********************************************/

int main(int argc, char **argv) 
{ /* main() */

	//////////////// check number of arguments ////////////////
	if (argc == 1) 
	{ /* no arguments  */
		/* print a usage message */
		printf("Usage: %s inputImage.pgm tiling_factor outputImage_<row>_<column>.pgm\n", argv[0]);
		/* and return 0      */
		return 0;
	} /* no arguments  */

	else if (argc != 4) 
	{ /* wrong number of arguments */
		/* print an error message        */
		printf("ERROR: Bad Argument Count\n");
		/* and return 0 */
		return EXIT_BAD_ARGUMENT_COUNT;
	} /* wrong number of arguments */

	/* Turn the second argument into the reduction factor */
    int factor = atoi(argv[2]);

	/* check reduction factor */
	if (factor <= 0)
	{ /* invalid reduction factor */
		/* print an error message  */
		printf("ERROR: Miscellaneous (Invalid reduction factor)\n");
		/* and return 0      */
		return EXIT_MISCELLANEOUS;
	} /* invalid reduction factor */

    /* Create a pgm file structure */
	pgmFile *file = (pgmFile *) malloc(sizeof(pgmFile));

	if (file == NULL) { /* malloc failed */
		printf("ERROR: Image Malloc Failed\n");
		/* free memory */
		free(file);
		/* and return error code */
		return EXIT_IMAGE_MALLOC_FAILED;
	} /* malloc failed */

	/* Temp pgm file structure */
	pgmFile *tempFile = (pgmFile *) malloc(sizeof(pgmFile));

	if (tempFile == NULL) { /* malloc failed */
		printf("ERROR: Image Malloc Failed\n");
		/* free memory */
		free(tempFile);
		/* and return error code */
		return EXIT_IMAGE_MALLOC_FAILED;
	} /* malloc failed */

	/* Initialise values in the pgm file structures */
	initialise(file);
	initialise(tempFile);

    /* Check the file type */
    int type = fileType(argv[1], file);

	/* buffers to hold the template */
	char fileStart[100] = "";
	char fileEnd[100] = "";
	char row[6] = "";
	char col[9]= "";

	/* parse the template for the output files */
	sscanf(argv[3], "%[^<]%[^_]_%[^_ .]%[^.].", fileStart, row, col, fileEnd);

	if ((strcmp(row, "<row>")) || strcmp(col, "<column>")) 
	{ /* doesn't contain <row> and <column>*/
		/* print an error message        */
		printf("ERROR: Miscellaneous (Bad template)\n");
		/* free memory */
		free(tempFile);
		/* and return 0      */
		return EXIT_MISCELLANEOUS;
	} /* doesn't contain <row> and <column>*/

	/* x and y offset when reading the file */
	int xOffset = 0;
	int yOffset = 0;

	/* buffer to hold the final file name */
	char fileName[500];

	if(type == 0) 
	{ /* file is ASCCI */
        /* Read from pgm file */
		int fileReadReturn = readASCII(argv[1], file);
		if (fileReadReturn != 0) 
		{ /* read failed */
			/* free memory */
			cleanUp(file);
			/* and return error code */
			return error(argv[1], fileReadReturn);
		} /* read failed */

		/* set the width and height of the file */
		tempFile->width = file-> width / factor;
		tempFile->height = file->height / factor;

		/* loop factor * factor times creating one tile at a time */
		int counter = 0;
		for (int i=0; i<factor; i++) 
		{
			yOffset = 0;
			for (int j=0; j<factor; j++) 
			{

				if (!strcmp(fileEnd, "")) 
				{ /* if the template has text after <row> <column> */
					sprintf(fileName, "%s%d_%d.pgm", fileStart, i, j);
				} /* if the template has text after <row> <column> */
				else 
				{
					sprintf(fileName, "%s%d_%d%s.pgm", fileStart, i, j, fileEnd);
				}

				/* generate a tile */
				tileImage(file, tempFile, factor, xOffset, yOffset);

				/* Wrtie to pgm file */
				int fileWriteReturn = writeASCII(fileName, tempFile);
				if (fileWriteReturn != 0) 
				{ /* write failed */
					/* free memory */
					cleanUp(file);
					/* and return error code */
					return error(fileName, fileWriteReturn);
				} /* write failed */

				/* increase the y offset */
				yOffset = yOffset + tempFile->width;
				counter ++;
			}
			/* increase the y offset */
			xOffset = xOffset + tempFile->width;
		}

        if (fileReadReturn == 0 && (counter == factor*factor)) 
		{ /* successfully tiled the image */
			/* print a success message        */
			printf("TILED\n");
			/* print an success code        */
			return EXIT_NO_ERRORS;
		}/* successfully tiled the image */
		
	} /* file is ASCCI */

	
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

		/* set the width and height of the file */
		tempFile->width = file-> width / factor;
		tempFile->height = file->height / factor;

		/* loop factor * factor times creating one tile at a time */
		int counter = 0;
		for (int i=0; i<factor; i++) 
		{
			yOffset = 0;
			for (int j=0; j<factor; j++) 
			{

				if (!strcmp(fileEnd, "")) 
				{ /* if the template has text after <row> <column> */
					sprintf(fileName, "%s%d_%d.pgm", fileStart, i, j);
				} /* if the template has text after <row> <column> */
				else 
				{
					sprintf(fileName, "%s%d_%d%s.pgm", fileStart, i, j, fileEnd);
				}

				/* generate a tile */
				tileImage(file, tempFile, factor, xOffset, yOffset);

				/* Wrtie to pgm file */
				int fileWriteReturn = writeBinary(fileName, tempFile);
				if (fileWriteReturn != 0) 
				{ /* write failed */
					/* free memory */
					cleanUp(file);
					/* and return error code */
					return error(fileName, fileWriteReturn);
				} /* write failed */

				/* increase the y offset */
				yOffset = yOffset + tempFile->width;
				counter ++;
			}
			/* increase the y offset */
			xOffset = xOffset + tempFile->width;
		}

        if (fileReadReturn == 0 && (counter == factor*factor)) 
		{ /* successfully tiled the image */
			/* print a success message        */
			printf("TILED\n");
			/* print an success code        */
			return EXIT_NO_ERRORS;
		}/* successfully tiled the image */
		
	} /* file is binary */

	else 
	{ /* erro occurs */
		/* return error code */
		return error(argv[1], type);
		/* and free memory */
		cleanUp(file);
		cleanUp(tempFile);
	} /* erro occurs */
	
	/* at this point, we are done and can exit with a success code */
	return EXIT_NO_ERRORS;
}
