#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x2b"); 
  __asm volatile("mov R2,#0xba"); 
  __asm volatile("ADC R3, R10, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
