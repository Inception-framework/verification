#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xf6"); 
  __asm volatile("mov R8,#0xa0"); 
  __asm volatile("ADC R12, R11, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
