#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xe4"); 
  __asm volatile("mov R8,#0xf9"); 
  __asm volatile("ADD R11, R2, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
