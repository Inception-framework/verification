#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x0a"); 
  __asm volatile("ADC R2, R9, #0xc9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
