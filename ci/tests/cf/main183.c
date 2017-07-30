#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R1,#2"); 
  __asm volatile("mov R10,#2"); 
  __asm volatile("cmp R1,R10"); 
  __asm volatile("bvs bb1"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R3,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R4,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R9,#3"); 
  __asm volatile("cmp R1,R10"); 
  __asm volatile("bvs bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
