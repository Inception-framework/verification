#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0"); 
  __asm volatile("add R7,R7,#0x6a"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0xf9"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x44"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0xe0"); 
  __asm volatile("SUB R0, R7, #0xfbd");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
