#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2, #0"); 
  __asm volatile("outer_loop:"); 
  __asm volatile("mov R5, #100"); 
  __asm volatile("loop:"); 
  __asm volatile("add R5,R5,#-1"); 
  __asm volatile("cmp R5,#0"); 
  __asm volatile("bls loop"); 
  __asm volatile("add R2,R2,#1"); 
  __asm volatile("cmp R2,#0x100"); 
  __asm volatile("bgt outer_loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
