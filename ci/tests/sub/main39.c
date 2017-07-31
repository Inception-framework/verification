#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0"); 
  __asm volatile("add R5,R5,#0x28"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0xfa"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0xfd"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x04"); 
  __asm volatile("SUB R11, R5, #0x72");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
