#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x3a"); 
  __asm volatile("ADC R8, R4, #0x4a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
