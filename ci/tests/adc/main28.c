#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xd9"); 
  __asm volatile("ADC R10, R0, #0x33");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
