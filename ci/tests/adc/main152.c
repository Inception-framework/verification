#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xa9"); 
  __asm volatile("ADC R7, R11, #0xc4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
