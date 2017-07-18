#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xf3"); 
  __asm volatile("mov R3,#0xac"); 
  __asm volatile("ADC R4, R11, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
