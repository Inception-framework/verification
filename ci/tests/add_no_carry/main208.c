#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xdc"); 
  __asm volatile("mov R9,#0xe8"); 
  __asm volatile("ADDS R0, R10, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
