#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x57"); 
  __asm volatile("mov R5,#0xda"); 
  __asm volatile("ADC R5, R12, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
