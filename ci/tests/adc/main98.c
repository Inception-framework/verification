#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xef"); 
  __asm volatile("mov R9,#0xac"); 
  __asm volatile("ADC R9, R11, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
