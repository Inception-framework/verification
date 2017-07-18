#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x95"); 
  __asm volatile("mov R0,#0x46"); 
  __asm volatile("ADDS R6, R9, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
