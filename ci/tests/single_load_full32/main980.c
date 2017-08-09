#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3, #0"); 
  __asm volatile("outer_loop:"); 
  __asm volatile("mov R11, #100"); 
  __asm volatile("loop:"); 
  __asm volatile("add R11,R11,#-1"); 
  __asm volatile("cmp R11,#0"); 
  __asm volatile("bls loop"); 
  __asm volatile("add R3,R3,#1"); 
  __asm volatile("cmp R3,#0x100"); 
  __asm volatile("bhi outer_loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
