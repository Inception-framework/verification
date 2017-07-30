#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R3,#4"); 
  __asm volatile("mov R12,#-1"); 
  __asm volatile("cmp R3,R12"); 
  __asm volatile("bvs bb2"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R1,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R9,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R6,#3"); 
  __asm volatile("cmp R3,R12"); 
  __asm volatile("bvs end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
