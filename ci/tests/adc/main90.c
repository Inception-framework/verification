#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x1f"); 
  __asm volatile("mov R2,#0x41"); 
  __asm volatile("ADC R12, R6, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
