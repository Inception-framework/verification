#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10, #0"); 
  __asm volatile("outer_loop:"); 
  __asm volatile("mov R1, #100"); 
  __asm volatile("loop:"); 
  __asm volatile("add R1,R1,#-1"); 
  __asm volatile("cmp R1,#0"); 
  __asm volatile("bne loop"); 
  __asm volatile("add R10,R10,#1"); 
  __asm volatile("cmp R10,#0x100"); 
  __asm volatile("bgt outer_loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
