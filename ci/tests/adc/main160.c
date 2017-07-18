#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x91"); 
  __asm volatile("ADC R11, R8, #0xb4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
