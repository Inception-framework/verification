#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x12"); 
  __asm volatile("mov R1,#0x86"); 
  __asm volatile("ADC R9, R1, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
