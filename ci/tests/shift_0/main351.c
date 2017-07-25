#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x16"); 
  __asm volatile("ROR R9, R3, 14");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
