#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xb5"); 
  __asm volatile("mov R7,#0x2c"); 
  __asm volatile("ADD R8, R2, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
