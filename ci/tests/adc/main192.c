#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xb7"); 
  __asm volatile("ADC R9, R0, #0xfa");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
