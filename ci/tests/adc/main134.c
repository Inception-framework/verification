#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xcf"); 
  __asm volatile("mov R4,#0x0b"); 
  __asm volatile("ADC R12, R3, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
