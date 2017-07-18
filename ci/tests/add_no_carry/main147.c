#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x84"); 
  __asm volatile("ADDS R5, R11, #0x42");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
