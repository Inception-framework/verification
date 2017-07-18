#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xea"); 
  __asm volatile("ADDS R1, R3, #0xc1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
