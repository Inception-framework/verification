#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x60"); 
  __asm volatile("ADDS R4, R2, #0x5f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
