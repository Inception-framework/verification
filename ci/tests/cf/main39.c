#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R10,#3"); 
  __asm volatile("mov R0,#-1"); 
  __asm volatile("cmp R10,R0"); 
  __asm volatile("bcc bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R9,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R2,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R12,#3"); 
  __asm volatile("cmp R10,R0"); 
  __asm volatile("bcc end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
