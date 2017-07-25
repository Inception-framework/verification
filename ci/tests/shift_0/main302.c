#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xd9"); 
  __asm volatile("mov R4,#0x1f"); 
  __asm volatile("ROR R1, R8, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
