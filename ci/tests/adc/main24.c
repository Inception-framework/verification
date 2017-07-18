#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x25"); 
  __asm volatile("ADC R9, R10, #0x0d");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
