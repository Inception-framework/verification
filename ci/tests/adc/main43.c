#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xd6"); 
  __asm volatile("mov R12,#0x17"); 
  __asm volatile("ADCS R6, R11, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
