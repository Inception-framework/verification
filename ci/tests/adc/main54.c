#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x15"); 
  __asm volatile("mov R0,#0x69"); 
  __asm volatile("ADC R4, R0, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
