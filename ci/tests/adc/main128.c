#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xd7"); 
  __asm volatile("ADC R2, R12, #0xdd");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
