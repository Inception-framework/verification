#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xfb"); 
  __asm volatile("ADC R6, R2, #0x29");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
