#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x35"); 
  __asm volatile("mov R3,#0xea"); 
  __asm volatile("ADCS R9, R2, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
