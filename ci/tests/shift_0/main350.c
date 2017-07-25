#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x40"); 
  __asm volatile("mov R0,#0x0b"); 
  __asm volatile("ROR R0, R2, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
