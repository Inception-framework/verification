#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x82"); 
  __asm volatile("ADC R8, R9, #0xaa");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
