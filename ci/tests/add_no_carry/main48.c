#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xb4"); 
  __asm volatile("mov R9,#0x93"); 
  __asm volatile("ADDS R12, R7, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
