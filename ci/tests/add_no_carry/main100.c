#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xa5"); 
  __asm volatile("ADD R8, R7, #0xff");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
