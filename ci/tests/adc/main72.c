#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xb7"); 
  __asm volatile("ADC R6, R3, #0x3a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
