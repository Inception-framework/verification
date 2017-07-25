#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xb1"); 
  __asm volatile("mov R1,#0x0a"); 
  __asm volatile("LSR R2, R10, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
