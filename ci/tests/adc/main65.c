#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xaf"); 
  __asm volatile("ADCS R7, R5, #0x3f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
