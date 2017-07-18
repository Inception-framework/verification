#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xde"); 
  __asm volatile("mov R2,#0xe5"); 
  __asm volatile("ADDS R10, R10, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
