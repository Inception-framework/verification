#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R2,#5"); 
  __asm volatile("mov R12,#3"); 
  __asm volatile("cmp R2,R12"); 
  __asm volatile("bhi bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R4,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R10,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R1,#3"); 
  __asm volatile("cmp R2,R12"); 
  __asm volatile("bhi bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
