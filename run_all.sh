#!/bin/bash
# Authors: Giovanni Camurati, Nassim Corteggiani

./versioning.sh $1

echo "" >> $1
echo "" >> $1

./ci.sh -t add_full32 -f LR,CPSR,.stack,SP,PC  >> $1

./ci.sh -t shift_full32 -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t cmpcmn_full32 -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t it_cf -f LR,CPSR,.stack,PC >> $1

./ci.sh -t add_extra -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t sub_full32 -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t div -f LR,CPSR,.stack,PC,SP >> $1

./ci.sh -t it_add -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t it_flags1 -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t it_flags2 -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t logical -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t mov -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t mul_mbedtls -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t rsb_all -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t loop -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t misc -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t extend -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t fib -f LR,CPSR,.stack,SP,PC >> $1

./ci.sh -t single_load_full32 -f LR,CPSR,.stack,PC >> $1

./ci.sh -t store_spi -f LR,CPSR,.stack,PC >> $1

#./ci.sh -t store_full32 -f LR,CPSR,.stack,PC >> $1


