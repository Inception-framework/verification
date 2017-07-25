#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xea"); 
  __asm volatile("mov R11,#0x05"); 
  __asm volatile("ROR R9, R10, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
