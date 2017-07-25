#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x18"); 
  __asm volatile("ROR R11, R3, 10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
