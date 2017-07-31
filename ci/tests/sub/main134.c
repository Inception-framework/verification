#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0"); 
  __asm volatile("add R10,R10,#0x4c"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x88"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xb9"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xd8"); 
  __asm volatile("SUB R8, R10, #0xf20");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
