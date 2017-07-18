#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xfa"); 
  __asm volatile("ADDS R3, R7, #0xa2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
