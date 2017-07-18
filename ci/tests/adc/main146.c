#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xa2"); 
  __asm volatile("mov R7,#0x1e"); 
  __asm volatile("ADC R7, R7, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
