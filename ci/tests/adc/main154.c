#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xa1"); 
  __asm volatile("mov R2,#0x6a"); 
  __asm volatile("ADC R11, R2, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
