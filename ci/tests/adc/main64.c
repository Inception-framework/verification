#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x37"); 
  __asm volatile("ADC R4, R6, #0x32");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
