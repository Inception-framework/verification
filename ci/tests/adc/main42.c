#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xe5"); 
  __asm volatile("mov R6,#0xd4"); 
  __asm volatile("ADC R3, R10, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
