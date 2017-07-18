#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xfb"); 
  __asm volatile("ADCS R12, R12, #0x38");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
