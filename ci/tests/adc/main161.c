#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xdc"); 
  __asm volatile("ADCS R7, R0, #0xe8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
