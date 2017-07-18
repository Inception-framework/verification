#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x90"); 
  __asm volatile("ADC R10, R11, #0x71");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
