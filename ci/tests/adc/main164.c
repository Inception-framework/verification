#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x03"); 
  __asm volatile("ADC R4, R10, #0x47");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
