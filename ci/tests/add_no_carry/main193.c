#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x3b"); 
  __asm volatile("mov R9,#0x01"); 
  __asm volatile("ADDS R5, R0, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
