#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x72"); 
  __asm volatile("ADDS R2, R3, #0xe5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
