typedef struct {
  int a;
  int b;
} my_type;

__attribute__((naked))
void foo(my_type* mt){
  __asm volatile("ldr r1,[r0]");
  __asm volatile("add r1,r1,#1");
  __asm volatile("str r1,[r0]");
  __asm volatile("str r1,[r0,#4]");
  __asm volatile("bx lr");
}

void main(void){
 int i = 0;
 //#ifndef NOPRINT
 //klee_make_symbolic(&global,sizeof global,"global");
 //#endif
 my_type my_thing;
 my_thing.a = 0;
 foo(&my_thing);
 #ifndef NOPRINT
 printf("my_thing .a=%d .b=%d\n",my_thing.a,my_thing.b);
 #endif
}
