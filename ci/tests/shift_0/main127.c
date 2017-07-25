#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xfb"); 
  __asm volatile("ROR R12, R12, 4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
