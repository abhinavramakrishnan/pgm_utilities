#!/bin/sh
#
#--------------Test Script-----------------

############################################################################
#                               Tests for pgmEcho                          #
############################################################################
echo "/////////////////////////////////////////////////////////////////////"
echo "//                            pgmEcho tests                        //"
echo "/////////////////////////////////////////////////////////////////////"
# Call with no arguments
./pgmEcho
# Call with wrong number of arguments
./pgmEcho ./pgm/ascii/slice0a.pgm
# Call with bad file name
./pgmEcho invalidFile.pgm outputImage.pgm
# Pass in file with bad magic number
./pgmEcho ./pgm/ascii/bad_magic_number.pgm outputImage.pgm
# Pass in file with bad dimensions(-1)
./pgmEcho ./pgm/ascii/bad_dimensions_-1.pgm outputImage.pgm
# Pass in file with bad dimensions(65536)
./pgmEcho ./pgm/ascii/bad_dimensions_65536.pgm outputImage.pgm
# Pass in file with bad Max Gray Value(-1)
./pgmEcho ./pgm/ascii/bad_gray_-1.pgm outputImage.pgm
# Pass in file with bad Max Gray Value(256)
./pgmEcho ./pgm/ascii/bad_gray_256.pgm outputImage.pgm
# Pass in file with bad comment line 
./pgmEcho ./pgm/ascii/bad_comment.pgm outputImage.pgm
# Pass in file with bad data(small file size)
./pgmEcho ./pgm/ascii/bad_data_small_file.pgm outputImage.pgm
# Pass in file with bad data(big file size)
./pgmEcho ./pgm/ascii/bad_data_big_file.pgm outputImage.pgm
# Pass in file with bad data(256)
./pgmEcho ./pgm/ascii/bad_data_-1.pgm outputImage.pgm
# Pass in file with bad data(-1)
./pgmEcho ./pgm/ascii/bad_data_256.pgm outputImage.pgm

echo "\nEcho ASCII file: "
# Call with an ASCII file
./pgmEcho ./pgm/ascii/balloons.pgm echo_ASCII_Output.pgm
echo "\nEcho Binary file: "
# Call with a binary file
./pgmEcho ./pgm/binary/baboon.pgm echo_binary_Output.pgm


############################################################################
#                               Tests for pgmComp                          #
############################################################################
echo "\n/////////////////////////////////////////////////////////////////////"
echo "//                            pgmComp tests                        //"
echo "/////////////////////////////////////////////////////////////////////"
# Call with no arguments
./pgmComp
# Call with wrong number of arguments
./pgmComp ./pgm/ascii/slice0a.pgm
################### Tests for bad file 1 ###################
# Call with bad file name
./pgmComp invalidFile.pgm ./pgm/ascii/slice0a.pgm
# Pass in file with bad magic number
./pgmComp ./pgm/ascii/bad_magic_number.pgm ./pgm/ascii/slice0a.pgm
# Pass in file with bad dimensions(-1)
./pgmComp ./pgm/ascii/bad_dimensions_-1.pgm ./pgm/ascii/slice0a.pgm
# Pass in file with bad dimensions(65536)
./pgmComp ./pgm/ascii/bad_dimensions_65536.pgm ./pgm/ascii/slice0a.pgm
# Pass in file with bad Max Gray Value(-1)
./pgmComp ./pgm/ascii/bad_gray_-1.pgm ./pgm/ascii/slice0a.pgm
# Pass in file with bad Max Gray Value(256)
./pgmComp ./pgm/ascii/bad_gray_256.pgm ./pgm/ascii/slice0a.pgm
# Pass in file with bad comment line 
./pgmComp ./pgm/ascii/bad_comment.pgm ./pgm/ascii/slice0a.pgm
# Pass in file with bad data(small file size)
./pgmComp ./pgm/ascii/bad_data_small_file.pgm ./pgm/ascii/slice0a.pgm
# Pass in file with bad data(big file size)
./pgmComp ./pgm/ascii/bad_data_big_file.pgm ./pgm/ascii/slice0a.pgm
# Pass in file with bad data(256)
./pgmComp ./pgm/ascii/bad_data_-1.pgm ./pgm/ascii/slice0a.pgm
# Pass in file with bad data(-1)
./pgmComp ./pgm/ascii/bad_data_256.pgm ./pgm/ascii/slice0a.pgm

################### Tests for bad file 2 ###################
# Call with bad file name
./pgmComp ./pgm/ascii/slice0a.pgm invalidFile.pgm
# Pass in file with bad magic number
./pgmComp ./pgm/ascii/slice0a.pgm ./pgm/ascii/bad_magic_number.pgm
# Pass in file with bad dimensions(-1)
./pgmComp ./pgm/ascii/slice0a.pgm ./pgm/ascii/bad_dimensions_-1.pgm
# Pass in file with bad dimensions(65536)
./pgmComp ./pgm/ascii/slice0a.pgm ./pgm/ascii/bad_dimensions_65536.pgm
# Pass in file with bad Max Gray Value(-1)
./pgmComp ./pgm/ascii/slice0a.pgm ./pgm/ascii/bad_gray_-1.pgm
# Pass in file with bad Max Gray Value(256)
./pgmComp ./pgm/ascii/slice0a.pgm ./pgm/ascii/bad_gray_256.pgm
# Pass in file with bad comment line 
./pgmComp ./pgm/ascii/slice0a.pgm ./pgm/ascii/bad_comment.pgm
# Pass in file with bad data(small file size)
./pgmComp ./pgm/ascii/slice0a.pgm ./pgm/ascii/bad_data_small_file.pgm
# Pass in file with bad data(big file size)
./pgmComp ./pgm/ascii/slice0a.pgm ./pgm/ascii/bad_data_big_file.pgm
# Pass in file with bad data(256)
./pgmComp ./pgm/ascii/slice0a.pgm ./pgm/ascii/bad_data_-1.pgm
# Pass in file with bad data(-1)
./pgmComp ./pgm/ascii/slice0a.pgm ./pgm/ascii/bad_data_256.pgm


echo "\nIdentical ASCII file: "
# Call with identical ASCII file
./pgmComp ./pgm/ascii/balloons.pgm ./pgm/ascii/balloons_copy.pgm
echo "Different ASCII file: "
# Call with Different ASCII file
./pgmComp ./pgm/ascii/balloons.pgm ./pgm/ascii/slice0a.pgm

echo "\nIdentical Binary file: "
# Call with identical ASCII file
./pgmComp ./pgm/binary/baboon.pgm ./pgm/binary/baboon_copy.pgm
echo "Different Binary file: "
# Call with Different ASCII file
./pgmComp ./pgm/binary/baboon.pgm ./pgm/binary/slice0b.pgm

echo "\nIdentical ASCII file and binary file : "
# Call with identical ASCII file
./pgmComp ./pgm/ascii/surf_ascii.pgm ./pgm/binary/surf_binary.pgm
echo "Different ASCII file and binary file : "
# Call with Different ASCII file
./pgmComp ./pgm/ascii/balloons.pgm ./pgm/binary/baboon.pgm



############################################################################
#                               Tests for pgma2b                           #
############################################################################
echo "\n/////////////////////////////////////////////////////////////////////"
echo "//                            pgma2b tests                         //"
echo "/////////////////////////////////////////////////////////////////////"
# Call with no arguments
./pgma2b
# Call with wrong number of arguments
./pgma2b ./pgm/ascii/slice0a.pgm
# Call with bad file name
./pgma2b invalidFile.pgm outputImage.pgm
# Pass in file with bad magic number
./pgma2b ./pgm/ascii/bad_magic_number.pgm outputImage.pgm
# Pass in file with bad dimensions(-1)
./pgma2b ./pgm/ascii/bad_dimensions_-1.pgm outputImage.pgm
# Pass in file with bad dimensions(65536)
./pgma2b ./pgm/ascii/bad_dimensions_65536.pgm outputImage.pgm
# Pass in file with bad Max Gray Value(-1)
./pgma2b ./pgm/ascii/bad_gray_-1.pgm outputImage.pgm
# Pass in file with bad Max Gray Value(256)
./pgma2b ./pgm/ascii/bad_gray_256.pgm outputImage.pgm
# Pass in file with bad comment line 
./pgma2b ./pgm/ascii/bad_comment.pgm outputImage.pgm
# Pass in file with bad data(small file size)
./pgma2b ./pgm/ascii/bad_data_small_file.pgm outputImage.pgm
# Pass in file with bad data(big file size)
./pgma2b ./pgm/ascii/bad_data_big_file.pgm outputImage.pgm
# Pass in file with bad data(256)
./pgma2b ./pgm/ascii/bad_data_-1.pgm outputImage.pgm
# Pass in file with bad data(-1)
./pgma2b ./pgm/ascii/bad_data_256.pgm outputImage.pgm

echo "\nConvert from ASCII to binary: "
# Call with ASCII file
./pgma2b ./pgm/ascii/balloons.pgm balloons_binary.pgm
echo "and "
# Compare ASCII and binary file after converting
./pgmComp ./pgm/ascii/balloons.pgm balloons_binary.pgm


############################################################################
#                               Tests for pgmb2a                           #
############################################################################
echo "\n/////////////////////////////////////////////////////////////////////"
echo "//                            pgmb2a tests                         //"
echo "/////////////////////////////////////////////////////////////////////"
# Call with no arguments
./pgmb2a
# Call with wrong number of arguments
./pgmb2a ./pgm/ascii/slice0a.pgm
# Call with bad file name
./pgmb2a invalidFile.pgm outputImage.pgm
# Pass in file with bad magic number
./pgmb2a ./pgm/ascii/bad_magic_number.pgm outputImage.pgm
# Pass in file with bad dimensions(-1)
./pgmb2a ./pgm/ascii/bad_dimensions_-1.pgm outputImage.pgm
# Pass in file with bad dimensions(65536)
./pgmb2a ./pgm/ascii/bad_dimensions_65536.pgm outputImage.pgm
# Pass in file with bad Max Gray Value(-1)
./pgmb2a ./pgm/ascii/bad_gray_-1.pgm outputImage.pgm
# Pass in file with bad Max Gray Value(256)
./pgmb2a ./pgm/ascii/bad_gray_256.pgm outputImage.pgm
# Pass in file with bad comment line 
./pgmb2a ./pgm/ascii/bad_comment.pgm outputImage.pgm
# Pass in file with bad data(small file size)
./pgmb2a ./pgm/ascii/bad_data_small_file.pgm outputImage.pgm
# Pass in file with bad data(big file size)
./pgmb2a ./pgm/ascii/bad_data_big_file.pgm outputImage.pgm
# Pass in file with bad data(256)
./pgmb2a ./pgm/ascii/bad_data_-1.pgm outputImage.pgm
# Pass in file with bad data(-1)
./pgmb2a ./pgm/ascii/bad_data_256.pgm outputImage.pgm

echo "\nConvert from binary to ASCII: "
# Call with binary file
./pgmb2a ./pgm/binary/baboon.pgm baboon_ascii.pgm
echo "and "
# Compare ASCII and binary file after converting
./pgmComp ./pgm/binary/baboon.pgm baboon_ascii.pgm


############################################################################
#                              Tests for pgmReduce                         #
############################################################################
echo "\n/////////////////////////////////////////////////////////////////////"
echo "//                           pgmReduce tests                       //"
echo "/////////////////////////////////////////////////////////////////////"
# Call with no arguments
./pgmReduce
# Call with wrong number of arguments - 1/3
./pgmReduce ./pgm/ascii/slice0a.pgm 
# Call with wrong number of arguments - 2/3
./pgmReduce ./pgm/ascii/slice0a.pgm 1
# Call with wrong reduction factor(-1)
./pgmReduce ./pgm/ascii/slice0a.pgm -1 outputImage.pgm
# Call with wrong reduction factor(abc)
./pgmReduce ./pgm/ascii/slice0a.pgm abc outputImage.pgm
# Call with bad file name
./pgmReduce invalidFile.pgm 1 outputImage.pgm
# Pass in file with bad magic number
./pgmReduce ./pgm/ascii/bad_magic_number.pgm 1 outputImage.pgm
# Pass in file with bad dimensions(-1)
./pgmReduce ./pgm/ascii/bad_dimensions_-1.pgm 1 outputImage.pgm
# Pass in file with bad dimensions(65536)
./pgmReduce ./pgm/ascii/bad_dimensions_65536.pgm 1 outputImage.pgm
# Pass in file with bad Max Gray Value(-1)
./pgmReduce ./pgm/ascii/bad_gray_-1.pgm 1 outputImage.pgm
# Pass in file with bad Max Gray Value(256)
./pgmReduce ./pgm/ascii/bad_gray_256.pgm 1 outputImage.pgm
# Pass in file with bad comment line 
./pgmReduce ./pgm/ascii/bad_comment.pgm 1 outputImage.pgm
# Pass in file with bad data(small file size)
./pgmReduce ./pgm/ascii/bad_data_small_file.pgm 1 outputImage.pgm
# Pass in file with bad data(big file size)
./pgmReduce ./pgm/ascii/bad_data_big_file.pgm 1 outputImage.pgm
# Pass in file with bad data(256)
./pgmReduce ./pgm/ascii/bad_data_-1.pgm 1 outputImage.pgm
# Pass in file with bad data(-1)
./pgmReduce ./pgm/ascii/bad_data_256.pgm 1 outputImage.pgm

echo "\nReduce ASCII file: "
# Call with an ASCII file
./pgmReduce ./pgm/ascii/balloons.pgm 5 reduce_ASCII_Output.pgm
echo "\nReduce Binary file: "
# Call with a binary file
./pgmReduce ./pgm/binary/baboon.pgm 5 reduce_binary_Output.pgm


############################################################################
#                               Tests for pgmTile                          #
############################################################################
echo "\n/////////////////////////////////////////////////////////////////////"
echo "//                            pgmTile tests                        //"
echo "/////////////////////////////////////////////////////////////////////"
# Call with no arguments
./pgmTile
# Call with wrong number of arguments - 1/3
./pgmTile ./pgm/ascii/slice0a.pgm 
# Call with wrong number of arguments - 2/3
./pgmTile ./pgm/ascii/slice0a.pgm 1
# Call with wrong reduction factor(-1)
./pgmTile ./pgm/ascii/slice0a.pgm -1 "outputImage_<row>_<column>.pgm"
# Call with wrong reduction factor(abc)
./pgmTile ./pgm/ascii/slice0a.pgm abc "outputImage_<row>_<column>.pgm"
# Call with bad file name
./pgmTile invalidFile.pgm 1 "outputImage_<row>_<column>.pgm"
# Pass in file with bad magic number
./pgmTile ./pgm/ascii/bad_magic_number.pgm 1 "outputImage_<row>_<column>.pgm"
# Pass in file with bad dimensions(-1)
./pgmTile ./pgm/ascii/bad_dimensions_-1.pgm 1 "outputImage_<row>_<column>.pgm"
# Pass in file with bad dimensions(65536)
./pgmTile ./pgm/ascii/bad_dimensions_65536.pgm 1 "outputImage_<row>_<column>.pgm"
# Pass in file with bad Max Gray Value(-1)
./pgmTile ./pgm/ascii/bad_gray_-1.pgm 1 "outputImage_<row>_<column>.pgm"
# Pass in file with bad Max Gray Value(256)
./pgmTile ./pgm/ascii/bad_gray_256.pgm 1 "outputImage_<row>_<column>.pgm"
# Pass in file with bad comment line 
./pgmTile ./pgm/ascii/bad_comment.pgm 1 "outputImage_<row>_<column>.pgm"
# Pass in file with bad data(small file size)
./pgmTile ./pgm/ascii/bad_data_small_file.pgm 1 "outputImage_<row>_<column>.pgm"
# Pass in file with bad data(big file size)
./pgmTile ./pgm/ascii/bad_data_big_file.pgm 1 "outputImage_<row>_<column>.pgm"
# Pass in file with bad data(256)
./pgmTile ./pgm/ascii/bad_data_-1.pgm 1 "outputImage_<row>_<column>.pgm"
# Pass in file with bad data(-1)
./pgmTile ./pgm/ascii/bad_data_256.pgm 1 "outputImage_<row>_<column>.pgm"

echo "\nTile ASCII file: "
# Call with an ASCII file
./pgmTile ./pgm/ascii/apollonian_gasket.pgm 3 "output_ascii_<row>_<column>.pgm"
echo "\nTile Binary file: "
# Call with a binary file
./pgmTile ./pgm/binary/baboon.pgm 3 "output_binary_<row>_<column>.pgm"


############################################################################
#                             Tests for pgmAssemble                        #
############################################################################
echo "\n/////////////////////////////////////////////////////////////////////"
echo "//                          pgmAssemble tests                      //"
echo "/////////////////////////////////////////////////////////////////////"
# Call with no arguments
./pgmAssemble
# Call with wrong number of arguments
./pgmAssemble outputImage.pgm
# Call with wrong number of arguments
./pgmAssemble outputImage.pgm 0
# Call with wrong number of arguments
./pgmAssemble outputImage.pgm 0 0
# Call with bad file name
./pgmAssemble outputImage.pgm 100 100 0 0 invalidFile.pgm
# Pass in file with bad magic number
./pgmAssemble outputImage.pgm 100 100 0 0 ./pgm/ascii/bad_magic_number.pgm
# Pass in file with bad dimensions(-1)
./pgmAssemble outputImage.pgm 100 100 0 0 ./pgm/ascii/bad_dimensions_-1.pgm
# Pass in file with bad dimensions(65536)
./pgmAssemble outputImage.pgm 100 100 0 0 ./pgm/ascii/bad_dimensions_65536.pgm
# Pass in file with bad Max Gray Value(-1)
./pgmAssemble outputImage.pgm 100 100 0 0 ./pgm/ascii/bad_gray_-1.pgm
# Pass in file with bad Max Gray Value(256)
./pgmAssemble outputImage.pgm 100 100 0 0 ./pgm/ascii/bad_gray_256.pgm
# Pass in file with bad comment line 
./pgmAssemble outputImage.pgm 100 100 0 0 ./pgm/ascii/bad_comment.pgm
# Pass in file with bad data(small file size)
./pgmAssemble outputImage.pgm 100 100 0 0 ./pgm/ascii/bad_data_small_file.pgm
# Pass in file with bad data(big file size)
./pgmAssemble outputImage.pgm 100 100 0 0 ./pgm/ascii/bad_data_big_file.pgm
# Pass in file with bad data(256)
./pgmAssemble outputImage.pgm 100 100 0 0 ./pgm/ascii/bad_data_-1.pgm
# Pass in file with bad data(-1)
./pgmAssemble outputImage.pgm 100 100 0 0 ./pgm/ascii/bad_data_256.pgm

echo "\nAssemble ASCII files: "
# Call with an ASCII files
./pgmAssemble ascii_assemble_output.pgm 600 600 0 0 output_ascii_0_0.pgm 0 1 output_ascii_0_1.pgm 1 0 output_ascii_1_0.pgm 1 2 output_ascii_1_2.pgm 2 0 output_ascii_2_0.pgm 0 2 output_ascii_0_2.pgm 1 1 output_ascii_1_1.pgm 2 1 output_ascii_2_1.pgm 2 2 output_ascii_2_2.pgm

echo "\nAssemble binary files: "
# Call with an binary files
./pgmAssemble binary_assemble_output.pgm 512 512 0 0 output_binary_0_0.pgm 0 1 output_binary_0_1.pgm 1 0 output_binary_1_0.pgm 1 2 output_binary_1_2.pgm 2 0 output_binary_2_0.pgm 0 2 output_binary_0_2.pgm 1 1 output_binary_1_1.pgm 2 1 output_binary_2_1.pgm 2 2 output_binary_2_2.pgm


############################################
# Clean temp files                         #
############################################
rm *.pgm
