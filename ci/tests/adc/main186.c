#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xf5"); 
  __asm volatile("mov R4,#0x57"); 
  __asm volatile("ADC R5, R10, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
