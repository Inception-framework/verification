#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x56"); 
  __asm volatile("ADC R11, R7, #0x68");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
