#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x94"); 
  __asm volatile("ADDS R2, R2, #0xb8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
