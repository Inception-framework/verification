#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0"); 
  __asm volatile("add R5,R5,#0xe8"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x7a"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x16"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x13"); 
  __asm volatile("SUB R7, R5, #0x474");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
