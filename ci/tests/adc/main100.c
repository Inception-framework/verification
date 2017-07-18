#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x3e"); 
  __asm volatile("ADC R12, R4, #0x60");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
