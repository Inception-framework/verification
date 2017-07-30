#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3, #0"); 
  __asm volatile("loop:"); 
  __asm volatile("add R3,R3,#1"); 
  __asm volatile("cmp R3,#0x100"); 
  __asm volatile("bhs loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
