#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2, #0"); 
  __asm volatile("outer_loop:"); 
  __asm volatile("mov R1, #100"); 
  __asm volatile("loop:"); 
  __asm volatile("add R1,R1,#-1"); 
  __asm volatile("cmp R1,#0"); 
  __asm volatile("bge loop"); 
  __asm volatile("add R2,R2,#1"); 
  __asm volatile("cmp R2,#0x100"); 
  __asm volatile("bcc outer_loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
