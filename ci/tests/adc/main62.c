#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x7a"); 
  __asm volatile("mov R0,#0x9d"); 
  __asm volatile("ADC R7, R11, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
