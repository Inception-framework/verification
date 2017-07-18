#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xb0"); 
  __asm volatile("mov R11,#0x84"); 
  __asm volatile("ADC R1, R7, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
