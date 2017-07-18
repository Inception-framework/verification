#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x85"); 
  __asm volatile("mov R7,#0x23"); 
  __asm volatile("ADDS R0, R9, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
