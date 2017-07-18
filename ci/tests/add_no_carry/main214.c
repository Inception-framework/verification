#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xe8"); 
  __asm volatile("ADD R8, R3, #0x62b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
