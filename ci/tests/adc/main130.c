#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x2c"); 
  __asm volatile("mov R7,#0x68"); 
  __asm volatile("ADC R7, R10, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
