#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x73"); 
  __asm volatile("LSR R0, R0, 21");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
