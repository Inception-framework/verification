#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xb1"); 
  __asm volatile("ADCS R1, R3, #0x60");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
