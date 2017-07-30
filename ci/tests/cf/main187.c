#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R7,#1"); 
  __asm volatile("mov R10,#-4"); 
  __asm volatile("cmp R7,R10"); 
  __asm volatile("blo bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R5,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R1,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R2,#3"); 
  __asm volatile("cmp R7,R10"); 
  __asm volatile("blo bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
