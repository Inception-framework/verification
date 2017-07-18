#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x77"); 
  __asm volatile("mov R12,#0xc4"); 
  __asm volatile("ADC R11, R2, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
