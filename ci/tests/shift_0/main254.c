#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x53"); 
  __asm volatile("mov R10,#0x1d"); 
  __asm volatile("ROR R8, R10, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
