#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x00"); 
  __asm volatile("ADDS R8, R9, #0x13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
