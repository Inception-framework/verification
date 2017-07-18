#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x72"); 
  __asm volatile("mov R5,#0x7c"); 
  __asm volatile("ADC R2, R2, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
