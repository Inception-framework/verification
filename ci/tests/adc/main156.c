#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x64"); 
  __asm volatile("ADC R11, R3, #0xe0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
