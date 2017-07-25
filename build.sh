#!/bin/bash

function help() {
	echo "Illegal number of parameters. Should be : "
	echo "    $0 <SAMPLE_NAME> <MODE>"
	echo "    Supported samples names : "
	echo "        "$SAMPLES
	echo "    Supported mode : "
	echo "        inception"
	echo "        fracture"
	exit 1
}

function clean() {
	rm -rf $3/*.o
	rm -rf $3/*.ll
	#rm -rf $3/*.bc
	rm -rf $3/*.elf
	rm -rf $3/*.bin
}

LLVM_LINK='../tools/llvm/build_debug/Debug+Asserts/bin/llvm-link'
LLVM_AS='../tools/llvm/build_debug/Debug+Asserts/bin/llvm-as'
CLANG='../tools/llvm/build_debug/Debug+Asserts/bin/clang'
TARGET_PATH='../Compiler/Debug+Asserts/bin'
TARGET=''

AS_ARGS='-mcpu=cortex-m3 -mthumb -mfloat-abi=softfp'
CLANG_ARGS='--target=thumbv7m-elf -mcpu=cortex-m3 -mthumb'
GCC_ARGS='-march=armv7-m -mthumb -mcpu=cortex-m3 -Wa,-mimplicit-it=thumb'
fracture_ARGS='-arch=thumb -triple=thumbv7m-unknown-none-elf -mcpu=cortex-m3'

PRINT_GRAPHS=false

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

#SAMPLES="$(find ./* -type d -printf "%f\n")"

if [ "$#" != 3 ]; then
	help
fi

if [ "$2" == "inception" ]; then
	TARGET="inception-cl"
	FRACTURE_ARGS+="$DIR/$3/$1.elf $DIR/$3/$1.bc"
elif [ "$2" == "fracture" ]; then
	TARGET='fracture-cl'
	FRACTURE_ARGS+="$DIR/$3/$1.elf"
else
	echo "Unknown mode ... $2"
	help
fi

#printf "%s" "Checking arguments...                        "
#if echo "$SAMPLES" | grep -q "$1"; then
#	printf "%s\n" "--> ok"
#else
#	printf "%s\n" "--> failed"
#	exit 1
#fi

printf "%s" "Cleaning directory  ...                      "
clean
printf "%s\n" "--> ok"

#printf "%s" "Compiling assembly to binary ...             "
#arm-none-eabi-as $AS_ARGS -g ./$1/$1.s -o ./$1/$1.o
#if [ $? != 0 ]; then
#	printf "%s\n" "--> failed"
#	exit 1;
#fi
#printf "%s\n" "--> ok"
#
printf "%s" "Compiling C Source to LLVM IR ...            "
$CLANG $CLANG_ARGS -emit-llvm -I/usr/arm-linux-gnueabihf/include/ -I/usr/include/newlib/ -c -g ./$3/$1.c -o ./$3/$1.bc
if [ $? != 0 ]; then
	printf "%s\n" "--> failed"
	exit 1;
fi
printf "%s\n" "--> ok"

printf "%s" "Compiling source to IR human readable ...    "
$CLANG $CLANG_ARGS -emit-llvm -S -I/usr/arm-linux-gnueabihf/include/ -I/usr/include/newlib/ -c -g ./$3/$1.c -o ./$3/$1.ll
if [ $? != 0 ]; then
	printf "%s\n" "--> failed"
	exit 1;
fi
printf "%s\n" "--> ok"

printf "%s" "Compiling C source code to object file ...    "
arm-none-eabi-gcc $GCC_ARGS -g -c ./$3/$1.c -o ./$3/$1.o
if [ $? != 0 ]; then
	printf "%s\n" "--> failed"
	exit 1;
fi
printf "%s\n" "--> ok"

printf "%s" "Linking object files ...                      "
arm-none-eabi-ld -T ./link.ld ./$3/$1.o -o ./$3/$1.elf
if [ $? != 0 ]; then
	printf "%s\n" "--> failed"
	exit 1;
fi
printf "%s\n" "--> ok"

printf "%s" "Creating binary format output ...             "
arm-none-eabi-objcopy -O binary ./$3/$1.elf ./$3/$1.bin
if [ $? != 0 ]; then
	printf "%s\n" "--> failed"
	exit 1;
fi
printf "%s\n" "--> ok"

#if [ $PRINT_GRAPHS = true ]; then
#	PRINT_ARGS='-view-machine-dags -view-ir-dags -print-graph'
#else
        PRINT_ARGS=''
##fi

$TARGET_PATH/$TARGET $PRINT_ARGS $FRACTURE_ARGS 2>&1 >/dev/null
if [ $? != 0 ]; then
	printf "%s\n" "--> $1 fracture failed"
	exit 1;
fi
printf "%s\n" "--> ok"


$LLVM_AS ./$3/$1.elf.ll -o ./$3/$1_merged.bc
if [ $? != 0 ]; then
	printf "%s\n" "--> $1 llvm-as failed"
	exit 1;
fi
printf "%s\n" "--> ok"


