#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xef"); 
  __asm volatile("ADC R6, R6, #0x47");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
