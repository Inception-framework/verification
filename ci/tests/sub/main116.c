#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0"); 
  __asm volatile("add R11,R11,#0xe6"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xb9"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x20"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xda"); 
  __asm volatile("SUB R6, R11, #0xe1f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
