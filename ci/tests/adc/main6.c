#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x68"); 
  __asm volatile("mov R8,#0xf4"); 
  __asm volatile("ADC R9, R10, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
