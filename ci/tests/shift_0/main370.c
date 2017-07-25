#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x90"); 
  __asm volatile("LSR R3, R10, 22");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
