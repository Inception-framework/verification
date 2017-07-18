#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x93"); 
  __asm volatile("mov R3,#0x35"); 
  __asm volatile("ADCS R2, R12, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
