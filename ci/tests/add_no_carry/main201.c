#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xda"); 
  __asm volatile("mov R12,#0xfb"); 
  __asm volatile("ADD R12, R6, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
