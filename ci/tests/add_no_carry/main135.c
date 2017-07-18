#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xda"); 
  __asm volatile("ADD R1, R2, #0xd8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
