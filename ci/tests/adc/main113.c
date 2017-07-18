#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x48"); 
  __asm volatile("ADCS R9, R3, #0x5f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
