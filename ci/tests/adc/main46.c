#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xef"); 
  __asm volatile("mov R0,#0xd4"); 
  __asm volatile("ADC R5, R4, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
