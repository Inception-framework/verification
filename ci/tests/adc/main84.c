#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xbe"); 
  __asm volatile("ADC R10, R7, #0xc3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
