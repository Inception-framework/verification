#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x9a"); 
  __asm volatile("mov R4,#0xc4"); 
  __asm volatile("ADC R4, R10, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
