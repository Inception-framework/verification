#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xd6"); 
  __asm volatile("mov R9,#0x8c"); 
  __asm volatile("ADC R3, R10, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
