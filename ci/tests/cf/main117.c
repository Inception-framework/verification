#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R9,#0"); 
  __asm volatile("mov R3,#-1"); 
  __asm volatile("cmp R9,R3"); 
  __asm volatile("bvs bb2"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R4,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R5,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R0,#3"); 
  __asm volatile("cmp R9,R3"); 
  __asm volatile("bvs end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
