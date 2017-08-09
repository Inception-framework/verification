#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9, #0"); 
  __asm volatile("outer_loop:"); 
  __asm volatile("mov R7, #100"); 
  __asm volatile("loop:"); 
  __asm volatile("add R7,R7,#-1"); 
  __asm volatile("cmp R7,#0"); 
  __asm volatile("bge loop"); 
  __asm volatile("add R9,R9,#1"); 
  __asm volatile("cmp R9,#0x100"); 
  __asm volatile("bgt outer_loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
