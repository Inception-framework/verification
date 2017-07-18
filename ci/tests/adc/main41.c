#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xab"); 
  __asm volatile("ADCS R9, R3, #0x51");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
