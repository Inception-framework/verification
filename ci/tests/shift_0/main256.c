#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xfb"); 
  __asm volatile("mov R10,#0x04"); 
  __asm volatile("LSR R5, R0, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
