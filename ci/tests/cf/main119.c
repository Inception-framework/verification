#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R3,#5"); 
  __asm volatile("mov R1,#4"); 
  __asm volatile("cmp R3,R1"); 
  __asm volatile("beq bb2"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R12,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R9,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R0,#3"); 
  __asm volatile("cmp R3,R1"); 
  __asm volatile("beq end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
