#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x80"); 
  __asm volatile("ADC R6, R10, #0x4e");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
