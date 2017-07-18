#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x00"); 
  __asm volatile("mov R11,#0x5d"); 
  __asm volatile("ADCS R12, R0, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
