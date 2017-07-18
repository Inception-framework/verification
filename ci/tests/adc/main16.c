#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x42"); 
  __asm volatile("ADC R1, R1, #0x4c");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
