#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xcb"); 
  __asm volatile("ADD R0, R4, #0xcad");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
