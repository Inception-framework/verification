#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xfe"); 
  __asm volatile("ADCS R12, R3, #0x6d");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
