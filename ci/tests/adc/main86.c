#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xd5"); 
  __asm volatile("mov R7,#0xc6"); 
  __asm volatile("ADC R4, R8, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
