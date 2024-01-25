COMP1721 Coursework 1
Author: Abhinav Ramakrishnan

Instructions to run submission
1. Run the make command in the directory with all the source code to comile all the files and produce 
the executables.
2. ./test.sh can be used to run some automated tests on the programs

This folder contains the following programs:
1. pgmEcho
2. pgmComp
3. pgma2b
4. pgmb2a
5. pgmReduce
6. pgmTile
7. pgmAssemble


----------------------------------------------------------------------------------------------------
                                            pgmEcho
----------------------------------------------------------------------------------------------------
Usage: 
./pgmEcho inputImage.pgm outputImage.pgm

Arguments:
1. an input file (either ASCII or binary)
2. an output file

Description:
This program echos(copy's) the input file to the output file.


----------------------------------------------------------------------------------------------------
                                            pgmComp
----------------------------------------------------------------------------------------------------
Usage:
./pgmComp inputImage.pgm inputImage.pgm

Arguments:
1. an input file 1 (either ASCII or binary)
2. an input file 2 (either ASCII or binary)

Description:
This program takes two imput pgm files and comapres them to see if they are identical.


----------------------------------------------------------------------------------------------------
                                            pgma2b
----------------------------------------------------------------------------------------------------
Usage:
./pgma2b inputImage.pgm outputImage.pgm

Arguments:
1. an input file (ASCII)
2. an output file (Binary)

Description:
This program converts an ASCII pgm to a binary pgm.


----------------------------------------------------------------------------------------------------
                                            pgmb2a
----------------------------------------------------------------------------------------------------
Usage:
./pgmb2a inputImage.pgm outputImage.pgm

Arguments:
1. an input file (Binary)
2. an output file (ASCII)

Description:
This program converts a binary pgm to an ASCII pgm.


----------------------------------------------------------------------------------------------------
                                            pgmReduce
----------------------------------------------------------------------------------------------------
Usage: 
./pgmReduce inputImage.pgm reduction_factor outputImage.pgm

Arguments:
1. an input file (either ASCII or binary)
2. an integer factor n
3. an output file

Description:
This program takes the input file and reduces it by the facoter n in each diemsion. 

Example: 
If the invocation is: ./pgmReduce inputFile 5 outputFile and inputFile is a 13x17 image, 
then outputFile will be a 2x3 image.


----------------------------------------------------------------------------------------------------
                                            pgmTile
----------------------------------------------------------------------------------------------------
Usage:
./pgmTile inputImage.pgm tiling_factor outputImage_<row>_<column>.pgm

Arguments:
1. an input file name
2. a tiling factor
3. a template for output files

Description:
This program takes 3 arguments, an input file (either ASCII or binary), a tiling factor n, and an 
output file name template. It then divides the input file into n*n smaller images corresponding to 
parts of the image. 

Example:
If the invocation is: ./pgmTile sampleFile.pgm 3 "sampleFile_<row>_<column>.pgm" then the programme 
will read in sampleFile.pgm and output 9 smaller images, named:
sampleFile_0_0.pgm
sampleFile_0_1.pgm
sampleFile_0_2.pgm
sampleFile_1_0.pgm
sampleFile_1_1.pgm
sampleFile_1_2.pgm
sampleFile_2_0.pgm
sampleFile_2_1.pgm
sampleFile_2_2.pgm
i.e. substituting the relative position of the subimage in the larger image into the <row> and
<column> tags in the template name.


----------------------------------------------------------------------------------------------------
                                            pgmAssemble
----------------------------------------------------------------------------------------------------
Usage: 
./pgmReduce inputImage.pgm reduction_factor outputImage.pgm

Arguments:
It takes 3n+3 arguments of which the first three are:
1. an output file name
2. width of the output image
3. height of the output image
and the remainder are the layout are triples of:
3i+1. row at which the subimage starts
3i+2. column at which the subimage starts
3i+3. The subimage to insert at that location

Description:
This programme can be used to assemble a large image from smaller ones. 
