#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R5,#-2"); 
  __asm volatile("mov R0,#-1"); 
  __asm volatile("cmp R5,R0"); 
  __asm volatile("blt bb2"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R1,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R7,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R3,#3"); 
  __asm volatile("cmp R5,R0"); 
  __asm volatile("blt end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
