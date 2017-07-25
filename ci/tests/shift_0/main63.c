#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x61"); 
  __asm volatile("ROR R9, R1, 4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
