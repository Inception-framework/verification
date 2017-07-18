#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x65"); 
  __asm volatile("mov R4,#0x8f"); 
  __asm volatile("ADC R1, R9, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
