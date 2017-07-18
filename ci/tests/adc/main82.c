#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x21"); 
  __asm volatile("mov R3,#0x42"); 
  __asm volatile("ADC R8, R0, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
