#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x81"); 
  __asm volatile("ADC R7, R5, #0x28");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
