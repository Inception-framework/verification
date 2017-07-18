#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x20"); 
  __asm volatile("mov R3,#0x71"); 
  __asm volatile("ADD R11, R5, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
