#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xe4"); 
  __asm volatile("mov R1,#0x75"); 
  __asm volatile("mov R4,#0xa2"); 
  __asm volatile("mov R7,#0x0b"); 
  __asm volatile("mov R8,#0x04"); 
  __asm volatile("mov R10,#0x6e"); 
  __asm volatile("mov R11,#0x0e"); 
  __asm volatile("mov R12,#0xe0"); 
  __asm volatile("mov R14,#0x77"); 
  __asm volatile("LDRB R4, [R2]!");
  __asm volatile("mov R0,#0x88"); 
  __asm volatile("mov R1,#0x34"); 
  __asm volatile("mov R4,#0x0f"); 
  __asm volatile("mov R7,#0x0d"); 
  __asm volatile("mov R8,#0xc3"); 
  __asm volatile("mov R10,#0xd8"); 
  __asm volatile("mov R11,#0x71"); 
  __asm volatile("mov R12,#0xfd"); 
  __asm volatile("mov R14,#0xb0"); 
  __asm volatile("LDRB R4, [R2]!");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
