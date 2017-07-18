#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xfe"); 
  __asm volatile("mov R6,#0x13"); 
  __asm volatile("ADC R1, R11, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
