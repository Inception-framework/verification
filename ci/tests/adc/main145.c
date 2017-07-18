#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xf2"); 
  __asm volatile("ADCS R5, R10, #0xd4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
