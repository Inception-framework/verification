#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xff"); 
  __asm volatile("mov R7,#0x67"); 
  __asm volatile("ADC R10, R5, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
