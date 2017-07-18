#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xb5"); 
  __asm volatile("ADCS R8, R1, #0xde");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
