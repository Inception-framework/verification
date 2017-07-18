#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x3b"); 
  __asm volatile("ADC R4, R7, #0x83");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
