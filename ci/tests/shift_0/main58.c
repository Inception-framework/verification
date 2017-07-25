#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xef"); 
  __asm volatile("LSR R5, R4, 4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
