#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x71"); 
  __asm volatile("mov R9,#0xcb"); 
  __asm volatile("ADDS R12, R6, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
