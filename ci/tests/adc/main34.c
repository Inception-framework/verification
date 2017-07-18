#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x3c"); 
  __asm volatile("mov R9,#0xe2"); 
  __asm volatile("ADC R8, R4, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
