#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xce"); 
  __asm volatile("mov R11,#0x8e"); 
  __asm volatile("ADC R10, R8, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
