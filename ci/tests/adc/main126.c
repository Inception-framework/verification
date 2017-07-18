#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xf1"); 
  __asm volatile("mov R1,#0x5e"); 
  __asm volatile("ADC R5, R4, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
