#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x05"); 
  __asm volatile("mov R3,#0xbb"); 
  __asm volatile("ADC R5, R2, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
