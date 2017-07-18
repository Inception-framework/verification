#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x28"); 
  __asm volatile("ADCS R7, R11, #0xab");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
