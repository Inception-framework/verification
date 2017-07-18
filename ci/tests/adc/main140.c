#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x94"); 
  __asm volatile("ADC R1, R6, #0x90");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
