#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x43"); 
  __asm volatile("ADCS R11, R1, #0xd7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
