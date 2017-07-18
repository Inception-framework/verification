#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x84"); 
  __asm volatile("ADC R7, R1, #0x50");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
