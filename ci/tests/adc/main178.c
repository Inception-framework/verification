#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xde"); 
  __asm volatile("mov R1,#0x92"); 
  __asm volatile("ADC R5, R5, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
