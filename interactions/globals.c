static int global;
int global2;

typedef struct{
  int a;
  int b;
} mytype;

mytype global_struct;
int ptr = &global_struct;

__attribute__((naked))
void foo(int g){
  __asm volatile("mov r7,sp");
  __asm volatile("str r0,[r7]");
  __asm volatile("ldr r1,[r0]");
  __asm volatile("add r1,r1,#1");
  __asm volatile("str r1,[r0]");
  __asm volatile("bx lr");
}

__attribute__((naked))
void bar(int g){
  __asm volatile("ldr r2,[r0]");
  __asm volatile("add r2,r2,#1");
  __asm volatile("str r2,[r0]");
  __asm volatile("bx lr");
}

__attribute__((naked))
void mario(void){
  __asm volatile("mov %[dest], %[value]" : [dest] "=w" (global2) : [value] "r" (global)  );
  //__asm volatile("mov r12,pc");
  __asm volatile("bx lr");
}


void main(void){
  //#ifndef NOPRINT
  //klee_define_fixed_object(0x20000000,2050*4);
  //#endif
  int i = 1;
  global = 1;
  global2 = 0;
  global_struct.a = 1;
  global_struct.b = 2;
  mario();
  foo(&global);
  bar(ptr);
  #ifndef NOPRINT
  //klee_make_symbolic(&STACK,sizeof(STACK),"STACK");
  //printf("%d\n",STACK[1024]);
  printf("%08x %d\n",&global,global);
  printf("%08x %d\n",&global2,global2);
  printf("%08x %d\n",&global_struct.a,global_struct.a);
  #endif
}
