//////////////// Initialising function ////////////////
void initialise(pgmFile* file);

//////////////// Helper fucntions ////////////////
int echoFile (int typeOfFile, pgmFile* file, char* inputFile, char* outputFile);
int logicallyEqual(pgmFile* filename1, pgmFile* filename2);
void pgmReduce(pgmFile* file);
int reduceSize(pgmFile* file, int factor);
void tileImage (pgmFile* file, pgmFile* tempFile, int factor, int xOffset, int yOffset);
void cleanUp (pgmFile* file);

//////////////// Utility fucntions ////////////////
int scanComment(FILE* inputFile, pgmFile* file);
int error(char* filename, int errorNumber);
int fileType (char* filename, pgmFile* file);
int readHeader(char* filename, pgmFile* file);

//////////////// IO functions ////////////////
int readASCII(char* filename, pgmFile* file);
int readBinary(char* filename, pgmFile* file);
int writeASCII(char* filename, pgmFile* file);
int writeBinary(char* filename, pgmFile* file);