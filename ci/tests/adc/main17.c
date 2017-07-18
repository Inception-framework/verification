#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xc8"); 
  __asm volatile("ADCS R1, R11, #0x8d");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
