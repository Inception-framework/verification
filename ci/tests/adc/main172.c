#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xfd"); 
  __asm volatile("ADC R0, R7, #0xe0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
