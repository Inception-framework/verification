#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x93"); 
  __asm volatile("ADCS R8, R3, #0xe3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
