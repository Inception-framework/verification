#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x45"); 
  __asm volatile("ADDS R8, R4, #0x7a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
