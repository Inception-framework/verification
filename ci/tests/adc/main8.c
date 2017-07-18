#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x00"); 
  __asm volatile("ADC R11, R6, #0xfc");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
