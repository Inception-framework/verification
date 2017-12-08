=======================================================

Date: 08/12/2017 11:00 am

Analyzer:->  thread_support_rebased
commit 41ea9eaed20e907ff8dfc525bd188c2e6d668a46

Compile:-> dissassemble_more_rebased_on_jtag_basepri
commit 003cb26d6813d04151c41d26c1ae770f2110ed1c


Inception-compiler-verif->master
commit 887c188c6289f84cfe635a62702fd2892522f047

./ci.sh -t add_full32 -f LR,CPSR,.stack,SP,PC
1008 ci/add_full32.passed

./ci.sh -t shift_full32 -f LR,CPSR,.stack,SP,PC
1008 ci/shift_full32.passed

./ci.sh -t single_load_full32 -f LR,CPSR,.stack,SP,PC
900 ci/single_load_full32.passed

./ci.sh -t cmpcmn_full32 -f LR,CPSR,.stack,SP,PC
1000 ci/cmpcmn_full32.passed

./ci.sh -t store_full32 -f LR,CPSR,.stack,PC
300 ci/store_full32.passed

./ci.sh -t it_cf -f LR,CPSR,.stack,PC
945 ci/it_cf.passed

./ci.sh -t add_extra -f LR,CPSR,.stack,PC

./ci.sh -t sub_full32 -f LR,CPSR,.stack,SP,PC
1008 ci/sub_full32.passed

./ci.sh -t div -f LR,CPSR,.stack,PC,SP
1000 ci/div.passed

./ci.sh -t it_add -f LR,CPSR,.stack,SP,PC

./ci.sh -t it_flags1 -f LR,CPSR,.stack,SP,PC
1920 ci/it_flags1.passed

./ci.sh -t it_flags2 -f LR,CPSR,.stack,SP,PC
1920 ci/it_flags2.passed

./ci.sh -t logical -f LR,CPSR,.stack,SP,PC
3600 ci/logical.passed

./ci.sh -t mov -f LR,CPSR,.stack,SP,PC
1950 ci/mov.passed

./ci.sh -t mul_mbedtls -f LR,CPSR,.stack,SP,PC
1000 ci/mul_mbedtls.passed

./ci.sh -t rsb_all -f LR,CPSR,.stack,SP,PC
1000 ci/rsb_all.passed

./ci.sh -t loop -f LR,CPSR,.stack,SP,PC
300 ci/loop.passed

./ci.sh -t misc -f LR,CPSR,.stack,SP,PC
1200 ci/misc.passed

./ci.sh -t extend -f LR,CPSR,.stack,SP,PC
800 ci/extend.passed

./ci.sh -t fib -f LR,CPSR,.stack,SP,PC
100 ci/fib.passed
