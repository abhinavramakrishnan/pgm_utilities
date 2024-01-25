/* library for I/O routines */
#include <stdio.h>
/* library for memory routines */
#include <stdlib.h>
/* library for constants and error codes */
#include "constantsAndCodes.h"

int error(char* info, int errorNumber) 
{ /* error() */
	/* use to error number given to print an appropriate error message */
    switch (errorNumber) {
    	case 2:
			/* print error message */
			printf("ERROR: Bad File Name (%s)\n", info);
            break;
		case 3:
			/* print error message */
			printf("ERROR: Bad Magic Number (%s)\n", info);
			break;
		case 4:
			/* print error message */
			printf("ERROR: Bad Comment Line (%s)\n", info);
			break;
		case 5:
			/* print error message */
			printf("ERROR: Bad Dimensions (%s)\n", info);
			break;
		case 6:
			/* print error message */
			printf("ERROR: Bad Max Gray Value (%s)\n", info);
			break;
		case 7:
			/* print error message */
			printf("ERROR: Image Malloc Failed\n");
			break;
		case 8:
			/* print error message */
			printf("ERROR: Bad Data (%s)\n", info);
			break;
		case 9:
			/* print error message */
			printf("ERROR: Output Failed (%s)\n", info);
			break;
		case 10:
			/* print error message */
			printf("ERROR: Bad Layout\n");
			break;
		case 100:
			/* print error message */
			printf("Miscellaneous\n");
			break;
    }
	
	/* return error code */
	return errorNumber;

}/* error() */