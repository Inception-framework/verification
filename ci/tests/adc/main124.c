#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x1d"); 
  __asm volatile("ADC R10, R8, #0xc0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
