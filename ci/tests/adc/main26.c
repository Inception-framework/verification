#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x12"); 
  __asm volatile("mov R9,#0x0b"); 
  __asm volatile("ADC R5, R1, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
