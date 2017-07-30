#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4, #0"); 
  __asm volatile("outer_loop:"); 
  __asm volatile("mov R12, #100"); 
  __asm volatile("loop:"); 
  __asm volatile("add R12,R12,#-1"); 
  __asm volatile("cmp R12,#0"); 
  __asm volatile("bne loop"); 
  __asm volatile("add R4,R4,#1"); 
  __asm volatile("cmp R4,#0x100"); 
  __asm volatile("bhs outer_loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
