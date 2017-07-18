#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xa7"); 
  __asm volatile("ADC R4, R8, #0x5e");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
