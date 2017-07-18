#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x96"); 
  __asm volatile("ADC R11, R0, #0xbc");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
