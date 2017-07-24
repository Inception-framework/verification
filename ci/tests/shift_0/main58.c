#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xd4"); 
  __asm volatile("mov R3,#0x06"); 
  __asm volatile("LSR R7, R0, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
