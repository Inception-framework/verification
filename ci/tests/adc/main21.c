#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x8a"); 
  __asm volatile("ADCS R0, R11, #0x3b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
