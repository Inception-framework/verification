#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xd4"); 
  __asm volatile("mov R12,#0x4f"); 
  __asm volatile("ADC R1, R1, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
