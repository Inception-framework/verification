#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xab"); 
  __asm volatile("ADC R7, R9, #0x61");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
