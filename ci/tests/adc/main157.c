#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x19"); 
  __asm volatile("ADCS R9, R11, #0xc6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
