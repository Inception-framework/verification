#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x48"); 
  __asm volatile("mov R9,#0xd8"); 
  __asm volatile("ADC R8, R6, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
