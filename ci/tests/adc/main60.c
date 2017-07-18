#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x4c"); 
  __asm volatile("ADC R4, R2, #0x94");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
