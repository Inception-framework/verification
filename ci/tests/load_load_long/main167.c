#include <stdlib.h>
int STACK[2050];__attribute__((naked))
void foo(void){
  #ifndef KLEE
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("add r1,r1,#1025");
  __asm volatile("mov r2,sp");
  __asm volatile("loop:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  __asm volatile("add r2,#1025");
  __asm volatile("lsl r2,#2");
  __asm volatile("add r2,sp");
  __asm volatile("loop2:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop2");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  #endif
  __asm volatile("mov R4,sp"); 
  __asm volatile("mov R0,#0x34"); 
  __asm volatile("mov R1,#0x06"); 
  __asm volatile("mov R2,#0xd0"); 
  __asm volatile("mov R3,#0x5d"); 
  __asm volatile("mov R6,#0x51"); 
  __asm volatile("mov R7,#0x47"); 
  __asm volatile("mov R8,#0x40"); 
  __asm volatile("mov R9,#0x00"); 
  __asm volatile("mov R11,#0x6b"); 
  __asm volatile("mov R12,#0x54"); 
  __asm volatile("mov R14,#0x94"); 
  __asm volatile("LDRB R9, [R4, +R11]");
  __asm volatile("mov R0,#0x7f"); 
  __asm volatile("mov R1,#0x6e"); 
  __asm volatile("mov R2,#0x8f"); 
  __asm volatile("mov R3,#0xc7"); 
  __asm volatile("mov R6,#0x24"); 
  __asm volatile("mov R7,#0xe3"); 
  __asm volatile("mov R8,#0x43"); 
  __asm volatile("mov R9,#0x02"); 
  __asm volatile("mov R11,#0x6e"); 
  __asm volatile("mov R12,#0x55"); 
  __asm volatile("mov R14,#0xa0"); 
  __asm volatile("LDRB R9, [R4, +R11]");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
void main(void){
  int i;  for(i=0;i<2050;i++){
      STACK[2050-1-i]=i;
  }
  foo();
}
