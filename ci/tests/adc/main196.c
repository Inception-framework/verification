#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xc4"); 
  __asm volatile("ADC R12, R4, #0x1e");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
