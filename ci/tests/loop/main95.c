#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8, #0"); 
  __asm volatile("outer_loop:"); 
  __asm volatile("mov R0, #100"); 
  __asm volatile("loop:"); 
  __asm volatile("add R0,R0,#-1"); 
  __asm volatile("cmp R0,#0"); 
  __asm volatile("beq loop"); 
  __asm volatile("add R8,R8,#1"); 
  __asm volatile("cmp R8,#0x100"); 
  __asm volatile("bls outer_loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
