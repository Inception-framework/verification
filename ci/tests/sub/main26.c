#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0"); 
  __asm volatile("add R3,R3,#0xad"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xe9"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xb2"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xb4"); 
  __asm volatile("SUB R7, R3, #0xd9e");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
