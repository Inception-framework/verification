#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xc8"); 
  __asm volatile("ADC R5, R7, #0x05");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
