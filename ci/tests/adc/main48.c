#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xd5"); 
  __asm volatile("ADC R6, R10, #0xa1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
