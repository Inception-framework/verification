#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xf1"); 
  __asm volatile("ADCS R6, R11, #0x2f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
