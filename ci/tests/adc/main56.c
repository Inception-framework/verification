#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xea"); 
  __asm volatile("ADC R11, R10, #0xde");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
