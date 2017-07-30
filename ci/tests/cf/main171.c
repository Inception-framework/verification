#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R3,#2"); 
  __asm volatile("mov R12,#0"); 
  __asm volatile("cmp R3,R12"); 
  __asm volatile("bpl bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R10,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R1,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R7,#3"); 
  __asm volatile("cmp R3,R12"); 
  __asm volatile("bpl end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
