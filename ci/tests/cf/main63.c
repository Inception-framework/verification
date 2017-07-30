#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R0,#-4"); 
  __asm volatile("mov R8,#3"); 
  __asm volatile("cmp R0,R8"); 
  __asm volatile("bpl bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R2,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R9,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R4,#3"); 
  __asm volatile("cmp R0,R8"); 
  __asm volatile("bpl bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
