#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x01"); 
  __asm volatile("mov R4,#0x95"); 
  __asm volatile("ADC R0, R1, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
