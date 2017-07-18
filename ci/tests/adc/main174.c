#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x29"); 
  __asm volatile("mov R3,#0x32"); 
  __asm volatile("ADC R1, R1, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
