#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x11"); 
  __asm volatile("mov R12,#0x0b"); 
  __asm volatile("ROR R10, R8, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
