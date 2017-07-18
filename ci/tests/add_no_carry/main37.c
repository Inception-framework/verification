#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x33"); 
  __asm volatile("ADDS R0, R9, #0xc8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
