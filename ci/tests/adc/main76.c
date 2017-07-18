#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x4d"); 
  __asm volatile("ADC R5, R8, #0x35");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
