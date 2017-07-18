#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x37"); 
  __asm volatile("ADDS R1, R2, #0x8d");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
