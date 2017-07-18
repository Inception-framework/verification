#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xc5"); 
  __asm volatile("mov R5,#0x7b"); 
  __asm volatile("ADC R9, R12, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
