#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x6f"); 
  __asm volatile("mov R8,#0x47"); 
  __asm volatile("ADC R5, R9, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
