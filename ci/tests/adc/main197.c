#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x7f"); 
  __asm volatile("ADCS R0, R5, #0xaf");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
