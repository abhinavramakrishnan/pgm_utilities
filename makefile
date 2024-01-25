# COMP 1921 Pogramming Project
# Abhinav Ramakrishnan

# -c					Compile only
# -g					Debug support for gdb
# -std=c99				Use the C99 C standard
# -fmax-errors=1		Stop the compiler after one error
# -o					Specify the output file name
# Wall					Turn all warning on
# Werror				Treat all warning as erros

###########################################################
# Macros												  #
###########################################################
# Compiler name
CC=gcc

# Compile flags
CCFLAGS=-g -std=c99 -fmax-errors=1 -Wall -Werror

# Subordinate routine
MODULES=initialise.o echoFile.o readBinary.o readASCII.o writeBinary.o writeASCII.o error.o logicallyEqual.o fileType.o reduceSize.o scanComment.o tileImage.o cleanUp.o

# Main routine
MAINS=pgmEcho.o pgmComp.o pgma2b.o pgmb2a.o pgmReduce.o pgmTile.o pgmAssemble.o

# Executables
TARGETS=pgmEcho pgmComp pgma2b pgmb2a pgmReduce pgmTile pgmAssemble


###########################################################
# Makefile												  #
###########################################################

# DEFAULT TARGET 
# -use dummy target to force compilation of the executables
all:	${TARGETS}

# CLEAN UP
# -use dummy target to clean things up, has no dependencies
#  and will always execute
clean:
	rm ${TARGETS} ${MAINS} ${MODULES} *.o *.pgm


# EXECUTABLE OF pgmEcho
pgmEcho: pgmEcho.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmEcho pgmEcho.o ${MODULES}

# EXECUTABLE OF pgmComp
pgmComp: pgmComp.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmComp pgmComp.o ${MODULES}

pgma2b: pgma2b.o ${MODULES}
	${CC} ${CCFLAGS} -o pgma2b pgma2b.o ${MODULES}

pgmb2a: pgmb2a.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmb2a pgmb2a.o ${MODULES}

pgmReduce: pgmReduce.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmReduce pgmReduce.o ${MODULES}

pgmTile: pgmTile.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmTile pgmTile.o ${MODULES}

pgmAssemble: pgmAssemble.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmAssemble pgmAssemble.o ${MODULES}



######################## TARGET FOR EACH OBJECT FILE ########################

# Main routine for pgmEcho
# Target	Impementaion	Interfaces
pgmEcho.o:	pgmEcho.c		fileStructures.h constantsAndCodes.h pgmUtilities.h
#	Tool		Complie flags		Output name			Files to compile
	${CC}		-c ${CCFLAGS} 		-o pgmEcho.o 		pgmEcho.c

# Main routine for pgmComp
# Target	Impementaion	Interfaces
pgmComp.o:	pgmComp.c 		fileStructures.h constantsAndCodes.h pgmUtilities.h
	${CC} -c ${CCFLAGS} -o pgmComp.o pgmComp.c

# Main routine for pgma2b
# Target	Impementaion	Interfaces
pgma2b.o:	pgma2b.c		fileStructures.h constantsAndCodes.h pgmUtilities.h
#	Tool		Complie flags		Output name			Files to compile
	${CC}		-c ${CCFLAGS} 		-o pgma2b.o 		pgma2b.c


# Main routine for pgma2b
# Target	Impementaion	Interfaces
pgmb2a.o:	pgmb2a.c		fileStructures.h constantsAndCodes.h pgmUtilities.h
#	Tool		Complie flags		Output name			Files to compile
	${CC}		-c ${CCFLAGS} 		-o pgmb2a.o 		pgmb2a.c


# Main routine for pgmReduce
# Target			Impementaion		Interfaces
pgmReduce.o:		pgmReduce.c			fileStructures.h constantsAndCodes.h pgmUtilities.h
#	Tool			Complie flags		Output name				Files to compile
	${CC}			-c ${CCFLAGS}		-o pgmReduce.o			pgmReduce.c

# Main routine for pgmTile
# Target			Impementaion		Interfaces
pgmTile.o:			pgmTile.c			fileStructures.h constantsAndCodes.h pgmUtilities.h
#	Tool			Complie flags		Output name				Files to compile
	${CC}			-c ${CCFLAGS}		-o pgmTile.o			pgmTile.c

# Main routine for pgmAssemble
# Target				Impementaion			Interfaces
pgmAssemble.o:			pgmAssemble.c			fileStructures.h constantsAndCodes.h pgmUtilities.h
#	Tool			Complie flags		Output name				Files to compile
	${CC}			-c ${CCFLAGS}		-o pgmAssemble.o			pgmAssemble.c



# Target		Impementaion	Interfaces
initialise.o:	initialise.c		fileStructures.h constantsAndCodes.h pgmUtilities.h
#	Tool		Complie flags		Output name			Files to compile
	${CC}		-c ${CCFLAGS}		-o initialise.o		initialise.c

# Target		Impementaion	Interfaces
echoFile.o:		echoFile.c		fileStructures.h
#	Tool		Complie flags		Output name			Files to compile
	${CC}		-c ${CCFLAGS}		-o echoFile.o		echoFile.c

# Read modules
# Target		Impementaion	Interfaces
readBinary.o:	readBinary.c 	fileStructures.h constantsAndCodes.h 
#	Tool		Complie flags		Output name				Files to compile
	${CC}		-c ${CCFLAGS}		-o readBinary.o			readBinary.c

# Target		Impementaion	Interfaces
readASCII.o:	readASCII.c 	fileStructures.h constantsAndCodes.h 
#	Tool		Complie flags		Output name				Files to compile
	${CC}		-c ${CCFLAGS}		-o readASCII.o			readASCII.c


# Write modules
# Target		Impementaion		Interfaces
writeBinary.o:	writeBinary.c		fileStructures.h constantsAndCodes.h
#	Tool		Complie flags		Output name				Files to compile
	${CC}		-c ${CCFLAGS}		-o writeBinary.o		writeBinary.c

writeASCII.o:	writeASCII.c		fileStructures.h constantsAndCodes.h
#	Tool		Complie flags		Output name				Files to compile
	${CC}		-c ${CCFLAGS}		-o writeASCII.o		writeASCII.c



# Error handling module
# Target	Impementaion	Interfaces
error.o:	error.c 		constantsAndCodes.h
#	Tool		Complie flags		Output name		Files to compile
	${CC}		-c ${CCFLAGS}		-o error.o		error.c

# Module to check logical equivalence
# Target			Impementaion		Interfaces
logicallyEqual.o:	logicallyEqual.c	fileStructures.h constantsAndCodes.h
#	Tool		Complie flags		Output name				Files to compile
	${CC}		-c ${CCFLAGS}		-o logicallyEqual.o		logicallyEqual.c

# Module to check file type
# Target			Impementaion		Interfaces
fileType.o:			fileType.c			constantsAndCodes.h fileStructures.h
#	Tool		Complie flags		Output name				Files to compile
	${CC}		-c ${CCFLAGS}		-o fileType.o		fileType.c

# Module to check file type
# Target			Impementaion		Interfaces
reduceSize.o:		reduceSize.c		constantsAndCodes.h fileStructures.h
#	Tool		Complie flags		Output name				Files to compile
	${CC}		-c ${CCFLAGS}		-o reduceSize.o		reduceSize.c

# Module to read comments
# Target			Impementaion		Interfaces
scanComment.o:		scanComment.c		constantsAndCodes.h fileStructures.h
#	Tool		Complie flags		Output name				Files to compile
	${CC}		-c ${CCFLAGS}		-o scanComment.o		scanComment.c

# Module to split images into tiles
# Target			Impementaion		Interfaces
tileImage.o:		tileImage.c		constantsAndCodes.h fileStructures.h
#	Tool		Complie flags		Output name				Files to compile
	${CC}		-c ${CCFLAGS}		-o tileImage.o		tileImage.c

# Module to split images into tiles
# Target			Impementaion		Interfaces
cleanUp.o:			cleanUp.c			fileStructures.h
#	Tool		Complie flags		Output name			Files to compile
	${CC}		-c ${CCFLAGS}		-o cleanUp.o		cleanUp.c
