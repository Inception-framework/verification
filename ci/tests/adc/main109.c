#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xb7"); 
  __asm volatile("ADCS R1, R1, #0x0f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
