#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x41"); 
  __asm volatile("ADDS R0, R2, #0x7a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
