#define USE_STD_LIB 1

#line 0 "boilerplate.hpp"
typedef unsigned long long int u64;
typedef signed long long int s64;

typedef signed int s32;
typedef unsigned int u32;

typedef double f64;
typedef float f32;

typedef short int s16;
typedef unsigned short int u16;

typedef signed char s8;
typedef unsigned char u8;
#include <stddef.h>

#if USE_STD_LIB
#include <errno.h>
#include <stdint.h>
#undef RAND_MAX
#endif

#ifdef TESTING
#if TEST_VERBOSE
int printf(u8 *, ...);
#endif

typedef struct {
  const char *name;
  void (*function)();
} $ela_test;

static void $ela_test_run($ela_test *test) {
#if TEST_VERBOSE
  printf("running %s\n", test->name);
#endif
  test->function();
}

#endif

typedef struct Type Type;
typedef struct List$38 List$38;
extern List$38 _type_info;
typedef struct Type Type;

#line 8 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct str {
  u8 *data;
  u64 length;
} str;

#line 16 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct String {
  u8 *data;
  u64 length;
  u64 capacity;
} String;

#line 25 "/usr/local/lib/ela/bootstrap/libc.ela"
extern u8 *strdup(u8 *);
typedef struct str str;

#line 47 "/usr/local/lib/ela/bootstrap/libc.ela"
extern u32 strlen(u8 *);
#line 27 "/usr/local/lib/ela/bootstrap/range.ela"
typedef struct Range_Enumerator$1 {
  s32 begin;
  s32 end;
  s32 idx;
} Range_Enumerator$1;

#line 4 "/usr/local/lib/ela/bootstrap/range.ela"
typedef struct Range_Base$1 {
  s32 begin;
  s32 end;
} Range_Base$1;
typedef struct Range_Base$1 Range_Base$1;

#line 46 "/usr/local/lib/ela/bootstrap/range.ela"
Range_Enumerator$1 $53_enumerator(Range_Base$1 *self)
#line 46 "/usr/local/lib/ela/bootstrap/range.ela"
{

#line 47 "/usr/local/lib/ela/bootstrap/range.ela"

#line 47 "/usr/local/lib/ela/bootstrap/range.ela"
  return (Range_Enumerator$1){
      .begin = (s32)self->begin, .end = (s32)self->end, .idx = (s32)0};
  ;
}
#line 40 "/usr/local/lib/ela/bootstrap/range.ela"
bool $85_done(Range_Enumerator$1 self)
#line 40 "/usr/local/lib/ela/bootstrap/range.ela"
{

#line 41 "/usr/local/lib/ela/bootstrap/range.ela"

#line 41 "/usr/local/lib/ela/bootstrap/range.ela"
  return (self.idx >= self.end);
  ;
}
#line 34 "/usr/local/lib/ela/bootstrap/range.ela"
s32 $85_current(Range_Enumerator$1 self)
#line 34 "/usr/local/lib/ela/bootstrap/range.ela"
{

#line 35 "/usr/local/lib/ela/bootstrap/range.ela"

#line 35 "/usr/local/lib/ela/bootstrap/range.ela"
  return self.idx;
  ;
}
typedef struct Range_Enumerator$1 Range_Enumerator$1;

#line 37 "/usr/local/lib/ela/bootstrap/range.ela"
void $85_next(Range_Enumerator$1 *self)
#line 37 "/usr/local/lib/ela/bootstrap/range.ela"
{

#line 38 "/usr/local/lib/ela/bootstrap/range.ela"

#line 38 "/usr/local/lib/ela/bootstrap/range.ela"
  self->idx++;
}
#line 50 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct Slice$7 {
  u8 *data;
  u64 length;
} Slice$7;
typedef struct {
  s32 $0;
  s32 $1;
} $tuple1$1;

#line 54 "/usr/local/lib/ela/bootstrap/interfaces.ela"
typedef struct Iter$7 {
  u8 *ptr;
  u8 *end;
} Iter$7;

#line 18 "/usr/local/lib/ela/bootstrap/str.ela"
u8 $13_subscript(str *self, s64 idx)
#line 18 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 19 "/usr/local/lib/ela/bootstrap/str.ela"

#line 19 "/usr/local/lib/ela/bootstrap/str.ela"
  return self->data[idx];
  ;
}
#line 66 "/usr/local/lib/ela/bootstrap/str.ela"
bool $13_eq(str self, str other)
#line 66 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 67 "/usr/local/lib/ela/bootstrap/str.ela"

#line 67 "/usr/local/lib/ela/bootstrap/str.ela"
  if ((self.length != other.length))
#line 67 "/usr/local/lib/ela/bootstrap/str.ela"
  {

#line 67 "/usr/local/lib/ela/bootstrap/str.ela"

#line 67 "/usr/local/lib/ela/bootstrap/str.ela"
    return false;
    ;
  };

#line 68 "/usr/local/lib/ela/bootstrap/str.ela"

#line 68 "/usr/local/lib/ela/bootstrap/str.ela"
  {
    Range_Base$1 $_range_id0 = (Range_Base$1){.begin = 0, .end = self.length};
    Range_Enumerator$1 $_loop_id0 = $53_enumerator(&$_range_id0);
    while (!$85_done($_loop_id0)) {
      s32 idx = $85_current($_loop_id0);
      $85_next(&$_loop_id0);

#line 68 "/usr/local/lib/ela/bootstrap/str.ela"
      {

#line 69 "/usr/local/lib/ela/bootstrap/str.ela"

#line 69 "/usr/local/lib/ela/bootstrap/str.ela"
        if (($13_subscript(&self, idx) != $13_subscript(&other, idx)))
#line 69 "/usr/local/lib/ela/bootstrap/str.ela"
        {

#line 69 "/usr/local/lib/ela/bootstrap/str.ela"

#line 69 "/usr/local/lib/ela/bootstrap/str.ela"
          return false;
          ;
        };
      }
    }
  };

#line 71 "/usr/local/lib/ela/bootstrap/str.ela"

#line 71 "/usr/local/lib/ela/bootstrap/str.ela"
  return true;
  ;
}
#line 57 "/usr/local/lib/ela/bootstrap/str.ela"
Iter$7 $13_iter(str *self)
#line 57 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 58 "/usr/local/lib/ela/bootstrap/str.ela"

#line 58 "/usr/local/lib/ela/bootstrap/str.ela"
  return (Iter$7){.ptr = (u8 *)self->data,
                  .end = (u8 *)(self->data + self->length)};
  ;
}
#line 69 "/usr/local/lib/ela/bootstrap/interfaces.ela"
bool $177_done(Iter$7 self)
#line 69 "/usr/local/lib/ela/bootstrap/interfaces.ela"
{

#line 70 "/usr/local/lib/ela/bootstrap/interfaces.ela"

#line 70 "/usr/local/lib/ela/bootstrap/interfaces.ela"
  return ((self.ptr >= self.end) || (self.ptr == self.end));
  ;
}
#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"
u8 *$177_current(Iter$7 self)
#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"
{

#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"

#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"
  return self.ptr;
  ;
}
typedef struct Iter$7 Iter$7;

#line 64 "/usr/local/lib/ela/bootstrap/interfaces.ela"
void $177_next(Iter$7 *self)
#line 64 "/usr/local/lib/ela/bootstrap/interfaces.ela"
{

#line 65 "/usr/local/lib/ela/bootstrap/interfaces.ela"

#line 65 "/usr/local/lib/ela/bootstrap/interfaces.ela"
  self->ptr++;
}
#line 50 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct Slice$5 {
  u32 *data;
  u64 length;
} Slice$5;
typedef struct String String;

#line 45 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s32 strncmp(u8 *, u8 *, s32);
#line 11 "/usr/local/lib/ela/bootstrap/libc.ela"
extern void *realloc(void *, u64);
#line 43 "/usr/local/lib/ela/bootstrap/libc.ela"
extern void *memcpy(void *, void *, u64);
#line 9 "/usr/local/lib/ela/bootstrap/libc.ela"
extern void *malloc(u64);
#line 50 "/usr/local/lib/ela/bootstrap/String.ela"
void $14_resize(String *self, u64 new_size)
#line 50 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 51 "/usr/local/lib/ela/bootstrap/String.ela"

#line 51 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((new_size < self->length))
#line 51 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 51 "/usr/local/lib/ela/bootstrap/String.ela"

#line 51 "/usr/local/lib/ela/bootstrap/String.ela"
    (self->length = new_size);
  };

#line 52 "/usr/local/lib/ela/bootstrap/String.ela"

#line 52 "/usr/local/lib/ela/bootstrap/String.ela"
  (self->capacity = new_size);

#line 53 "/usr/local/lib/ela/bootstrap/String.ela"

#line 53 "/usr/local/lib/ela/bootstrap/String.ela"
  (self->data = (u8 *)realloc(self->data, ((new_size * sizeof(u8)) + 1)));

#line 54 "/usr/local/lib/ela/bootstrap/String.ela"

#line 54 "/usr/local/lib/ela/bootstrap/String.ela"
  (self->data[self->length] = 0);
}
#line 42 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s32 memmove(void *, void *, s64);
#line 8 "/usr/local/lib/ela/bootstrap/libc.ela"
extern void free(void *);
#line 116 "/usr/local/lib/ela/bootstrap/String.ela"
u8 $14_subscript(String *self, s64 idx)
#line 116 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 117 "/usr/local/lib/ela/bootstrap/String.ela"

#line 117 "/usr/local/lib/ela/bootstrap/String.ela"
  return self->data[idx];
  ;
}
typedef struct Field Field;

#line 32 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct List$28 {
  Field *data;
  u64 length;
  u64 capacity;
} List$28;
typedef struct List$27 List$27;

#line 32 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct List$38 {
  Type **data;
  u64 length;
  u64 capacity;
} List$38;

#line 13 "/usr/local/lib/ela/bootstrap/reflection.ela"
typedef struct Type {
  s32 id;
  u8 *name;
  u64 size;
  u64 flags;
  List$28 fields;
  List$27 (*elements)(u8 *);
  Type *element_type;
} Type;

#line 40 "/usr/local/lib/ela/bootstrap/reflection.ela"
typedef enum {
  TypeFlags_INTEGER = 1,
  TypeFlags_FLOAT = 2,
  TypeFlags_BOOL = 4,
  TypeFlags_STRING = 8,
  TypeFlags_STRUCT = 16,
  TypeFlags_TAGGED_UNION = 32,
  TypeFlags_ENUM = 64,
  TypeFlags_TUPLE = 128,
  TypeFlags_ARRAY = 256,
  TypeFlags_FUNCTION = 512,
  TypeFlags_POINTER = 1024,
  TypeFlags_SIGNED = 2048,
  TypeFlags_UNSIGNED = 4096
} TypeFlags;

#line 65 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_has_no_extension(Type *self)
#line 65 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 66 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 66 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (((self->flags & TypeFlags_POINTER) == 0) &&
          ((self->flags & TypeFlags_ARRAY) == 0));
  ;
}
#line 54 "/usr/local/lib/ela/bootstrap/interfaces.ela"
typedef struct Iter$28 {
  Field *ptr;
  Field *end;
} Iter$28;

#line 5 "/usr/local/lib/ela/bootstrap/reflection.ela"
typedef struct Field {
  u8 *name;
  Type *type;
  u64 size;
  u64 offset;
  s64 enum_value;
} Field;
typedef struct List$28 List$28;

#line 123 "/usr/local/lib/ela/bootstrap/list.ela"
Iter$28 $220_iter(List$28 *self)
#line 123 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 124 "/usr/local/lib/ela/bootstrap/list.ela"

#line 124 "/usr/local/lib/ela/bootstrap/list.ela"
  return (Iter$28){.ptr = (Field *)self->data,
                   .end = (Field *)(Field *)(self->data + self->length)};
  ;
}
#line 69 "/usr/local/lib/ela/bootstrap/interfaces.ela"
bool $234_done(Iter$28 self)
#line 69 "/usr/local/lib/ela/bootstrap/interfaces.ela"
{

#line 70 "/usr/local/lib/ela/bootstrap/interfaces.ela"

#line 70 "/usr/local/lib/ela/bootstrap/interfaces.ela"
  return ((self.ptr >= self.end) || (self.ptr == self.end));
  ;
}
#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"
Field *$234_current(Iter$28 self)
#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"
{

#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"

#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"
  return self.ptr;
  ;
}
typedef struct Iter$28 Iter$28;

#line 64 "/usr/local/lib/ela/bootstrap/interfaces.ela"
void $234_next(Iter$28 *self)
#line 64 "/usr/local/lib/ela/bootstrap/interfaces.ela"
{

#line 65 "/usr/local/lib/ela/bootstrap/interfaces.ela"

#line 65 "/usr/local/lib/ela/bootstrap/interfaces.ela"
  self->ptr++;
}
#line 46 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s32 strcmp(u8 *, u8 *);
#line 13 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s32 printf(u8 *, ...);
#line 14 "/usr/local/lib/ela/bootstrap/libc.ela"
extern void exit(s32);
#line 37 "/usr/local/lib/ela/bootstrap/lib.ela"
void (*panic_handler)(str) = (void (*)(str)){0};

#line 49 "/usr/local/lib/ela/bootstrap/lib.ela"
void $lambda$0(str msg)
#line 46 "/usr/local/lib/ela/bootstrap/lib.ela"
{

#line 47 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 47 "/usr/local/lib/ela/bootstrap/lib.ela"
  printf("panic(): %s\n", msg.data);

#line 48 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 48 "/usr/local/lib/ela/bootstrap/lib.ela"
  exit(1);
}

#line 32 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct List$13 {
  str *data;
  u64 length;
  u64 capacity;
} List$13;
typedef struct Env Env;

#line 81 "/usr/local/lib/ela/bootstrap/lib.ela"
typedef struct Env {
  List$13 m_args;
} Env;

#line 43 "/usr/local/lib/ela/bootstrap/lib.ela"
void panic(str msg)
#line 43 "/usr/local/lib/ela/bootstrap/lib.ela"
{

#line 44 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 44 "/usr/local/lib/ela/bootstrap/lib.ela"
  if ((!panic_handler))
#line 44 "/usr/local/lib/ela/bootstrap/lib.ela"
  {

#line 45 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 46 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 46 "/usr/local/lib/ela/bootstrap/lib.ela"
    (panic_handler = (void (*)(str))$lambda$0);
    ;
  };

#line 58 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 58 "/usr/local/lib/ela/bootstrap/lib.ela"
  panic_handler(msg);
}
#line 99 "/usr/local/lib/ela/bootstrap/list.ela"
List$13 $318_clone(List$13 self)
#line 99 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 100 "/usr/local/lib/ela/bootstrap/list.ela"

#line 100 "/usr/local/lib/ela/bootstrap/list.ela"
  void *new_data = malloc((sizeof(str) * self.capacity));
  ;

#line 101 "/usr/local/lib/ela/bootstrap/list.ela"

#line 101 "/usr/local/lib/ela/bootstrap/list.ela"
  if ((!new_data))
#line 101 "/usr/local/lib/ela/bootstrap/list.ela"
  {

#line 101 "/usr/local/lib/ela/bootstrap/list.ela"

#line 101 "/usr/local/lib/ela/bootstrap/list.ela"
    panic((str){.data = "Failed to allocate in List clone", .length = 32});
  };

#line 102 "/usr/local/lib/ela/bootstrap/list.ela"

#line 102 "/usr/local/lib/ela/bootstrap/list.ela"
  memcpy(new_data, self.data, (sizeof(str) * self.length));

#line 103 "/usr/local/lib/ela/bootstrap/list.ela"

#line 103 "/usr/local/lib/ela/bootstrap/list.ela"
  return (List$13){.data = (str *)new_data,
                   .length = (u64)self.length,
                   .capacity = (u64)self.capacity};
  ;
}
#line 85 "/usr/local/lib/ela/bootstrap/lib.ela"
static Env *$29_current()
#line 85 "/usr/local/lib/ela/bootstrap/lib.ela"
{

#line 86 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 86 "/usr/local/lib/ela/bootstrap/lib.ela"
  static Env self = (Env){};
  ;

#line 87 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 87 "/usr/local/lib/ela/bootstrap/lib.ela"
  return (&self);
  ;
}
typedef struct List$13 List$13;

#line 29 "/usr/local/lib/ela/bootstrap/list.ela"
void $318_resize(List$13 *self, u64 new_capacity)
#line 29 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"
  if (((new_capacity < self->capacity) && (new_capacity < self->length)))
#line 30 "/usr/local/lib/ela/bootstrap/list.ela"
  {

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"
    (self->length = new_capacity);
  };

#line 32 "/usr/local/lib/ela/bootstrap/list.ela"

#line 32 "/usr/local/lib/ela/bootstrap/list.ela"
  (self->capacity = new_capacity);

#line 33 "/usr/local/lib/ela/bootstrap/list.ela"

#line 33 "/usr/local/lib/ela/bootstrap/list.ela"
  (self->data = (str *)realloc(self->data, (sizeof(str) * self->capacity)));

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"
  if ((!self->data))
#line 34 "/usr/local/lib/ela/bootstrap/list.ela"
  {

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"
    panic((str){.data = "Failed to allocate in List![{#type(T).name}]",
                .length = 44});
  };
}
#line 37 "/usr/local/lib/ela/bootstrap/list.ela"
void $318_push(List$13 *self, str v)
#line 37 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 38 "/usr/local/lib/ela/bootstrap/list.ela"

#line 38 "/usr/local/lib/ela/bootstrap/list.ela"
  if (((self->length + 1) >= self->capacity))
#line 38 "/usr/local/lib/ela/bootstrap/list.ela"
  {

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"
    if ((self->capacity == 0))
#line 39 "/usr/local/lib/ela/bootstrap/list.ela"
    {

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"
      (self->capacity = 4);
    };

#line 40 "/usr/local/lib/ela/bootstrap/list.ela"

#line 40 "/usr/local/lib/ela/bootstrap/list.ela"
    $318_resize(self, (self->capacity * 2));
  };

#line 42 "/usr/local/lib/ela/bootstrap/list.ela"

#line 42 "/usr/local/lib/ela/bootstrap/list.ela"
  (self->data[self->length] = v);

#line 43 "/usr/local/lib/ela/bootstrap/list.ela"

#line 43 "/usr/local/lib/ela/bootstrap/list.ela"
  self->length++;
}
typedef struct {
  u32 $0;
  s8 $1;
} $tuple5$3;

#line 2 "/usr/local/lib/ela/format.ela"
u32 UTF8_ERROR = 0xFFFD;
typedef struct Slice$7 Slice$7;

#line 14 "/usr/local/lib/ela/bootstrap/slice.ela"
u8 $172_subscript(Slice$7 *self, u32 idx)
#line 14 "/usr/local/lib/ela/bootstrap/slice.ela"
{

#line 15 "/usr/local/lib/ela/bootstrap/slice.ela"

#line 15 "/usr/local/lib/ela/bootstrap/slice.ela"
  return self->data[idx];
  ;
}
#line 32 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct List$7 {
  u8 *data;
  u64 length;
  u64 capacity;
} List$7;
typedef struct List$7 List$7;

#line 29 "/usr/local/lib/ela/bootstrap/list.ela"
void $356_resize(List$7 *self, u64 new_capacity)
#line 29 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"
  if (((new_capacity < self->capacity) && (new_capacity < self->length)))
#line 30 "/usr/local/lib/ela/bootstrap/list.ela"
  {

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"
    (self->length = new_capacity);
  };

#line 32 "/usr/local/lib/ela/bootstrap/list.ela"

#line 32 "/usr/local/lib/ela/bootstrap/list.ela"
  (self->capacity = new_capacity);

#line 33 "/usr/local/lib/ela/bootstrap/list.ela"

#line 33 "/usr/local/lib/ela/bootstrap/list.ela"
  (self->data = (u8 *)realloc(self->data, (sizeof(u8) * self->capacity)));

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"
  if ((!self->data))
#line 34 "/usr/local/lib/ela/bootstrap/list.ela"
  {

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"
    panic((str){.data = "Failed to allocate in List![{#type(T).name}]",
                .length = 44});
  };
}
#line 37 "/usr/local/lib/ela/bootstrap/list.ela"
void $356_push(List$7 *self, u8 v)
#line 37 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 38 "/usr/local/lib/ela/bootstrap/list.ela"

#line 38 "/usr/local/lib/ela/bootstrap/list.ela"
  if (((self->length + 1) >= self->capacity))
#line 38 "/usr/local/lib/ela/bootstrap/list.ela"
  {

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"
    if ((self->capacity == 0))
#line 39 "/usr/local/lib/ela/bootstrap/list.ela"
    {

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"
      (self->capacity = 4);
    };

#line 40 "/usr/local/lib/ela/bootstrap/list.ela"

#line 40 "/usr/local/lib/ela/bootstrap/list.ela"
    $356_resize(self, (self->capacity * 2));
  };

#line 42 "/usr/local/lib/ela/bootstrap/list.ela"

#line 42 "/usr/local/lib/ela/bootstrap/list.ela"
  (self->data[self->length] = v);

#line 43 "/usr/local/lib/ela/bootstrap/list.ela"

#line 43 "/usr/local/lib/ela/bootstrap/list.ela"
  self->length++;
}
#line 147 "/usr/local/lib/ela/format.ela"
bool utf8_is_cyrillic_alpha(u32 ch)
#line 147 "/usr/local/lib/ela/format.ela"
{

#line 148 "/usr/local/lib/ela/format.ela"

#line 148 "/usr/local/lib/ela/format.ela"
  return (((0x0400 <= ch) && (ch <= 0x04FF)) ||
          ((0x0500 <= ch) && (ch <= 0x052F)));
  ;
}
#line 151 "/usr/local/lib/ela/format.ela"
bool utf8_is_chinese_alpha(u32 ch)
#line 151 "/usr/local/lib/ela/format.ela"
{

#line 152 "/usr/local/lib/ela/format.ela"

#line 152 "/usr/local/lib/ela/format.ela"
  return (((0x4E00 <= ch) && (ch <= 0x9FFF)) ||
          ((0x3400 <= ch) && (ch <= 0x4DBF)));
  ;
}
#line 155 "/usr/local/lib/ela/format.ela"
bool utf8_is_korean_alpha(u32 ch)
#line 155 "/usr/local/lib/ela/format.ela"
{

#line 156 "/usr/local/lib/ela/format.ela"

#line 156 "/usr/local/lib/ela/format.ela"
  return (((0xAC00 <= ch) && (ch <= 0xD7AF)) ||
          ((0x1100 <= ch) && (ch <= 0x11FF)));
  ;
}
#line 159 "/usr/local/lib/ela/format.ela"
bool utf8_is_japanese_alpha(u32 ch)
#line 159 "/usr/local/lib/ela/format.ela"
{

#line 160 "/usr/local/lib/ela/format.ela"

#line 160 "/usr/local/lib/ela/format.ela"
  return ((((0x3040 <= ch) && (ch <= 0x309F)) ||
           ((0x30A0 <= ch) && (ch <= 0x30FF))) ||
          ((0x4E00 <= ch) && (ch <= 0x9FFF)));
  ;
}
#line 163 "/usr/local/lib/ela/format.ela"
bool utf8_is_latin_alpha(u32 ch)
#line 163 "/usr/local/lib/ela/format.ela"
{

#line 164 "/usr/local/lib/ela/format.ela"

#line 164 "/usr/local/lib/ela/format.ela"
  return (((0x0041 <= ch) && (ch <= 0x005A)) ||
          ((0x0061 <= ch) && (ch <= 0x007A)));
  ;
}
typedef struct String_Builder_Block String_Builder_Block;

#line 6 "/usr/local/lib/ela/builder.ela"
typedef struct String_Builder_Block {
  u8 *data;
  u64 length;
  String_Builder_Block *next;
} String_Builder_Block;

#line 4 "/usr/local/lib/ela/builder.ela"
static constexpr s32 STRING_BUILDER_BLOCK_MAX_LEN = 8192;

#line 10 "/usr/local/lib/ela/bootstrap/libc.ela"
extern void *calloc(u64, u64);
#line 19 "/usr/local/lib/ela/builder.ela"
void $30_deinit(String_Builder_Block *self)
#line 19 "/usr/local/lib/ela/builder.ela"
{

#line 20 "/usr/local/lib/ela/builder.ela"

#line 20 "/usr/local/lib/ela/builder.ela"
  if (self->data)
#line 20 "/usr/local/lib/ela/builder.ela"
  {

#line 20 "/usr/local/lib/ela/builder.ela"

#line 20 "/usr/local/lib/ela/builder.ela"
    free(self->data);
  };

#line 21 "/usr/local/lib/ela/builder.ela"

#line 21 "/usr/local/lib/ela/builder.ela"
  if (self->next)
#line 21 "/usr/local/lib/ela/builder.ela"
  {

#line 22 "/usr/local/lib/ela/builder.ela"

#line 22 "/usr/local/lib/ela/builder.ela"
    $30_deinit(self->next);

#line 23 "/usr/local/lib/ela/builder.ela"

#line 23 "/usr/local/lib/ela/builder.ela"
    free(self->next);
  };

#line 25 "/usr/local/lib/ela/builder.ela"

#line 25 "/usr/local/lib/ela/builder.ela"
  (self->data = (u8 *)NULL);

#line 26 "/usr/local/lib/ela/builder.ela"

#line 26 "/usr/local/lib/ela/builder.ela"
  (self->next = (String_Builder_Block *)NULL);

#line 27 "/usr/local/lib/ela/builder.ela"

#line 27 "/usr/local/lib/ela/builder.ela"
  (self->length = 0);
}
typedef struct String_Builder String_Builder;

#line 31 "/usr/local/lib/ela/builder.ela"
typedef struct String_Builder {
  String_Builder_Block *root;
  String_Builder_Block *current;
} String_Builder;

#line 42 "/usr/local/lib/ela/builder.ela"
void $31_deinit(String_Builder *self)
#line 42 "/usr/local/lib/ela/builder.ela"
{

#line 43 "/usr/local/lib/ela/builder.ela"

#line 43 "/usr/local/lib/ela/builder.ela"
  if (self->root)
#line 43 "/usr/local/lib/ela/builder.ela"
  {

#line 43 "/usr/local/lib/ela/builder.ela"

#line 43 "/usr/local/lib/ela/builder.ela"
    $30_deinit(self->root);
  };

#line 44 "/usr/local/lib/ela/builder.ela"

#line 44 "/usr/local/lib/ela/builder.ela"
  (self->root = (String_Builder_Block *)NULL);

#line 45 "/usr/local/lib/ela/builder.ela"

#line 45 "/usr/local/lib/ela/builder.ela"
  (self->current = (String_Builder_Block *)NULL);
}
#line 53 "/usr/local/lib/ela/builder.ela"
u64 $31_length(String_Builder *self)
#line 53 "/usr/local/lib/ela/builder.ela"
{

#line 54 "/usr/local/lib/ela/builder.ela"

#line 54 "/usr/local/lib/ela/builder.ela"
  if ((!self->root))
#line 54 "/usr/local/lib/ela/builder.ela"
  {

#line 54 "/usr/local/lib/ela/builder.ela"

#line 54 "/usr/local/lib/ela/builder.ela"
    return 0;
    ;
  };

#line 55 "/usr/local/lib/ela/builder.ela"

#line 55 "/usr/local/lib/ela/builder.ela"
  String_Builder_Block *current = self->root;
  ;

#line 56 "/usr/local/lib/ela/builder.ela"

#line 56 "/usr/local/lib/ela/builder.ela"
  u64 len = (u64){0};
  ;

#line 57 "/usr/local/lib/ela/builder.ela"

#line 57 "/usr/local/lib/ela/builder.ela"
  while (current)
#line 57 "/usr/local/lib/ela/builder.ela"
  {

#line 58 "/usr/local/lib/ela/builder.ela"

#line 58 "/usr/local/lib/ela/builder.ela"
    (len += current->length);

#line 59 "/usr/local/lib/ela/builder.ela"

#line 59 "/usr/local/lib/ela/builder.ela"
    (current = (String_Builder_Block *)current->next);
  };

#line 61 "/usr/local/lib/ela/builder.ela"

#line 61 "/usr/local/lib/ela/builder.ela"
  return len;
  ;
}
#line 13 "/usr/local/lib/ela/builder.ela"
static String_Builder_Block *$30_new()
#line 13 "/usr/local/lib/ela/builder.ela"
{

#line 14 "/usr/local/lib/ela/builder.ela"

#line 14 "/usr/local/lib/ela/builder.ela"
  String_Builder_Block *self = malloc(sizeof(String_Builder_Block));
  ;

#line 15 "/usr/local/lib/ela/builder.ela"

#line 15 "/usr/local/lib/ela/builder.ela"
  (self->data = (u8 *)calloc(sizeof(u8), STRING_BUILDER_BLOCK_MAX_LEN));

#line 16 "/usr/local/lib/ela/builder.ela"

#line 16 "/usr/local/lib/ela/builder.ela"
  (self->next = (String_Builder_Block *)NULL);

#line 17 "/usr/local/lib/ela/builder.ela"

#line 17 "/usr/local/lib/ela/builder.ela"
  return self;
  ;
}
typedef struct any any;

#line 26 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct Init_List$18 {
  any *data;
  u64 length;
} Init_List$18;

#line 115 "/usr/local/lib/ela/bootstrap/lib.ela"
Slice$7 $5_as_byte_slice(u32 self)
#line 115 "/usr/local/lib/ela/bootstrap/lib.ela"
{

#line 116 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 116 "/usr/local/lib/ela/bootstrap/lib.ela"
  static u8 chars[2] = {'\0', '\0'};

#line 119 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 119 "/usr/local/lib/ela/bootstrap/lib.ela"
  (chars[0] = self);

#line 120 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 120 "/usr/local/lib/ela/bootstrap/lib.ela"
  return (Slice$7){.data = (u8 *)chars, .length = (u64)1};
  ;
}
#line 81 "/usr/local/lib/ela/builder.ela"
void $31_append$5(String_Builder *self, u32 value)
#line 81 "/usr/local/lib/ela/builder.ela"
{

#line 82 "/usr/local/lib/ela/builder.ela"

#line 82 "/usr/local/lib/ela/builder.ela"
  Slice$7 slice = $5_as_byte_slice(value);
  ;

#line 84 "/usr/local/lib/ela/builder.ela"

#line 84 "/usr/local/lib/ela/builder.ela"
  if ((slice.length == 0))
#line 85 "/usr/local/lib/ela/builder.ela"
  {

#line 85 "/usr/local/lib/ela/builder.ela"

#line 85 "/usr/local/lib/ela/builder.ela"
    return;
    ;
  };

#line 87 "/usr/local/lib/ela/builder.ela"

#line 87 "/usr/local/lib/ela/builder.ela"
  if ((!self->root))
#line 87 "/usr/local/lib/ela/builder.ela"
  {

#line 88 "/usr/local/lib/ela/builder.ela"

#line 88 "/usr/local/lib/ela/builder.ela"
    (self->root = (String_Builder_Block *)$30_new());

#line 89 "/usr/local/lib/ela/builder.ela"

#line 89 "/usr/local/lib/ela/builder.ela"
    (self->current = (String_Builder_Block *)self->root);
  };

#line 92 "/usr/local/lib/ela/builder.ela"

#line 92 "/usr/local/lib/ela/builder.ela"
  s32 slice_index = 0;
  ;

#line 93 "/usr/local/lib/ela/builder.ela"

#line 93 "/usr/local/lib/ela/builder.ela"
  u64 length = slice.length;
  ;

#line 95 "/usr/local/lib/ela/builder.ela"

#line 95 "/usr/local/lib/ela/builder.ela"
  s32 remaining = (STRING_BUILDER_BLOCK_MAX_LEN - self->current->length);
  ;

#line 97 "/usr/local/lib/ela/builder.ela"

#line 97 "/usr/local/lib/ela/builder.ela"
  while ((length > 0))
#line 97 "/usr/local/lib/ela/builder.ela"
  {

#line 99 "/usr/local/lib/ela/builder.ela"

#line 99 "/usr/local/lib/ela/builder.ela"
    if ((length <= remaining))
#line 99 "/usr/local/lib/ela/builder.ela"
    {

#line 100 "/usr/local/lib/ela/builder.ela"

#line 100 "/usr/local/lib/ela/builder.ela"
      memcpy((self->current->data + self->current->length),
             (slice.data + slice_index), length);

#line 101 "/usr/local/lib/ela/builder.ela"

#line 101 "/usr/local/lib/ela/builder.ela"
      (self->current->length += length);

#line 102 "/usr/local/lib/ela/builder.ela"

#line 102 "/usr/local/lib/ela/builder.ela"
      break;
      ;
    };

#line 106 "/usr/local/lib/ela/builder.ela"

#line 106 "/usr/local/lib/ela/builder.ela"
    memcpy((self->current->data + self->current->length),
           (slice.data + slice_index), remaining);

#line 107 "/usr/local/lib/ela/builder.ela"

#line 107 "/usr/local/lib/ela/builder.ela"
    (self->current->length += remaining);

#line 108 "/usr/local/lib/ela/builder.ela"

#line 108 "/usr/local/lib/ela/builder.ela"
    (slice_index += remaining);

#line 109 "/usr/local/lib/ela/builder.ela"

#line 109 "/usr/local/lib/ela/builder.ela"
    (length -= remaining);

#line 110 "/usr/local/lib/ela/builder.ela"

#line 110 "/usr/local/lib/ela/builder.ela"
    (self->current->next = (String_Builder_Block *)$30_new());

#line 111 "/usr/local/lib/ela/builder.ela"

#line 111 "/usr/local/lib/ela/builder.ela"
    (self->current = (String_Builder_Block *)self->current->next);

#line 112 "/usr/local/lib/ela/builder.ela"

#line 112 "/usr/local/lib/ela/builder.ela"
    (remaining = STRING_BUILDER_BLOCK_MAX_LEN);
  };
}
#line 42 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct any {
  void *ptr;
  Type *type;
} any;

#line 100 "/usr/local/lib/ela/bootstrap/str.ela"
Slice$7 $13_as_byte_slice(str self)
#line 100 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 101 "/usr/local/lib/ela/bootstrap/str.ela"

#line 101 "/usr/local/lib/ela/bootstrap/str.ela"
  return (Slice$7){.data = (u8 *)self.data, .length = (u64)self.length};
  ;
}
#line 81 "/usr/local/lib/ela/builder.ela"
void $31_append$13(String_Builder *self, str value)
#line 81 "/usr/local/lib/ela/builder.ela"
{

#line 82 "/usr/local/lib/ela/builder.ela"

#line 82 "/usr/local/lib/ela/builder.ela"
  Slice$7 slice = $13_as_byte_slice(value);
  ;

#line 84 "/usr/local/lib/ela/builder.ela"

#line 84 "/usr/local/lib/ela/builder.ela"
  if ((slice.length == 0))
#line 85 "/usr/local/lib/ela/builder.ela"
  {

#line 85 "/usr/local/lib/ela/builder.ela"

#line 85 "/usr/local/lib/ela/builder.ela"
    return;
    ;
  };

#line 87 "/usr/local/lib/ela/builder.ela"

#line 87 "/usr/local/lib/ela/builder.ela"
  if ((!self->root))
#line 87 "/usr/local/lib/ela/builder.ela"
  {

#line 88 "/usr/local/lib/ela/builder.ela"

#line 88 "/usr/local/lib/ela/builder.ela"
    (self->root = (String_Builder_Block *)$30_new());

#line 89 "/usr/local/lib/ela/builder.ela"

#line 89 "/usr/local/lib/ela/builder.ela"
    (self->current = (String_Builder_Block *)self->root);
  };

#line 92 "/usr/local/lib/ela/builder.ela"

#line 92 "/usr/local/lib/ela/builder.ela"
  s32 slice_index = 0;
  ;

#line 93 "/usr/local/lib/ela/builder.ela"

#line 93 "/usr/local/lib/ela/builder.ela"
  u64 length = slice.length;
  ;

#line 95 "/usr/local/lib/ela/builder.ela"

#line 95 "/usr/local/lib/ela/builder.ela"
  s32 remaining = (STRING_BUILDER_BLOCK_MAX_LEN - self->current->length);
  ;

#line 97 "/usr/local/lib/ela/builder.ela"

#line 97 "/usr/local/lib/ela/builder.ela"
  while ((length > 0))
#line 97 "/usr/local/lib/ela/builder.ela"
  {

#line 99 "/usr/local/lib/ela/builder.ela"

#line 99 "/usr/local/lib/ela/builder.ela"
    if ((length <= remaining))
#line 99 "/usr/local/lib/ela/builder.ela"
    {

#line 100 "/usr/local/lib/ela/builder.ela"

#line 100 "/usr/local/lib/ela/builder.ela"
      memcpy((self->current->data + self->current->length),
             (slice.data + slice_index), length);

#line 101 "/usr/local/lib/ela/builder.ela"

#line 101 "/usr/local/lib/ela/builder.ela"
      (self->current->length += length);

#line 102 "/usr/local/lib/ela/builder.ela"

#line 102 "/usr/local/lib/ela/builder.ela"
      break;
      ;
    };

#line 106 "/usr/local/lib/ela/builder.ela"

#line 106 "/usr/local/lib/ela/builder.ela"
    memcpy((self->current->data + self->current->length),
           (slice.data + slice_index), remaining);

#line 107 "/usr/local/lib/ela/builder.ela"

#line 107 "/usr/local/lib/ela/builder.ela"
    (self->current->length += remaining);

#line 108 "/usr/local/lib/ela/builder.ela"

#line 108 "/usr/local/lib/ela/builder.ela"
    (slice_index += remaining);

#line 109 "/usr/local/lib/ela/builder.ela"

#line 109 "/usr/local/lib/ela/builder.ela"
    (length -= remaining);

#line 110 "/usr/local/lib/ela/builder.ela"

#line 110 "/usr/local/lib/ela/builder.ela"
    (self->current->next = (String_Builder_Block *)$30_new());

#line 111 "/usr/local/lib/ela/builder.ela"

#line 111 "/usr/local/lib/ela/builder.ela"
    (self->current = (String_Builder_Block *)self->current->next);

#line 112 "/usr/local/lib/ela/builder.ela"

#line 112 "/usr/local/lib/ela/builder.ela"
    (remaining = STRING_BUILDER_BLOCK_MAX_LEN);
  };
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
u8 *$18_unwrap$36(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(u8 **)self->ptr);
  ;
}
#line 25 "/usr/local/lib/ela/bootstrap/String.ela"
static String $14_from(u8 *data)
#line 25 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 26 "/usr/local/lib/ela/bootstrap/String.ela"

#line 26 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((!data))
#line 26 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 26 "/usr/local/lib/ela/bootstrap/String.ela"

#line 26 "/usr/local/lib/ela/bootstrap/String.ela"
    return (String){0};
    ;
  };

#line 27 "/usr/local/lib/ela/bootstrap/String.ela"

#line 27 "/usr/local/lib/ela/bootstrap/String.ela"
  u32 len = strlen(data);
  ;

#line 28 "/usr/local/lib/ela/bootstrap/String.ela"

#line 28 "/usr/local/lib/ela/bootstrap/String.ela"
  return (String){
      .data = (u8 *)strdup(data), .capacity = (u64)len, .length = (u64)len};
  ;
}
#line 176 "/usr/local/lib/ela/bootstrap/String.ela"
Slice$7 $14_as_byte_slice(String self)
#line 176 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 177 "/usr/local/lib/ela/bootstrap/String.ela"

#line 177 "/usr/local/lib/ela/bootstrap/String.ela"
  return (Slice$7){.data = (u8 *)self.data, .length = (u64)self.length};
  ;
}
#line 81 "/usr/local/lib/ela/builder.ela"
void $31_append$14(String_Builder *self, String value)
#line 81 "/usr/local/lib/ela/builder.ela"
{

#line 82 "/usr/local/lib/ela/builder.ela"

#line 82 "/usr/local/lib/ela/builder.ela"
  Slice$7 slice = $14_as_byte_slice(value);
  ;

#line 84 "/usr/local/lib/ela/builder.ela"

#line 84 "/usr/local/lib/ela/builder.ela"
  if ((slice.length == 0))
#line 85 "/usr/local/lib/ela/builder.ela"
  {

#line 85 "/usr/local/lib/ela/builder.ela"

#line 85 "/usr/local/lib/ela/builder.ela"
    return;
    ;
  };

#line 87 "/usr/local/lib/ela/builder.ela"

#line 87 "/usr/local/lib/ela/builder.ela"
  if ((!self->root))
#line 87 "/usr/local/lib/ela/builder.ela"
  {

#line 88 "/usr/local/lib/ela/builder.ela"

#line 88 "/usr/local/lib/ela/builder.ela"
    (self->root = (String_Builder_Block *)$30_new());

#line 89 "/usr/local/lib/ela/builder.ela"

#line 89 "/usr/local/lib/ela/builder.ela"
    (self->current = (String_Builder_Block *)self->root);
  };

#line 92 "/usr/local/lib/ela/builder.ela"

#line 92 "/usr/local/lib/ela/builder.ela"
  s32 slice_index = 0;
  ;

#line 93 "/usr/local/lib/ela/builder.ela"

#line 93 "/usr/local/lib/ela/builder.ela"
  u64 length = slice.length;
  ;

#line 95 "/usr/local/lib/ela/builder.ela"

#line 95 "/usr/local/lib/ela/builder.ela"
  s32 remaining = (STRING_BUILDER_BLOCK_MAX_LEN - self->current->length);
  ;

#line 97 "/usr/local/lib/ela/builder.ela"

#line 97 "/usr/local/lib/ela/builder.ela"
  while ((length > 0))
#line 97 "/usr/local/lib/ela/builder.ela"
  {

#line 99 "/usr/local/lib/ela/builder.ela"

#line 99 "/usr/local/lib/ela/builder.ela"
    if ((length <= remaining))
#line 99 "/usr/local/lib/ela/builder.ela"
    {

#line 100 "/usr/local/lib/ela/builder.ela"

#line 100 "/usr/local/lib/ela/builder.ela"
      memcpy((self->current->data + self->current->length),
             (slice.data + slice_index), length);

#line 101 "/usr/local/lib/ela/builder.ela"

#line 101 "/usr/local/lib/ela/builder.ela"
      (self->current->length += length);

#line 102 "/usr/local/lib/ela/builder.ela"

#line 102 "/usr/local/lib/ela/builder.ela"
      break;
      ;
    };

#line 106 "/usr/local/lib/ela/builder.ela"

#line 106 "/usr/local/lib/ela/builder.ela"
    memcpy((self->current->data + self->current->length),
           (slice.data + slice_index), remaining);

#line 107 "/usr/local/lib/ela/builder.ela"

#line 107 "/usr/local/lib/ela/builder.ela"
    (self->current->length += remaining);

#line 108 "/usr/local/lib/ela/builder.ela"

#line 108 "/usr/local/lib/ela/builder.ela"
    (slice_index += remaining);

#line 109 "/usr/local/lib/ela/builder.ela"

#line 109 "/usr/local/lib/ela/builder.ela"
    (length -= remaining);

#line 110 "/usr/local/lib/ela/builder.ela"

#line 110 "/usr/local/lib/ela/builder.ela"
    (self->current->next = (String_Builder_Block *)$30_new());

#line 111 "/usr/local/lib/ela/builder.ela"

#line 111 "/usr/local/lib/ela/builder.ela"
    (self->current = (String_Builder_Block *)self->current->next);

#line 112 "/usr/local/lib/ela/builder.ela"

#line 112 "/usr/local/lib/ela/builder.ela"
    (remaining = STRING_BUILDER_BLOCK_MAX_LEN);
  };
}
#line 114 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_pointer(Type *self)
#line 114 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 115 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 115 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_POINTER) != 0);
  ;
}
#line 102 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_bool(Type *self)
#line 102 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 103 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 103 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_BOOL) != 0);
  ;
}
#line 4 "/usr/local/lib/ela/bootstrap/str.ela"
String $13_as_string(str self)
#line 4 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 5 "/usr/local/lib/ela/bootstrap/str.ela"

#line 5 "/usr/local/lib/ela/bootstrap/str.ela"
  return (String){.data = (u8 *)strdup(self.data), .length = (u64)self.length};
  ;
}
#line 90 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_enum(Type *self)
#line 90 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 91 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 91 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_ENUM) != 0);
  ;
}
#line 94 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_integral(Type *self)
#line 94 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 95 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 95 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_INTEGER) != 0);
  ;
}
#line 98 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_float(Type *self)
#line 98 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 99 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 99 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_FLOAT) != 0);
  ;
}
#line 74 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_string(Type *self)
#line 74 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 75 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 75 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_STRING) != 0);
  ;
}
#line 22 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s32 snprintf(u8 *, u64, u8 *, ...);
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$37(void *value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[37];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 96 "/usr/local/lib/ela/bootstrap/String.ela"
void $14_deinit(String *self)
#line 96 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 97 "/usr/local/lib/ela/bootstrap/String.ela"

#line 97 "/usr/local/lib/ela/bootstrap/String.ela"
  free(self->data);

#line 98 "/usr/local/lib/ela/bootstrap/String.ela"

#line 98 "/usr/local/lib/ela/bootstrap/String.ela"
  (self->length = 0);
}
#line 116 "/usr/local/lib/ela/builder.ela"
void $31_append_then_free$14(String_Builder *self, String value)
#line 116 "/usr/local/lib/ela/builder.ela"
{

#line 117 "/usr/local/lib/ela/builder.ela"

#line 117 "/usr/local/lib/ela/builder.ela"
  $31_append$14(self, value);

#line 118 "/usr/local/lib/ela/builder.ela"

#line 118 "/usr/local/lib/ela/builder.ela"
  $14_deinit(&value);
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
s32 $18_unwrap$1(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(s32 *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$1(s32 value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[1];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
u8 $18_unwrap$7(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(u8 *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$7(u8 value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[7];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
u16 $18_unwrap$6(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(u16 *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$6(u16 value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[6];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
u32 $18_unwrap$5(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(u32 *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$5(u32 value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[5];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
u64 $18_unwrap$4(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(u64 *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$4(u64 value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[4];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
s8 $18_unwrap$3(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(s8 *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$3(s8 value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[3];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
s16 $18_unwrap$2(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(s16 *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$2(s16 value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[2];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
s64 $18_unwrap$0(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(s64 *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$0(s64 value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[0];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
f32 $18_unwrap$9(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(f32 *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$9(f32 value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[9];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
f64 $18_unwrap$8(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(f64 *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$8(f64 value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[8];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $18_unwrap$10(any *self)
#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 160 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (*(bool *)self->ptr);
  ;
}
#line 181 "/usr/local/lib/ela/format.ela"
String to_string$10(bool value)
#line 181 "/usr/local/lib/ela/format.ela"
{

#line 182 "/usr/local/lib/ela/format.ela"

#line 182 "/usr/local/lib/ela/format.ela"
  u8 buffer[64] = {0};

#line 183 "/usr/local/lib/ela/format.ela"

#line 183 "/usr/local/lib/ela/format.ela"
  Type *type = _type_info.data[10];
  ;

#line 184 "/usr/local/lib/ela/format.ela"

#line 184 "/usr/local/lib/ela/format.ela"
  str format = (str){};
  ;

#line 186 "/usr/local/lib/ela/format.ela"

#line 186 "/usr/local/lib/ela/format.ela"
  if ($17_is_bool(type))
#line 186 "/usr/local/lib/ela/format.ela"
  {

#line 187 "/usr/local/lib/ela/format.ela"

#line 187 "/usr/local/lib/ela/format.ela"
    if (value)
#line 187 "/usr/local/lib/ela/format.ela"
    {

#line 188 "/usr/local/lib/ela/format.ela"

#line 188 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "true", .length = 4});
      ;
    }
#line 189 "/usr/local/lib/ela/format.ela"
    else
#line 189 "/usr/local/lib/ela/format.ela"
    {

#line 190 "/usr/local/lib/ela/format.ela"

#line 190 "/usr/local/lib/ela/format.ela"
      return $13_as_string((str){.data = "false", .length = 5});
      ;
    };
  };

#line 194 "/usr/local/lib/ela/format.ela"

#line 194 "/usr/local/lib/ela/format.ela"
  if ($17_is_enum(type))
#line 194 "/usr/local/lib/ela/format.ela"
  {

#line 195 "/usr/local/lib/ela/format.ela"

#line 195 "/usr/local/lib/ela/format.ela"
    {
      List$28 $_range_id0 = type->fields;
      Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
      while (!$234_done($_loop_id0)) {
        Field field = *$234_current($_loop_id0);
        $234_next(&$_loop_id0);

#line 195 "/usr/local/lib/ela/format.ela"
        {

#line 196 "/usr/local/lib/ela/format.ela"

#line 196 "/usr/local/lib/ela/format.ela"
          if ((value == field.enum_value))
#line 196 "/usr/local/lib/ela/format.ela"
          {

#line 197 "/usr/local/lib/ela/format.ela"

#line 197 "/usr/local/lib/ela/format.ela"
            return $14_from(field.name);
            ;
          };
        }
      }
    };
  };

#line 203 "/usr/local/lib/ela/format.ela"

#line 203 "/usr/local/lib/ela/format.ela"
  if ((type == _type_info.data[7]))
#line 203 "/usr/local/lib/ela/format.ela"
  {

#line 204 "/usr/local/lib/ela/format.ela"

#line 204 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%c", .length = 2});
  }
#line 205 "/usr/local/lib/ela/format.ela"
  else
#line 205 "/usr/local/lib/ela/format.ela"
      if ($17_is_integral(type))
#line 205 "/usr/local/lib/ela/format.ela"
  {

#line 206 "/usr/local/lib/ela/format.ela"

#line 206 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%lld", .length = 4});
  }
#line 207 "/usr/local/lib/ela/format.ela"
  else
#line 207 "/usr/local/lib/ela/format.ela"
      if ($17_is_float(type))
#line 207 "/usr/local/lib/ela/format.ela"
  {

#line 208 "/usr/local/lib/ela/format.ela"

#line 208 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%.2lf", .length = 5});
  }
#line 209 "/usr/local/lib/ela/format.ela"
  else
#line 209 "/usr/local/lib/ela/format.ela"
      if ($17_is_string(type))
#line 209 "/usr/local/lib/ela/format.ela"
  {

#line 210 "/usr/local/lib/ela/format.ela"

#line 210 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%s", .length = 2});
  }
#line 211 "/usr/local/lib/ela/format.ela"
  else
#line 211 "/usr/local/lib/ela/format.ela"
      if ($17_is_pointer(type))
#line 211 "/usr/local/lib/ela/format.ela"
  {

#line 212 "/usr/local/lib/ela/format.ela"

#line 212 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "%p", .length = 2});
  }
#line 213 "/usr/local/lib/ela/format.ela"
  else
#line 213 "/usr/local/lib/ela/format.ela"
  {

#line 214 "/usr/local/lib/ela/format.ela"

#line 214 "/usr/local/lib/ela/format.ela"
    (format = (str){.data = "(unsupported type)", .length = 18});
  };

#line 217 "/usr/local/lib/ela/format.ela"

#line 217 "/usr/local/lib/ela/format.ela"
  snprintf(buffer, (64 * sizeof(u8)), format.data, value);

#line 218 "/usr/local/lib/ela/format.ela"

#line 218 "/usr/local/lib/ela/format.ela"
  return $14_from(strdup(buffer));
  ;
}
#line 64 "/usr/local/lib/ela/builder.ela"
String $31_get_string(String_Builder *self)
#line 64 "/usr/local/lib/ela/builder.ela"
{

#line 65 "/usr/local/lib/ela/builder.ela"

#line 65 "/usr/local/lib/ela/builder.ela"
  u64 length = $31_length(self);
  ;

#line 66 "/usr/local/lib/ela/builder.ela"

#line 66 "/usr/local/lib/ela/builder.ela"
  u8 *data = malloc(((sizeof(u8) * length) + 1));
  ;

#line 67 "/usr/local/lib/ela/builder.ela"

#line 67 "/usr/local/lib/ela/builder.ela"
  (data[length] = '\0');

#line 68 "/usr/local/lib/ela/builder.ela"

#line 68 "/usr/local/lib/ela/builder.ela"
  String_Builder_Block *current = self->root;
  ;

#line 69 "/usr/local/lib/ela/builder.ela"

#line 69 "/usr/local/lib/ela/builder.ela"
  s32 offset = 0;
  ;

#line 70 "/usr/local/lib/ela/builder.ela"

#line 70 "/usr/local/lib/ela/builder.ela"
  while (current)
#line 70 "/usr/local/lib/ela/builder.ela"
  {

#line 71 "/usr/local/lib/ela/builder.ela"

#line 71 "/usr/local/lib/ela/builder.ela"
    memcpy((data + offset), current->data, current->length);

#line 72 "/usr/local/lib/ela/builder.ela"

#line 72 "/usr/local/lib/ela/builder.ela"
    (offset += current->length);

#line 73 "/usr/local/lib/ela/builder.ela"

#line 73 "/usr/local/lib/ela/builder.ela"
    (current = (String_Builder_Block *)current->next);
  };

#line 75 "/usr/local/lib/ela/builder.ela"

#line 75 "/usr/local/lib/ela/builder.ela"
  return (String){.data = (u8 *)data, .length = (u64)length};
  ;
}
#line 221 "/usr/local/lib/ela/format.ela"
String format(str fmt, Init_List$18 list)
#line 221 "/usr/local/lib/ela/format.ela"
{

#line 222 "/usr/local/lib/ela/format.ela"

#line 222 "/usr/local/lib/ela/format.ela"
  if ((fmt.length == 0))
#line 222 "/usr/local/lib/ela/format.ela"
  {

#line 223 "/usr/local/lib/ela/format.ela"

#line 223 "/usr/local/lib/ela/format.ela"
    return (String){0};
    ;
  };

#line 226 "/usr/local/lib/ela/format.ela"

#line 226 "/usr/local/lib/ela/format.ela"
  String_Builder builder = (String_Builder){};
  ;

#line 227 "/usr/local/lib/ela/format.ela"

#line 227 "/usr/local/lib/ela/format.ela"
  s32 value_index = 0;
  ;

#line 229 "/usr/local/lib/ela/format.ela"

#line 229 "/usr/local/lib/ela/format.ela"
  while ((*fmt.data))
#line 229 "/usr/local/lib/ela/format.ela"
  {

#line 230 "/usr/local/lib/ela/format.ela"

#line 230 "/usr/local/lib/ela/format.ela"
    if ((((*fmt.data) == '\\') && ((*(fmt.data + 1)) == '%')))
#line 230 "/usr/local/lib/ela/format.ela"
    {

#line 231 "/usr/local/lib/ela/format.ela"

#line 231 "/usr/local/lib/ela/format.ela"
      $31_append$5(&builder, '%');

#line 232 "/usr/local/lib/ela/format.ela"

#line 232 "/usr/local/lib/ela/format.ela"
      (fmt.data += 2);

#line 233 "/usr/local/lib/ela/format.ela"

#line 233 "/usr/local/lib/ela/format.ela"
      continue;
      ;
    };

#line 236 "/usr/local/lib/ela/format.ela"

#line 236 "/usr/local/lib/ela/format.ela"
    if (((*fmt.data) == '%'))
#line 236 "/usr/local/lib/ela/format.ela"
    {

#line 237 "/usr/local/lib/ela/format.ela"

#line 237 "/usr/local/lib/ela/format.ela"
      any value = list.data[value_index];
      ;

#line 238 "/usr/local/lib/ela/format.ela"

#line 238 "/usr/local/lib/ela/format.ela"
      if ((value.ptr == NULL))
#line 238 "/usr/local/lib/ela/format.ela"
      {

#line 239 "/usr/local/lib/ela/format.ela"

#line 239 "/usr/local/lib/ela/format.ela"
        $31_append$13(&builder, (str){.data = "null", .length = 4});
      }
#line 240 "/usr/local/lib/ela/format.ela"
      else
#line 240 "/usr/local/lib/ela/format.ela"
          if ((value.type == _type_info.data[36]))
#line 240 "/usr/local/lib/ela/format.ela"
      {

#line 241 "/usr/local/lib/ela/format.ela"

#line 241 "/usr/local/lib/ela/format.ela"
        $31_append$14(&builder, $14_from($18_unwrap$36(&value)));
      }
#line 242 "/usr/local/lib/ela/format.ela"
      else
#line 242 "/usr/local/lib/ela/format.ela"
          if ($17_is_pointer(value.type))
#line 242 "/usr/local/lib/ela/format.ela"
      {

#line 243 "/usr/local/lib/ela/format.ela"

#line 243 "/usr/local/lib/ela/format.ela"
        $31_append_then_free$14(&builder, to_string$37(value.ptr));
      }
#line 244 "/usr/local/lib/ela/format.ela"
      else
#line 244 "/usr/local/lib/ela/format.ela"
          if ($17_is_enum(value.type))
#line 244 "/usr/local/lib/ela/format.ela"
      {

#line 245 "/usr/local/lib/ela/format.ela"

#line 245 "/usr/local/lib/ela/format.ela"
        $31_append_then_free$14(&builder, to_string$1($18_unwrap$1(&value)));
      }
#line 246 "/usr/local/lib/ela/format.ela"
      else
#line 246 "/usr/local/lib/ela/format.ela"
      {

#line 247 "/usr/local/lib/ela/format.ela"

#line 247 "/usr/local/lib/ela/format.ela"

#line 247 "/usr/local/lib/ela/format.ela"
        if (value.type == _type_info.data[7])
#line 248 "/usr/local/lib/ela/format.ela"

#line 248 "/usr/local/lib/ela/format.ela"
        {

#line 248 "/usr/local/lib/ela/format.ela"

#line 248 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$7($18_unwrap$7(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[6])
#line 249 "/usr/local/lib/ela/format.ela"

#line 249 "/usr/local/lib/ela/format.ela"
        {

#line 249 "/usr/local/lib/ela/format.ela"

#line 249 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$6($18_unwrap$6(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[5])
#line 250 "/usr/local/lib/ela/format.ela"

#line 250 "/usr/local/lib/ela/format.ela"
        {

#line 250 "/usr/local/lib/ela/format.ela"

#line 250 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$5($18_unwrap$5(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[4])
#line 251 "/usr/local/lib/ela/format.ela"

#line 251 "/usr/local/lib/ela/format.ela"
        {

#line 251 "/usr/local/lib/ela/format.ela"

#line 251 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$4($18_unwrap$4(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[3])
#line 253 "/usr/local/lib/ela/format.ela"

#line 253 "/usr/local/lib/ela/format.ela"
        {

#line 253 "/usr/local/lib/ela/format.ela"

#line 253 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$3($18_unwrap$3(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[2])
#line 254 "/usr/local/lib/ela/format.ela"

#line 254 "/usr/local/lib/ela/format.ela"
        {

#line 254 "/usr/local/lib/ela/format.ela"

#line 254 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$2($18_unwrap$2(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[1])
#line 255 "/usr/local/lib/ela/format.ela"

#line 255 "/usr/local/lib/ela/format.ela"
        {

#line 255 "/usr/local/lib/ela/format.ela"

#line 255 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$1($18_unwrap$1(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[0])
#line 256 "/usr/local/lib/ela/format.ela"

#line 256 "/usr/local/lib/ela/format.ela"
        {

#line 256 "/usr/local/lib/ela/format.ela"

#line 256 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$0($18_unwrap$0(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[1])
#line 258 "/usr/local/lib/ela/format.ela"

#line 258 "/usr/local/lib/ela/format.ela"
        {

#line 258 "/usr/local/lib/ela/format.ela"

#line 258 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$1($18_unwrap$1(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[9])
#line 260 "/usr/local/lib/ela/format.ela"

#line 260 "/usr/local/lib/ela/format.ela"
        {

#line 260 "/usr/local/lib/ela/format.ela"

#line 260 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$9($18_unwrap$9(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[9])
#line 261 "/usr/local/lib/ela/format.ela"

#line 261 "/usr/local/lib/ela/format.ela"
        {

#line 261 "/usr/local/lib/ela/format.ela"

#line 261 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$9($18_unwrap$9(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[8])
#line 262 "/usr/local/lib/ela/format.ela"

#line 262 "/usr/local/lib/ela/format.ela"
        {

#line 262 "/usr/local/lib/ela/format.ela"

#line 262 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, to_string$8($18_unwrap$8(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[10])
#line 264 "/usr/local/lib/ela/format.ela"

#line 264 "/usr/local/lib/ela/format.ela"
        {

#line 264 "/usr/local/lib/ela/format.ela"

#line 264 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder,
                                  to_string$10($18_unwrap$10(&value)));
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[14])
#line 266 "/usr/local/lib/ela/format.ela"

#line 266 "/usr/local/lib/ela/format.ela"
        {

#line 267 "/usr/local/lib/ela/format.ela"

#line 267 "/usr/local/lib/ela/format.ela"
          String string = (*(String *)value.ptr);
          ;

#line 269 "/usr/local/lib/ela/format.ela"

#line 269 "/usr/local/lib/ela/format.ela"
          $31_append$14(&builder, string);
        } else
#line 247 "/usr/local/lib/ela/format.ela"
            if (value.type == _type_info.data[13])
#line 271 "/usr/local/lib/ela/format.ela"

#line 271 "/usr/local/lib/ela/format.ela"
        {

#line 271 "/usr/local/lib/ela/format.ela"

#line 271 "/usr/local/lib/ela/format.ela"
          $31_append_then_free$14(&builder, $13_as_string((*(str *)value.ptr)));
        };
      };

#line 274 "/usr/local/lib/ela/format.ela"

#line 274 "/usr/local/lib/ela/format.ela"
      value_index++;
    }
#line 275 "/usr/local/lib/ela/format.ela"
    else
#line 275 "/usr/local/lib/ela/format.ela"
    {

#line 276 "/usr/local/lib/ela/format.ela"

#line 276 "/usr/local/lib/ela/format.ela"
      $31_append$5(&builder, (u32)(*fmt.data));
    };

#line 278 "/usr/local/lib/ela/format.ela"

#line 278 "/usr/local/lib/ela/format.ela"
    fmt.data++;
  };

#line 281 "/usr/local/lib/ela/format.ela"

#line 281 "/usr/local/lib/ela/format.ela"
  return $31_get_string(&builder);
  ;
}
#line 305 "/usr/local/lib/ela/format.ela"
typedef struct UTF8_Enumerator {
  Slice$7 slice;
  u32 position;
  u32 current_char;
} UTF8_Enumerator;
typedef struct UTF8_Enumerator UTF8_Enumerator;

#line 20 "/usr/local/lib/ela/bootstrap/slice.ela"
Slice$7 $172_slice(Slice$7 self, Range_Base$1 range)
#line 20 "/usr/local/lib/ela/bootstrap/slice.ela"
{

#line 21 "/usr/local/lib/ela/bootstrap/slice.ela"

#line 21 "/usr/local/lib/ela/bootstrap/slice.ela"
  if ((range.begin < 0))
#line 21 "/usr/local/lib/ela/bootstrap/slice.ela"
  {

#line 21 "/usr/local/lib/ela/bootstrap/slice.ela"

#line 21 "/usr/local/lib/ela/bootstrap/slice.ela"
    (range.begin = 0);
  };

#line 23 "/usr/local/lib/ela/bootstrap/slice.ela"

#line 23 "/usr/local/lib/ela/bootstrap/slice.ela"
  if (((range.end == (s32)(-1)) || (range.end > self.length)))
#line 23 "/usr/local/lib/ela/bootstrap/slice.ela"
  {

#line 24 "/usr/local/lib/ela/bootstrap/slice.ela"

#line 24 "/usr/local/lib/ela/bootstrap/slice.ela"
    (range.end = self.length);
  };

#line 27 "/usr/local/lib/ela/bootstrap/slice.ela"

#line 27 "/usr/local/lib/ela/bootstrap/slice.ela"
  s32 length = (range.end - range.begin);
  ;

#line 30 "/usr/local/lib/ela/bootstrap/slice.ela"

#line 30 "/usr/local/lib/ela/bootstrap/slice.ela"
  if ((length < 0))
#line 30 "/usr/local/lib/ela/bootstrap/slice.ela"
  {

#line 30 "/usr/local/lib/ela/bootstrap/slice.ela"

#line 30 "/usr/local/lib/ela/bootstrap/slice.ela"
    return (Slice$7){0};
    ;
  };

#line 32 "/usr/local/lib/ela/bootstrap/slice.ela"

#line 32 "/usr/local/lib/ela/bootstrap/slice.ela"
  return (Slice$7){.data = (u8 *)(self.data + range.begin),
                   .length = (u64)length};
  ;
}
#line 31 "/usr/local/lib/ela/format.ela"
$tuple5$3 utf8_to_code_point(Slice$7 sequence)
#line 31 "/usr/local/lib/ela/format.ela"
{

#line 32 "/usr/local/lib/ela/format.ela"

#line 32 "/usr/local/lib/ela/format.ela"
  if ((sequence.length == 0))
#line 33 "/usr/local/lib/ela/format.ela"
  {

#line 33 "/usr/local/lib/ela/format.ela"

#line 33 "/usr/local/lib/ela/format.ela"
    return ($tuple5$3){.$0 = UTF8_ERROR, .$1 = 1};
    ;
  };

#line 35 "/usr/local/lib/ela/format.ela"

#line 35 "/usr/local/lib/ela/format.ela"
  if (($172_subscript(&sequence, 0) <= 0x7F))
#line 36 "/usr/local/lib/ela/format.ela"
  {

#line 36 "/usr/local/lib/ela/format.ela"

#line 36 "/usr/local/lib/ela/format.ela"
    return ($tuple5$3){.$0 = (u32)$172_subscript(&sequence, 0), .$1 = 1};
    ;
  };

#line 40 "/usr/local/lib/ela/format.ela"

#line 40 "/usr/local/lib/ela/format.ela"
  u32 max_length = (u32){0};
  ;

#line 41 "/usr/local/lib/ela/format.ela"

#line 41 "/usr/local/lib/ela/format.ela"
  u32 min_code_point = (u32){0};
  ;

#line 42 "/usr/local/lib/ela/format.ela"

#line 42 "/usr/local/lib/ela/format.ela"
  u32 code_point = (u32){0};
  ;

#line 44 "/usr/local/lib/ela/format.ela"

#line 44 "/usr/local/lib/ela/format.ela"
  u8 byte_0 = $172_subscript(&sequence, 0);
  ;

#line 46 "/usr/local/lib/ela/format.ela"

#line 46 "/usr/local/lib/ela/format.ela"
  if (((byte_0 & 0xF0) < 0xE0))
#line 46 "/usr/local/lib/ela/format.ela"
  {

#line 49 "/usr/local/lib/ela/format.ela"

#line 49 "/usr/local/lib/ela/format.ela"
    (max_length = 2);

#line 50 "/usr/local/lib/ela/format.ela"

#line 50 "/usr/local/lib/ela/format.ela"
    (min_code_point = 0x80);

#line 51 "/usr/local/lib/ela/format.ela"

#line 51 "/usr/local/lib/ela/format.ela"
    (code_point = (u32)(byte_0 - 0xC0));
  }
#line 52 "/usr/local/lib/ela/format.ela"
  else
#line 52 "/usr/local/lib/ela/format.ela"
      if (((byte_0 & 0xF0) == 0xE0))
#line 52 "/usr/local/lib/ela/format.ela"
  {

#line 53 "/usr/local/lib/ela/format.ela"

#line 53 "/usr/local/lib/ela/format.ela"
    (max_length = 3);

#line 54 "/usr/local/lib/ela/format.ela"

#line 54 "/usr/local/lib/ela/format.ela"
    (min_code_point = 0x0800);

#line 55 "/usr/local/lib/ela/format.ela"

#line 55 "/usr/local/lib/ela/format.ela"
    (code_point = (u32)(byte_0 - 0xE0));
  }
#line 56 "/usr/local/lib/ela/format.ela"
  else
#line 56 "/usr/local/lib/ela/format.ela"
  {

#line 57 "/usr/local/lib/ela/format.ela"

#line 57 "/usr/local/lib/ela/format.ela"
    (max_length = 4);

#line 58 "/usr/local/lib/ela/format.ela"

#line 58 "/usr/local/lib/ela/format.ela"
    (min_code_point = 0x10000);

#line 59 "/usr/local/lib/ela/format.ela"

#line 59 "/usr/local/lib/ela/format.ela"
    (code_point = (u32)(byte_0 - 0xF0));
  };

#line 62 "/usr/local/lib/ela/format.ela"

#line 62 "/usr/local/lib/ela/format.ela"
  s32 index = 1;
  ;

#line 63 "/usr/local/lib/ela/format.ela"

#line 63 "/usr/local/lib/ela/format.ela"
  while ((index < sequence.length))
#line 63 "/usr/local/lib/ela/format.ela"
  {

#line 64 "/usr/local/lib/ela/format.ela"

#line 64 "/usr/local/lib/ela/format.ela"
    index++;

#line 65 "/usr/local/lib/ela/format.ela"

#line 65 "/usr/local/lib/ela/format.ela"
    u8 byte = $172_subscript(&sequence, index);
    ;

#line 67 "/usr/local/lib/ela/format.ela"

#line 67 "/usr/local/lib/ela/format.ela"
    (max_length -= 1);

#line 69 "/usr/local/lib/ela/format.ela"

#line 69 "/usr/local/lib/ela/format.ela"
    if ((max_length == 0))
#line 70 "/usr/local/lib/ela/format.ela"
    {

#line 70 "/usr/local/lib/ela/format.ela"

#line 70 "/usr/local/lib/ela/format.ela"
      break;
      ;
    };

#line 72 "/usr/local/lib/ela/format.ela"

#line 72 "/usr/local/lib/ela/format.ela"
    u32 offset = (byte - 0x80);
    ;

#line 78 "/usr/local/lib/ela/format.ela"

#line 78 "/usr/local/lib/ela/format.ela"
    if ((offset > 0x3F))
#line 78 "/usr/local/lib/ela/format.ela"
    {

#line 79 "/usr/local/lib/ela/format.ela"

#line 79 "/usr/local/lib/ela/format.ela"
      return ($tuple5$3){.$0 = UTF8_ERROR, .$1 = 1};
      ;
    };

#line 81 "/usr/local/lib/ela/format.ela"

#line 81 "/usr/local/lib/ela/format.ela"
    (code_point = ((code_point << 6) + offset));
  };

#line 85 "/usr/local/lib/ela/format.ela"

#line 85 "/usr/local/lib/ela/format.ela"
  if ((code_point < min_code_point))
#line 85 "/usr/local/lib/ela/format.ela"
  {

#line 86 "/usr/local/lib/ela/format.ela"

#line 86 "/usr/local/lib/ela/format.ela"
    return ($tuple5$3){.$0 = UTF8_ERROR, .$1 = 1};
    ;
  };

#line 93 "/usr/local/lib/ela/format.ela"

#line 93 "/usr/local/lib/ela/format.ela"
  if (((code_point >= 0xD800) && (code_point <= 0xDFFF)))
#line 93 "/usr/local/lib/ela/format.ela"
  {

#line 94 "/usr/local/lib/ela/format.ela"

#line 94 "/usr/local/lib/ela/format.ela"
    return ($tuple5$3){.$0 = UTF8_ERROR, .$1 = 1};
    ;
  };

#line 100 "/usr/local/lib/ela/format.ela"

#line 100 "/usr/local/lib/ela/format.ela"
  if ((code_point > 0x10FFFF))
#line 100 "/usr/local/lib/ela/format.ela"
  {

#line 101 "/usr/local/lib/ela/format.ela"

#line 101 "/usr/local/lib/ela/format.ela"
    return ($tuple5$3){.$0 = UTF8_ERROR, .$1 = 1};
    ;
  };

#line 104 "/usr/local/lib/ela/format.ela"

#line 104 "/usr/local/lib/ela/format.ela"
  return ($tuple5$3){.$0 = code_point, .$1 = (s8)index};
  ;
}
#line 120 "/usr/local/lib/ela/format.ela"
List$7 utf8_encode(u32 code_point)
#line 120 "/usr/local/lib/ela/format.ela"
{

#line 121 "/usr/local/lib/ela/format.ela"

#line 121 "/usr/local/lib/ela/format.ela"
  List$7 output = (List$7){};
  ;

#line 122 "/usr/local/lib/ela/format.ela"

#line 122 "/usr/local/lib/ela/format.ela"
  if ((code_point <= 0x7F))
#line 122 "/usr/local/lib/ela/format.ela"
  {

#line 123 "/usr/local/lib/ela/format.ela"

#line 123 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)code_point);

#line 124 "/usr/local/lib/ela/format.ela"

#line 124 "/usr/local/lib/ela/format.ela"
    return output;
    ;
  }
#line 125 "/usr/local/lib/ela/format.ela"
  else
#line 125 "/usr/local/lib/ela/format.ela"
      if ((code_point <= 0x7FF))
#line 125 "/usr/local/lib/ela/format.ela"
  {

#line 126 "/usr/local/lib/ela/format.ela"

#line 126 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)(0xC0 | (code_point >> 6)));

#line 127 "/usr/local/lib/ela/format.ela"

#line 127 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)(0x80 | (code_point & 0x3F)));

#line 128 "/usr/local/lib/ela/format.ela"

#line 128 "/usr/local/lib/ela/format.ela"
    return output;
    ;
  }
#line 129 "/usr/local/lib/ela/format.ela"
  else
#line 129 "/usr/local/lib/ela/format.ela"
      if ((code_point <= 0xFFFF))
#line 129 "/usr/local/lib/ela/format.ela"
  {

#line 130 "/usr/local/lib/ela/format.ela"

#line 130 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)(0xE0 | (code_point >> 12)));

#line 131 "/usr/local/lib/ela/format.ela"

#line 131 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)(0x80 | ((code_point >> 6) & 0x3F)));

#line 132 "/usr/local/lib/ela/format.ela"

#line 132 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)(0x80 | (code_point & 0x3F)));

#line 133 "/usr/local/lib/ela/format.ela"

#line 133 "/usr/local/lib/ela/format.ela"
    return output;
    ;
  }
#line 134 "/usr/local/lib/ela/format.ela"
  else
#line 134 "/usr/local/lib/ela/format.ela"
      if ((code_point <= 0x10FFFF))
#line 134 "/usr/local/lib/ela/format.ela"
  {

#line 135 "/usr/local/lib/ela/format.ela"

#line 135 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)(0xF0 | (code_point >> 18)));

#line 136 "/usr/local/lib/ela/format.ela"

#line 136 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)(0x80 | ((code_point >> 12) & 0x3F)));

#line 137 "/usr/local/lib/ela/format.ela"

#line 137 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)(0x80 | ((code_point >> 6) & 0x3F)));

#line 138 "/usr/local/lib/ela/format.ela"

#line 138 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)(0x80 | (code_point & 0x3F)));

#line 139 "/usr/local/lib/ela/format.ela"

#line 139 "/usr/local/lib/ela/format.ela"
    return output;
    ;
  }
#line 140 "/usr/local/lib/ela/format.ela"
  else
#line 140 "/usr/local/lib/ela/format.ela"
  {

#line 141 "/usr/local/lib/ela/format.ela"

#line 141 "/usr/local/lib/ela/format.ela"
    $356_push(&output, (u8)UTF8_ERROR);

#line 142 "/usr/local/lib/ela/format.ela"

#line 142 "/usr/local/lib/ela/format.ela"
    return output;
    ;
  };
}
#line 123 "/usr/local/lib/ela/bootstrap/list.ela"
Iter$7 $356_iter(List$7 *self)
#line 123 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 124 "/usr/local/lib/ela/bootstrap/list.ela"

#line 124 "/usr/local/lib/ela/bootstrap/list.ela"
  return (Iter$7){.ptr = (u8 *)self->data,
                  .end = (u8 *)(u8 *)(self->data + self->length)};
  ;
}
#line 127 "/usr/local/lib/ela/builder.ela"
void $31_append_byte(String_Builder *self, u8 ch)
#line 127 "/usr/local/lib/ela/builder.ela"
{

#line 128 "/usr/local/lib/ela/builder.ela"

#line 128 "/usr/local/lib/ela/builder.ela"
  if ((!self->root))
#line 128 "/usr/local/lib/ela/builder.ela"
  {

#line 129 "/usr/local/lib/ela/builder.ela"

#line 129 "/usr/local/lib/ela/builder.ela"
    (self->root = (String_Builder_Block *)$30_new());

#line 130 "/usr/local/lib/ela/builder.ela"

#line 130 "/usr/local/lib/ela/builder.ela"
    (self->current = (String_Builder_Block *)self->root);
  };

#line 133 "/usr/local/lib/ela/builder.ela"

#line 133 "/usr/local/lib/ela/builder.ela"
  if ((self->current->length == STRING_BUILDER_BLOCK_MAX_LEN))
#line 133 "/usr/local/lib/ela/builder.ela"
  {

#line 134 "/usr/local/lib/ela/builder.ela"

#line 134 "/usr/local/lib/ela/builder.ela"
    (self->current->next = (String_Builder_Block *)$30_new());

#line 135 "/usr/local/lib/ela/builder.ela"

#line 135 "/usr/local/lib/ela/builder.ela"
    (self->current = (String_Builder_Block *)self->current->next);
  };

#line 138 "/usr/local/lib/ela/builder.ela"

#line 138 "/usr/local/lib/ela/builder.ela"
  (self->current->data[self->current->length] = ch);

#line 139 "/usr/local/lib/ela/builder.ela"

#line 139 "/usr/local/lib/ela/builder.ela"
  (self->current->length += 1);
}
#line 3 "/home/josh_arch/source/ela/gl-test/test.ela"
typedef struct Vec3 {
  f32 x;
  f32 y;
  f32 z;
} Vec3;

#line 9 "/home/josh_arch/source/ela/gl-test/test.ela"
typedef struct Vec2 {
  f32 x;
  f32 y;
} Vec2;

#line 14 "/home/josh_arch/source/ela/gl-test/test.ela"
typedef struct Vertex {
  Vec3 position;
  Vec3 normal;
  Vec2 texcoord;
} Vertex;
typedef struct Vertex Vertex;

#line 32 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct List$35 {
  Vertex *data;
  u64 length;
  u64 capacity;
} List$35;

#line 31 "/home/josh_arch/source/ela/gl-test/test.ela"
static Vec3 $33_new(f32 x, f32 y, f32 z)
#line 31 "/home/josh_arch/source/ela/gl-test/test.ela"
{

#line 32 "/home/josh_arch/source/ela/gl-test/test.ela"

#line 32 "/home/josh_arch/source/ela/gl-test/test.ela"
  return (Vec3){.x = (f32)x, .y = (f32)y, .z = (f32)z};
  ;
}
#line 41 "/home/josh_arch/source/ela/gl-test/test.ela"
static Vec2 $34_new(f32 x, f32 y)
#line 41 "/home/josh_arch/source/ela/gl-test/test.ela"
{

#line 42 "/home/josh_arch/source/ela/gl-test/test.ela"

#line 42 "/home/josh_arch/source/ela/gl-test/test.ela"
  return (Vec2){.x = (f32)x, .y = (f32)y};
  ;
}
#line 21 "/home/josh_arch/source/ela/gl-test/test.ela"
static Vertex $35_new(Vec3 position, Vec3 normal, Vec2 texcoord)
#line 21 "/home/josh_arch/source/ela/gl-test/test.ela"
{

#line 22 "/home/josh_arch/source/ela/gl-test/test.ela"

#line 22 "/home/josh_arch/source/ela/gl-test/test.ela"
  return (Vertex){.position = (Vec3)position,
                  .normal = (Vec3)normal,
                  .texcoord = (Vec2)texcoord};
  ;
}
#line 26 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct Init_List$35 {
  Vertex *data;
  u64 length;
} Init_List$35;
typedef struct List$35 List$35;

#line 29 "/usr/local/lib/ela/bootstrap/list.ela"
void $432_resize(List$35 *self, u64 new_capacity)
#line 29 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"
  if (((new_capacity < self->capacity) && (new_capacity < self->length)))
#line 30 "/usr/local/lib/ela/bootstrap/list.ela"
  {

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"

#line 30 "/usr/local/lib/ela/bootstrap/list.ela"
    (self->length = new_capacity);
  };

#line 32 "/usr/local/lib/ela/bootstrap/list.ela"

#line 32 "/usr/local/lib/ela/bootstrap/list.ela"
  (self->capacity = new_capacity);

#line 33 "/usr/local/lib/ela/bootstrap/list.ela"

#line 33 "/usr/local/lib/ela/bootstrap/list.ela"
  (self->data =
       (Vertex *)realloc(self->data, (sizeof(Vertex) * self->capacity)));

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"
  if ((!self->data))
#line 34 "/usr/local/lib/ela/bootstrap/list.ela"
  {

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"

#line 34 "/usr/local/lib/ela/bootstrap/list.ela"
    panic((str){.data = "Failed to allocate in List![{#type(T).name}]",
                .length = 44});
  };
}
#line 37 "/usr/local/lib/ela/bootstrap/list.ela"
void $432_push(List$35 *self, Vertex v)
#line 37 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 38 "/usr/local/lib/ela/bootstrap/list.ela"

#line 38 "/usr/local/lib/ela/bootstrap/list.ela"
  if (((self->length + 1) >= self->capacity))
#line 38 "/usr/local/lib/ela/bootstrap/list.ela"
  {

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"
    if ((self->capacity == 0))
#line 39 "/usr/local/lib/ela/bootstrap/list.ela"
    {

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"

#line 39 "/usr/local/lib/ela/bootstrap/list.ela"
      (self->capacity = 4);
    };

#line 40 "/usr/local/lib/ela/bootstrap/list.ela"

#line 40 "/usr/local/lib/ela/bootstrap/list.ela"
    $432_resize(self, (self->capacity * 2));
  };

#line 42 "/usr/local/lib/ela/bootstrap/list.ela"

#line 42 "/usr/local/lib/ela/bootstrap/list.ela"
  (self->data[self->length] = v);

#line 43 "/usr/local/lib/ela/bootstrap/list.ela"

#line 43 "/usr/local/lib/ela/bootstrap/list.ela"
  self->length++;
}
#line 112 "/usr/local/lib/ela/bootstrap/list.ela"
static List$35 $432_init(Init_List$35 init)
#line 112 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 113 "/usr/local/lib/ela/bootstrap/list.ela"

#line 113 "/usr/local/lib/ela/bootstrap/list.ela"
  List$35 self = (List$35){};
  ;

#line 114 "/usr/local/lib/ela/bootstrap/list.ela"

#line 114 "/usr/local/lib/ela/bootstrap/list.ela"
  {
    Range_Base$1 $_range_id0 = (Range_Base$1){.begin = 0, .end = init.length};
    Range_Enumerator$1 $_loop_id0 = $53_enumerator(&$_range_id0);
    while (!$85_done($_loop_id0)) {
      s32 idx = $85_current($_loop_id0);
      $85_next(&$_loop_id0);

#line 114 "/usr/local/lib/ela/bootstrap/list.ela"
      {

#line 115 "/usr/local/lib/ela/bootstrap/list.ela"

#line 115 "/usr/local/lib/ela/bootstrap/list.ela"
        $432_push(&self, init.data[idx]);
      }
    }
  };

#line 117 "/usr/local/lib/ela/bootstrap/list.ela"

#line 117 "/usr/local/lib/ela/bootstrap/list.ela"
  return self;
  ;
}
#line 49 "/home/josh_arch/source/ela/gl-test/test.ela"
List$35 cube(f32 scale)
#line 49 "/home/josh_arch/source/ela/gl-test/test.ela"
{

#line 50 "/home/josh_arch/source/ela/gl-test/test.ela"

#line 50 "/home/josh_arch/source/ela/gl-test/test.ela"
  return $432_init((Init_List$35){
      .data =
          (Vertex[]){$35_new($33_new((f32)(-(scale / 2)), (f32)(-(scale / 2)),
                                     (f32)(-(scale / 2))),
                             $33_new(0.0f, 0.0f, (f32)(-scale)),
                             $34_new(0.0f, 0.0f)),
                     $35_new($33_new((scale / 2), (f32)(-(scale / 2)),
                                     (f32)(-(scale / 2))),
                             $33_new(0.0f, 0.0f, (f32)(-scale)),
                             $34_new(scale, 0.0f)),
                     $35_new(
                         $33_new((scale / 2), (scale / 2), (f32)(-(scale / 2))),
                         $33_new(0.0f, 0.0f, (f32)(-scale)),
                         $34_new(scale, scale)),
                     $35_new(
                         $33_new((scale / 2), (scale / 2), (f32)(-(scale / 2))),
                         $33_new(0.0f, 0.0f, (f32)(-scale)),
                         $34_new(scale, scale)),
                     $35_new($33_new((f32)(-(scale / 2)), (scale / 2),
                                     (f32)(-(scale / 2))),
                             $33_new(0.0f, 0.0f, (f32)(-scale)),
                             $34_new(0.0f, scale)),
                     $35_new($33_new((f32)(-(scale / 2)), (f32)(-(scale / 2)),
                                     (f32)(-(scale / 2))),
                             $33_new(0.0f, 0.0f, (f32)(-scale)),
                             $34_new(0.0f, 0.0f)),
                     $35_new($33_new((f32)(-(scale / 2)), (f32)(-(scale / 2)),
                                     (scale / 2)),
                             $33_new(0.0f, 0.0f, scale), $34_new(0.0f, 0.0f)),
                     $35_new(
                         $33_new((scale / 2), (f32)(-(scale / 2)), (scale / 2)),
                         $33_new(0.0f, 0.0f, scale), $34_new(scale, 0.0f)),
                     $35_new($33_new((scale / 2), (scale / 2), (scale / 2)),
                             $33_new(0.0f, 0.0f, scale), $34_new(scale, scale)),
                     $35_new($33_new((scale / 2), (scale / 2), (scale / 2)),
                             $33_new(0.0f, 0.0f, scale), $34_new(scale, scale)),
                     $35_new(
                         $33_new((f32)(-(scale / 2)), (scale / 2), (scale / 2)),
                         $33_new(0.0f, 0.0f, scale), $34_new(0.0f, scale)),
                     $35_new($33_new((f32)(-(scale / 2)), (f32)(-(scale / 2)),
                                     (scale / 2)),
                             $33_new(0.0f, 0.0f, scale), $34_new(0.0f, 0.0f)),
                     $35_new(
                         $33_new((f32)(-(scale / 2)), (scale / 2), (scale / 2)),
                         $33_new((f32)(-scale), 0.0f, 0.0f),
                         $34_new(scale, 0.0f)),
                     $35_new($33_new((f32)(-(scale / 2)), (scale / 2),
                                     (f32)(-(scale / 2))),
                             $33_new((f32)(-scale), 0.0f, 0.0f),
                             $34_new(scale, scale)),
                     $35_new($33_new((f32)(-(scale / 2)), (f32)(-(scale / 2)),
                                     (f32)(-(scale / 2))),
                             $33_new((f32)(-scale), 0.0f, 0.0f),
                             $34_new(0.0f, scale)),
                     $35_new($33_new((f32)(-(scale / 2)), (f32)(-(scale / 2)),
                                     (f32)(-(scale / 2))),
                             $33_new((f32)(-scale), 0.0f, 0.0f),
                             $34_new(0.0f, scale)),
                     $35_new($33_new((f32)(-(scale / 2)), (f32)(-(scale / 2)),
                                     (scale / 2)),
                             $33_new((f32)(-scale), 0.0f, 0.0f),
                             $34_new(0.0f, 0.0f)),
                     $35_new(
                         $33_new((f32)(-(scale / 2)), (scale / 2), (scale / 2)),
                         $33_new((f32)(-scale), 0.0f, 0.0f),
                         $34_new(scale, 0.0f)),
                     $35_new($33_new((scale / 2), (scale / 2), (scale / 2)),
                             $33_new(scale, 0.0f, 0.0f), $34_new(scale, 0.0f)),
                     $35_new(
                         $33_new((scale / 2), (scale / 2), (f32)(-(scale / 2))),
                         $33_new(scale, 0.0f, 0.0f), $34_new(scale, scale)),
                     $35_new($33_new((scale / 2), (f32)(-(scale / 2)),
                                     (f32)(-(scale / 2))),
                             $33_new(scale, 0.0f, 0.0f), $34_new(0.0f, scale)),
                     $35_new($33_new((scale / 2), (f32)(-(scale / 2)),
                                     (f32)(-(scale / 2))),
                             $33_new(scale, 0.0f, 0.0f), $34_new(0.0f, scale)),
                     $35_new(
                         $33_new((scale / 2), (f32)(-(scale / 2)), (scale / 2)),
                         $33_new(scale, 0.0f, 0.0f), $34_new(0.0f, 0.0f)),
                     $35_new($33_new((scale / 2), (scale / 2), (scale / 2)),
                             $33_new(scale, 0.0f, 0.0f), $34_new(scale, 0.0f)),
                     $35_new($33_new((f32)(-(scale / 2)), (f32)(-(scale / 2)),
                                     (f32)(-(scale / 2))),
                             $33_new(0.0f, (f32)(-scale), 0.0f),
                             $34_new(0.0f, scale)),
                     $35_new($33_new((scale / 2), (f32)(-(scale / 2)),
                                     (f32)(-(scale / 2))),
                             $33_new(0.0f, (f32)(-scale), 0.0f),
                             $34_new(scale, scale)),
                     $35_new(
                         $33_new((scale / 2), (f32)(-(scale / 2)), (scale / 2)),
                         $33_new(0.0f, (f32)(-scale), 0.0f),
                         $34_new(scale, 0.0f)),
                     $35_new(
                         $33_new((scale / 2), (f32)(-(scale / 2)), (scale / 2)),
                         $33_new(0.0f, (f32)(-scale), 0.0f),
                         $34_new(scale, 0.0f)),
                     $35_new($33_new((f32)(-(scale / 2)), (f32)(-(scale / 2)),
                                     (scale / 2)),
                             $33_new(0.0f, (f32)(-scale), 0.0f),
                             $34_new(0.0f, 0.0f)),
                     $35_new($33_new((f32)(-(scale / 2)), (f32)(-(scale / 2)),
                                     (f32)(-(scale / 2))),
                             $33_new(0.0f, (f32)(-scale), 0.0f),
                             $34_new(0.0f, scale)),
                     $35_new($33_new((f32)(-(scale / 2)), (scale / 2),
                                     (f32)(-(scale / 2))),
                             $33_new(0.0f, scale, 0.0f), $34_new(0.0f, scale)),
                     $35_new(
                         $33_new((scale / 2), (scale / 2), (f32)(-(scale / 2))),
                         $33_new(0.0f, scale, 0.0f), $34_new(scale, scale)),
                     $35_new($33_new((scale / 2), (scale / 2), (scale / 2)),
                             $33_new(0.0f, scale, 0.0f), $34_new(scale, 0.0f)),
                     $35_new($33_new((scale / 2), (scale / 2), (scale / 2)),
                             $33_new(0.0f, scale, 0.0f), $34_new(scale, 0.0f)),
                     $35_new(
                         $33_new((f32)(-(scale / 2)), (scale / 2), (scale / 2)),
                         $33_new(0.0f, scale, 0.0f), $34_new(0.0f, 0.0f)),
                     $35_new($33_new((f32)(-(scale / 2)), (scale / 2),
                                     (f32)(-(scale / 2))),
                             $33_new(0.0f, scale, 0.0f), $34_new(0.0f, scale))},
      .length = 36});
  ;
}
#line 54 "/usr/local/lib/ela/bootstrap/interfaces.ela"
typedef struct Iter$35 {
  Vertex *ptr;
  Vertex *end;
} Iter$35;

#line 123 "/usr/local/lib/ela/bootstrap/list.ela"
Iter$35 $432_iter(List$35 *self)
#line 123 "/usr/local/lib/ela/bootstrap/list.ela"
{

#line 124 "/usr/local/lib/ela/bootstrap/list.ela"

#line 124 "/usr/local/lib/ela/bootstrap/list.ela"
  return (Iter$35){.ptr = (Vertex *)self->data,
                   .end = (Vertex *)(Vertex *)(self->data + self->length)};
  ;
}
#line 69 "/usr/local/lib/ela/bootstrap/interfaces.ela"
bool $446_done(Iter$35 self)
#line 69 "/usr/local/lib/ela/bootstrap/interfaces.ela"
{

#line 70 "/usr/local/lib/ela/bootstrap/interfaces.ela"

#line 70 "/usr/local/lib/ela/bootstrap/interfaces.ela"
  return ((self.ptr >= self.end) || (self.ptr == self.end));
  ;
}
#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"
Vertex *$446_current(Iter$35 self)
#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"
{

#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"

#line 61 "/usr/local/lib/ela/bootstrap/interfaces.ela"
  return self.ptr;
  ;
}
typedef struct Iter$35 Iter$35;

#line 64 "/usr/local/lib/ela/bootstrap/interfaces.ela"
void $446_next(Iter$35 *self)
#line 64 "/usr/local/lib/ela/bootstrap/interfaces.ela"
{

#line 65 "/usr/local/lib/ela/bootstrap/interfaces.ela"

#line 65 "/usr/local/lib/ela/bootstrap/interfaces.ela"
  self->ptr++;
}
#line 138 "/usr/local/lib/ela/bootstrap/reflection.ela"
static any $18_new$9(f32 *t)
#line 138 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 139 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 139 "/usr/local/lib/ela/bootstrap/reflection.ela"
  static Type *type = (Type *){};
  ;

#line 140 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 140 "/usr/local/lib/ela/bootstrap/reflection.ela"
  if ((!type))
#line 140 "/usr/local/lib/ela/bootstrap/reflection.ela"
  {

#line 140 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 140 "/usr/local/lib/ela/bootstrap/reflection.ela"
    (type = (Type *)_type_info.data[9]);
  };

#line 141 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 141 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (any){.ptr = (void *)t, .type = (Type *)type};
  ;
}
#line 138 "/usr/local/lib/ela/bootstrap/reflection.ela"
static any $18_new$14(String *t)
#line 138 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 139 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 139 "/usr/local/lib/ela/bootstrap/reflection.ela"
  static Type *type = (Type *){};
  ;

#line 140 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 140 "/usr/local/lib/ela/bootstrap/reflection.ela"
  if ((!type))
#line 140 "/usr/local/lib/ela/bootstrap/reflection.ela"
  {

#line 140 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 140 "/usr/local/lib/ela/bootstrap/reflection.ela"
    (type = (Type *)_type_info.data[14]);
  };

#line 141 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 141 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (any){.ptr = (void *)t, .type = (Type *)type};
  ;
}
#line 290 "/usr/local/lib/ela/format.ela"
static void println$14(String message)
#line 290 "/usr/local/lib/ela/format.ela"
{

#line 291 "/usr/local/lib/ela/format.ela"

#line 291 "/usr/local/lib/ela/format.ela"
  String formatted =
      format((str){.data = "%", .length = 1},
             (Init_List$18){.data = (any[]){$18_new$14((&message)),
                                            $18_new$14((&message))},
                            .length = 2});
  ;

#line 292 "/usr/local/lib/ela/format.ela"

#line 292 "/usr/local/lib/ela/format.ela"
  printf("%s\n", formatted.data);

#line 293 "/usr/local/lib/ela/format.ela"

#line 293 "/usr/local/lib/ela/format.ela"
  $14_deinit(&formatted);
}
#line 1 "/usr/local/lib/ela/bootstrap/lib.ela"
;
;
;
;
;

#line 38 "/usr/local/lib/ela/bootstrap/typedef.ela"
typedef struct Type Type;
;
;
;

#line 56 "/usr/local/lib/ela/bootstrap/typedef.ela"
u8 RESULT_IS_ERR = 0;
;

#line 57 "/usr/local/lib/ela/bootstrap/typedef.ela"
u8 RESULT_IS_OK = 1;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;

#line 139 "/usr/local/lib/ela/bootstrap/interfaces.ela"
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;

#line 6 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 6 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s32 system(u8 *);
;
#line 8 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 9 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 10 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 11 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 13 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 14 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 16 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 16 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s32 scanf(u8 *, ...);
;
#line 17 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 17 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s32 getchar();
;
#line 19 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 19 "/usr/local/lib/ela/bootstrap/libc.ela"
extern void sleep(s32);
;
#line 20 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 20 "/usr/local/lib/ela/bootstrap/libc.ela"
extern void usleep(s32);
;
#line 22 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 23 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 23 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s32 sprintf(u8 *, u8 *, ...);
;
#line 25 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 26 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 26 "/usr/local/lib/ela/bootstrap/libc.ela"
extern u8 *strndup(u8 *, u64);
;
#line 27 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 27 "/usr/local/lib/ela/bootstrap/libc.ela"
extern u8 *strerror(s32);
;
#line 28 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 28 "/usr/local/lib/ela/bootstrap/libc.ela"
extern u8 *strtok(u8 *, u8 *);
;
#line 29 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 29 "/usr/local/lib/ela/bootstrap/libc.ela"
extern u8 *strcat(u8 *, u8 *);
;
#line 30 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 30 "/usr/local/lib/ela/bootstrap/libc.ela"
extern u8 *strncat(u8 *, u8 *, u64);
;
#line 32 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 32 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s64 strtol(u8 *, u8 ***, s32);
;
#line 33 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 33 "/usr/local/lib/ela/bootstrap/libc.ela"
extern u64 strtoul(u8 *, u8 ***, s32);
;
#line 34 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 34 "/usr/local/lib/ela/bootstrap/libc.ela"
extern f64 strtod(u8 *, u8 ***);
;
#line 36 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 36 "/usr/local/lib/ela/bootstrap/libc.ela"
extern s32 atoi(u8 *);
;
#line 37 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 37 "/usr/local/lib/ela/bootstrap/libc.ela"
extern f64 atof(u8 *);
;
#line 42 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 43 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 44 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 44 "/usr/local/lib/ela/bootstrap/libc.ela"
extern void *memset(void *, s32, u64);
;
#line 45 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 46 "/usr/local/lib/ela/bootstrap/libc.ela"
;
#line 47 "/usr/local/lib/ela/bootstrap/libc.ela"
;
;

#line 50 "/usr/local/lib/ela/bootstrap/libc.ela"
s32 isalnum(s32 c)
#line 50 "/usr/local/lib/ela/bootstrap/libc.ela"
{

#line 51 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 51 "/usr/local/lib/ela/bootstrap/libc.ela"
  return (s32)((((c >= '0') && (c <= '9')) || ((c >= 'A') && (c <= 'Z'))) ||
               ((c >= 'a') && (c <= 'z')));
  ;
};

#line 54 "/usr/local/lib/ela/bootstrap/libc.ela"
s32 isalpha(s32 c)
#line 54 "/usr/local/lib/ela/bootstrap/libc.ela"
{

#line 55 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 55 "/usr/local/lib/ela/bootstrap/libc.ela"
  return (s32)(((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')));
  ;
};

#line 58 "/usr/local/lib/ela/bootstrap/libc.ela"
s32 isspace(s32 c)
#line 58 "/usr/local/lib/ela/bootstrap/libc.ela"
{

#line 59 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 59 "/usr/local/lib/ela/bootstrap/libc.ela"
  return (s32)((((((c == ' ') || (c == '\t')) || (c == '\n')) || (c == '\v')) ||
                (c == '\f')) ||
               (c == '\r'));
  ;
};

#line 62 "/usr/local/lib/ela/bootstrap/libc.ela"
s32 isdigit(s32 c)
#line 62 "/usr/local/lib/ela/bootstrap/libc.ela"
{

#line 63 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 63 "/usr/local/lib/ela/bootstrap/libc.ela"
  return (s32)((c >= '0') && (c <= '9'));
  ;
};

#line 66 "/usr/local/lib/ela/bootstrap/libc.ela"
s32 islower(s32 c)
#line 66 "/usr/local/lib/ela/bootstrap/libc.ela"
{

#line 67 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 67 "/usr/local/lib/ela/bootstrap/libc.ela"
  return (s32)((c >= 'a') && (c <= 'z'));
  ;
};

#line 70 "/usr/local/lib/ela/bootstrap/libc.ela"
s32 isupper(s32 c)
#line 70 "/usr/local/lib/ela/bootstrap/libc.ela"
{

#line 71 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 71 "/usr/local/lib/ela/bootstrap/libc.ela"
  return (s32)((c >= 'A') && (c <= 'Z'));
  ;
};

#line 74 "/usr/local/lib/ela/bootstrap/libc.ela"
s32 isprint(s32 c)
#line 74 "/usr/local/lib/ela/bootstrap/libc.ela"
{

#line 75 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 75 "/usr/local/lib/ela/bootstrap/libc.ela"
  return (s32)((c >= 32) && (c < 127));
  ;
};

#line 78 "/usr/local/lib/ela/bootstrap/libc.ela"
s32 ispunct(s32 c)
#line 78 "/usr/local/lib/ela/bootstrap/libc.ela"
{

#line 79 "/usr/local/lib/ela/bootstrap/libc.ela"

#line 79 "/usr/local/lib/ela/bootstrap/libc.ela"
  return (s32)(((((c >= '!') && (c <= '/')) || ((c >= ':') && (c <= '@'))) ||
                ((c >= '[') && (c <= '`'))) ||
               ((c >= '{') && (c <= '~')));
  ;
};
;
;
;

#line 3 "/usr/local/lib/ela/bootstrap/list.ela"
void panic(str msg);
;

#line 6 "/usr/local/lib/ela/bootstrap/list.ela"
;
#line 98 "/usr/local/lib/ela/bootstrap/list.ela"
;
#line 111 "/usr/local/lib/ela/bootstrap/list.ela"
;
;
;
;
;
;
;
;

#line 3 "/usr/local/lib/ela/bootstrap/str.ela"
;
;

#line 14 "/usr/local/lib/ela/bootstrap/str.ela"
static str $13_empty()
#line 14 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 15 "/usr/local/lib/ela/bootstrap/str.ela"

#line 15 "/usr/local/lib/ela/bootstrap/str.ela"
  return (str){0};
  ;
}
#line 22 "/usr/local/lib/ela/bootstrap/str.ela"
bool $13_starts_with(str *self, u8 *prefix)
#line 22 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 23 "/usr/local/lib/ela/bootstrap/str.ela"

#line 23 "/usr/local/lib/ela/bootstrap/str.ela"
  u32 prefix_len = strlen(prefix);
  ;

#line 24 "/usr/local/lib/ela/bootstrap/str.ela"

#line 24 "/usr/local/lib/ela/bootstrap/str.ela"
  if ((self->length < prefix_len))
#line 24 "/usr/local/lib/ela/bootstrap/str.ela"
  {

#line 24 "/usr/local/lib/ela/bootstrap/str.ela"

#line 24 "/usr/local/lib/ela/bootstrap/str.ela"
    return false;
    ;
  };

#line 25 "/usr/local/lib/ela/bootstrap/str.ela"

#line 25 "/usr/local/lib/ela/bootstrap/str.ela"
  {
    Range_Base$1 $_range_id0 = (Range_Base$1){.begin = 0, .end = prefix_len};
    Range_Enumerator$1 $_loop_id0 = $53_enumerator(&$_range_id0);
    while (!$85_done($_loop_id0)) {
      s32 i = $85_current($_loop_id0);
      $85_next(&$_loop_id0);

#line 25 "/usr/local/lib/ela/bootstrap/str.ela"
      {

#line 26 "/usr/local/lib/ela/bootstrap/str.ela"

#line 26 "/usr/local/lib/ela/bootstrap/str.ela"
        if ((self->data[i] != prefix[i]))
#line 26 "/usr/local/lib/ela/bootstrap/str.ela"
        {

#line 26 "/usr/local/lib/ela/bootstrap/str.ela"

#line 26 "/usr/local/lib/ela/bootstrap/str.ela"
          return false;
          ;
        };
      }
    }
  };

#line 28 "/usr/local/lib/ela/bootstrap/str.ela"

#line 28 "/usr/local/lib/ela/bootstrap/str.ela"
  return true;
  ;
}
#line 31 "/usr/local/lib/ela/bootstrap/str.ela"
bool $13_ends_with(str *self, u8 *suffix)
#line 31 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 32 "/usr/local/lib/ela/bootstrap/str.ela"

#line 32 "/usr/local/lib/ela/bootstrap/str.ela"
  u32 suffix_len = strlen(suffix);
  ;

#line 33 "/usr/local/lib/ela/bootstrap/str.ela"

#line 33 "/usr/local/lib/ela/bootstrap/str.ela"
  if ((self->length < suffix_len))
#line 33 "/usr/local/lib/ela/bootstrap/str.ela"
  {

#line 33 "/usr/local/lib/ela/bootstrap/str.ela"

#line 33 "/usr/local/lib/ela/bootstrap/str.ela"
    return false;
    ;
  };

#line 34 "/usr/local/lib/ela/bootstrap/str.ela"

#line 34 "/usr/local/lib/ela/bootstrap/str.ela"
  {
    Range_Base$1 $_range_id0 = (Range_Base$1){.begin = 0, .end = suffix_len};
    Range_Enumerator$1 $_loop_id0 = $53_enumerator(&$_range_id0);
    while (!$85_done($_loop_id0)) {
      s32 i = $85_current($_loop_id0);
      $85_next(&$_loop_id0);

#line 34 "/usr/local/lib/ela/bootstrap/str.ela"
      {

#line 35 "/usr/local/lib/ela/bootstrap/str.ela"

#line 35 "/usr/local/lib/ela/bootstrap/str.ela"
        if ((self->data[((self->length - suffix_len) + i)] != suffix[i]))
#line 35 "/usr/local/lib/ela/bootstrap/str.ela"
        {

#line 35 "/usr/local/lib/ela/bootstrap/str.ela"

#line 35 "/usr/local/lib/ela/bootstrap/str.ela"
          return false;
          ;
        };
      }
    }
  };

#line 37 "/usr/local/lib/ela/bootstrap/str.ela"

#line 37 "/usr/local/lib/ela/bootstrap/str.ela"
  return true;
  ;
}
#line 40 "/usr/local/lib/ela/bootstrap/str.ela"
Slice$7 $13_slice(str *self, Range_Base$1 range)
#line 40 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 41 "/usr/local/lib/ela/bootstrap/str.ela"

#line 41 "/usr/local/lib/ela/bootstrap/str.ela"
  auto $temp_tuple$0 = ($tuple1$1){.$0 = range.begin, .$1 = range.end};

#line 41 "/usr/local/lib/ela/bootstrap/str.ela"
  auto start = $temp_tuple$0.$0;
  auto end = $temp_tuple$0.$1;

#line 41 "/usr/local/lib/ela/bootstrap/str.ela"

#line 41 "/usr/local/lib/ela/bootstrap/str.ela"
  ;

#line 42 "/usr/local/lib/ela/bootstrap/str.ela"

#line 42 "/usr/local/lib/ela/bootstrap/str.ela"
  s32 length = (end - start);
  ;

#line 44 "/usr/local/lib/ela/bootstrap/str.ela"

#line 44 "/usr/local/lib/ela/bootstrap/str.ela"
  if ((((start < 0) || (length < 0)) || ((start + length) > self->length)))
#line 44 "/usr/local/lib/ela/bootstrap/str.ela"
  {

#line 45 "/usr/local/lib/ela/bootstrap/str.ela"

#line 45 "/usr/local/lib/ela/bootstrap/str.ela"
    return (Slice$7){0};
    ;
  };

#line 48 "/usr/local/lib/ela/bootstrap/str.ela"

#line 48 "/usr/local/lib/ela/bootstrap/str.ela"
  return (Slice$7){.data = (u8 *)(self->data + start), .length = (u64)length};
  ;
};
;

#line 74 "/usr/local/lib/ela/bootstrap/str.ela"
bool $13_neq(str self, str other)
#line 74 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 75 "/usr/local/lib/ela/bootstrap/str.ela"

#line 75 "/usr/local/lib/ela/bootstrap/str.ela"
  return (!$13_eq(self, other));
  ;
};

#line 80 "/usr/local/lib/ela/bootstrap/str.ela"
u64 $13_hash(str self)
#line 80 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 81 "/usr/local/lib/ela/bootstrap/str.ela"

#line 81 "/usr/local/lib/ela/bootstrap/str.ela"
  u64 hash = 0xCBF29CE484222325;
  ;

#line 82 "/usr/local/lib/ela/bootstrap/str.ela"

#line 82 "/usr/local/lib/ela/bootstrap/str.ela"
  {
    str $_range_id0 = self;
    Iter$7 $_loop_id0 = $13_iter(&$_range_id0);
    while (!$177_done($_loop_id0)) {
      u8 byte = *$177_current($_loop_id0);
      $177_next(&$_loop_id0);

#line 82 "/usr/local/lib/ela/bootstrap/str.ela"
      {

#line 83 "/usr/local/lib/ela/bootstrap/str.ela"

#line 83 "/usr/local/lib/ela/bootstrap/str.ela"
        (hash ^= byte);

#line 84 "/usr/local/lib/ela/bootstrap/str.ela"

#line 84 "/usr/local/lib/ela/bootstrap/str.ela"
        (hash *= 0x100000001B3);
      }
    }
  };

#line 86 "/usr/local/lib/ela/bootstrap/str.ela"

#line 86 "/usr/local/lib/ela/bootstrap/str.ela"
  return hash;
  ;
};

#line 91 "/usr/local/lib/ela/bootstrap/str.ela"
Slice$5 $13_as_char_slice(str self)
#line 91 "/usr/local/lib/ela/bootstrap/str.ela"
{

#line 92 "/usr/local/lib/ela/bootstrap/str.ela"

#line 92 "/usr/local/lib/ela/bootstrap/str.ela"
  return (Slice$5){.data = (u32 *)self.data, .length = (u64)self.length};
  ;
};
;

#line 4 "/usr/local/lib/ela/bootstrap/String.ela"

#line 5 "/usr/local/lib/ela/bootstrap/String.ela"
str $14_replace(String *self, u8 *old, u8 *replacement)
#line 5 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 6 "/usr/local/lib/ela/bootstrap/String.ela"

#line 6 "/usr/local/lib/ela/bootstrap/String.ela"
  u32 old_len = strlen(old);
  ;

#line 7 "/usr/local/lib/ela/bootstrap/String.ela"

#line 7 "/usr/local/lib/ela/bootstrap/String.ela"
  u32 new_len = strlen(replacement);
  ;

#line 8 "/usr/local/lib/ela/bootstrap/String.ela"

#line 8 "/usr/local/lib/ela/bootstrap/String.ela"
  str result = (str){0};
  ;

#line 9 "/usr/local/lib/ela/bootstrap/String.ela"

#line 9 "/usr/local/lib/ela/bootstrap/String.ela"
  {
    Range_Base$1 $_range_id0 = (Range_Base$1){.begin = 0, .end = self->length};
    Range_Enumerator$1 $_loop_id0 = $53_enumerator(&$_range_id0);
    while (!$85_done($_loop_id0)) {
      s32 i = $85_current($_loop_id0);
      $85_next(&$_loop_id0);

#line 9 "/usr/local/lib/ela/bootstrap/String.ela"
      {

#line 10 "/usr/local/lib/ela/bootstrap/String.ela"

#line 10 "/usr/local/lib/ela/bootstrap/String.ela"
        if ((strncmp((self->data + i), old, old_len) == 0))
#line 10 "/usr/local/lib/ela/bootstrap/String.ela"
        {

#line 11 "/usr/local/lib/ela/bootstrap/String.ela"

#line 11 "/usr/local/lib/ela/bootstrap/String.ela"
          (result.data =
               (u8 *)realloc(result.data, ((result.length + new_len) + 1)));

#line 12 "/usr/local/lib/ela/bootstrap/String.ela"

#line 12 "/usr/local/lib/ela/bootstrap/String.ela"
          memcpy((result.data + result.length), replacement, new_len);

#line 13 "/usr/local/lib/ela/bootstrap/String.ela"

#line 13 "/usr/local/lib/ela/bootstrap/String.ela"
          (result.length += new_len);

#line 14 "/usr/local/lib/ela/bootstrap/String.ela"

#line 14 "/usr/local/lib/ela/bootstrap/String.ela"
          (i += (old_len - 1));
        }
#line 15 "/usr/local/lib/ela/bootstrap/String.ela"
        else
#line 15 "/usr/local/lib/ela/bootstrap/String.ela"
        {

#line 16 "/usr/local/lib/ela/bootstrap/String.ela"

#line 16 "/usr/local/lib/ela/bootstrap/String.ela"
          (result.data = (u8 *)realloc(result.data, ((result.length + 1) + 1)));

#line 17 "/usr/local/lib/ela/bootstrap/String.ela"

#line 17 "/usr/local/lib/ela/bootstrap/String.ela"
          (result.data[result.length] = self->data[i]);

#line 18 "/usr/local/lib/ela/bootstrap/String.ela"

#line 18 "/usr/local/lib/ela/bootstrap/String.ela"
          result.length++;
        };
      }
    }
  };

#line 21 "/usr/local/lib/ela/bootstrap/String.ela"

#line 21 "/usr/local/lib/ela/bootstrap/String.ela"
  (result.data[result.length] = 0);

#line 22 "/usr/local/lib/ela/bootstrap/String.ela"

#line 22 "/usr/local/lib/ela/bootstrap/String.ela"
  return result;
  ;
}
#line 35 "/usr/local/lib/ela/bootstrap/String.ela"
static String $14_from_ptr(u8 *begin, u8 *end)
#line 35 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 36 "/usr/local/lib/ela/bootstrap/String.ela"

#line 36 "/usr/local/lib/ela/bootstrap/String.ela"
  String self = (String){};
  ;

#line 37 "/usr/local/lib/ela/bootstrap/String.ela"

#line 37 "/usr/local/lib/ela/bootstrap/String.ela"
  (self.length = (end - begin));

#line 38 "/usr/local/lib/ela/bootstrap/String.ela"

#line 38 "/usr/local/lib/ela/bootstrap/String.ela"
  (self.capacity = self.length);

#line 39 "/usr/local/lib/ela/bootstrap/String.ela"

#line 39 "/usr/local/lib/ela/bootstrap/String.ela"
  (self.data = (u8 *)malloc(((sizeof(u8) * self.length) + 1)));

#line 40 "/usr/local/lib/ela/bootstrap/String.ela"

#line 40 "/usr/local/lib/ela/bootstrap/String.ela"
  memcpy(self.data, begin, self.length);

#line 41 "/usr/local/lib/ela/bootstrap/String.ela"

#line 41 "/usr/local/lib/ela/bootstrap/String.ela"
  (self.data[self.length] = 0);

#line 42 "/usr/local/lib/ela/bootstrap/String.ela"

#line 42 "/usr/local/lib/ela/bootstrap/String.ela"
  return self;
  ;
};
#line 49 "/usr/local/lib/ela/bootstrap/String.ela"

#line 57 "/usr/local/lib/ela/bootstrap/String.ela"
void $14_push(String *self, u8 ch)
#line 57 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 58 "/usr/local/lib/ela/bootstrap/String.ela"

#line 58 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((self->capacity == 0))
#line 58 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 58 "/usr/local/lib/ela/bootstrap/String.ela"

#line 58 "/usr/local/lib/ela/bootstrap/String.ela"
    (self->capacity = (256 / 3));
  };

#line 59 "/usr/local/lib/ela/bootstrap/String.ela"

#line 59 "/usr/local/lib/ela/bootstrap/String.ela"
  if (((self->length + 1) >= self->capacity))
#line 59 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 60 "/usr/local/lib/ela/bootstrap/String.ela"

#line 60 "/usr/local/lib/ela/bootstrap/String.ela"
    $14_resize(self, ((self->capacity * 3) + 1));
  };

#line 62 "/usr/local/lib/ela/bootstrap/String.ela"

#line 62 "/usr/local/lib/ela/bootstrap/String.ela"
  (self->data[self->length] = ch);

#line 63 "/usr/local/lib/ela/bootstrap/String.ela"

#line 63 "/usr/local/lib/ela/bootstrap/String.ela"
  self->length++;

#line 64 "/usr/local/lib/ela/bootstrap/String.ela"

#line 64 "/usr/local/lib/ela/bootstrap/String.ela"
  (self->data[self->length] = '\0');
}
#line 67 "/usr/local/lib/ela/bootstrap/String.ela"
u8 $14_pop(String *self)
#line 67 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 68 "/usr/local/lib/ela/bootstrap/String.ela"

#line 68 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((self->length == 0))
#line 68 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 68 "/usr/local/lib/ela/bootstrap/String.ela"

#line 68 "/usr/local/lib/ela/bootstrap/String.ela"
    return (u8)'\0';
    ;
  };

#line 69 "/usr/local/lib/ela/bootstrap/String.ela"

#line 69 "/usr/local/lib/ela/bootstrap/String.ela"
  u8 ch = self->data[self->length--];
  ;

#line 70 "/usr/local/lib/ela/bootstrap/String.ela"

#line 70 "/usr/local/lib/ela/bootstrap/String.ela"
  (self->data[self->length] = '\0');

#line 71 "/usr/local/lib/ela/bootstrap/String.ela"

#line 71 "/usr/local/lib/ela/bootstrap/String.ela"
  return ch;
  ;
}
#line 74 "/usr/local/lib/ela/bootstrap/String.ela"
u8 $14_pop_front(String *self)
#line 74 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 75 "/usr/local/lib/ela/bootstrap/String.ela"

#line 75 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((self->length == 0))
#line 75 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 75 "/usr/local/lib/ela/bootstrap/String.ela"

#line 75 "/usr/local/lib/ela/bootstrap/String.ela"
    return (u8)'\0';
    ;
  };

#line 76 "/usr/local/lib/ela/bootstrap/String.ela"

#line 76 "/usr/local/lib/ela/bootstrap/String.ela"
  u8 ch = self->data[0];
  ;

#line 77 "/usr/local/lib/ela/bootstrap/String.ela"

#line 77 "/usr/local/lib/ela/bootstrap/String.ela"
  memmove(self->data, (self->data + 1), (self->length - 1));

#line 78 "/usr/local/lib/ela/bootstrap/String.ela"

#line 78 "/usr/local/lib/ela/bootstrap/String.ela"
  self->length--;

#line 79 "/usr/local/lib/ela/bootstrap/String.ela"

#line 79 "/usr/local/lib/ela/bootstrap/String.ela"
  (self->data[self->length] = '\0');

#line 80 "/usr/local/lib/ela/bootstrap/String.ela"

#line 80 "/usr/local/lib/ela/bootstrap/String.ela"
  return ch;
  ;
}
#line 83 "/usr/local/lib/ela/bootstrap/String.ela"
void $14_push_front(String *self, u8 ch)
#line 83 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 84 "/usr/local/lib/ela/bootstrap/String.ela"

#line 84 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((self->capacity == 0))
#line 84 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 84 "/usr/local/lib/ela/bootstrap/String.ela"

#line 84 "/usr/local/lib/ela/bootstrap/String.ela"
    (self->capacity = (256 / 3));
  };

#line 85 "/usr/local/lib/ela/bootstrap/String.ela"

#line 85 "/usr/local/lib/ela/bootstrap/String.ela"
  if (((self->length + 1) >= self->capacity))
#line 85 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 86 "/usr/local/lib/ela/bootstrap/String.ela"

#line 86 "/usr/local/lib/ela/bootstrap/String.ela"
    $14_resize(self, (self->capacity * 3));
  };

#line 88 "/usr/local/lib/ela/bootstrap/String.ela"

#line 88 "/usr/local/lib/ela/bootstrap/String.ela"
  memmove((self->data + 1), self->data, self->length);

#line 89 "/usr/local/lib/ela/bootstrap/String.ela"

#line 89 "/usr/local/lib/ela/bootstrap/String.ela"
  (self->data[0] = ch);

#line 90 "/usr/local/lib/ela/bootstrap/String.ela"

#line 90 "/usr/local/lib/ela/bootstrap/String.ela"
  self->length++;

#line 91 "/usr/local/lib/ela/bootstrap/String.ela"

#line 91 "/usr/local/lib/ela/bootstrap/String.ela"
  (self->data[self->length] = '\0');
};
#line 95 "/usr/local/lib/ela/bootstrap/String.ela"
;
;

#line 105 "/usr/local/lib/ela/bootstrap/String.ela"
str $14_as_str(String self)
#line 105 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 106 "/usr/local/lib/ela/bootstrap/String.ela"

#line 106 "/usr/local/lib/ela/bootstrap/String.ela"
  return (str){.data = (u8 *)self.data, .length = (u64)self.length};
  ;
}
#line 112 "/usr/local/lib/ela/bootstrap/String.ela"
static String $14_empty()
#line 112 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 113 "/usr/local/lib/ela/bootstrap/String.ela"

#line 113 "/usr/local/lib/ela/bootstrap/String.ela"
  return (String){0};
  ;
}
#line 120 "/usr/local/lib/ela/bootstrap/String.ela"
bool $14_eq(String *self, String other)
#line 120 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 121 "/usr/local/lib/ela/bootstrap/String.ela"

#line 121 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((self->length != other.length))
#line 121 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 121 "/usr/local/lib/ela/bootstrap/String.ela"

#line 121 "/usr/local/lib/ela/bootstrap/String.ela"
    return false;
    ;
  };

#line 122 "/usr/local/lib/ela/bootstrap/String.ela"

#line 122 "/usr/local/lib/ela/bootstrap/String.ela"
  {
    Range_Base$1 $_range_id0 = (Range_Base$1){.begin = 0, .end = self->length};
    Range_Enumerator$1 $_loop_id0 = $53_enumerator(&$_range_id0);
    while (!$85_done($_loop_id0)) {
      s32 idx = $85_current($_loop_id0);
      $85_next(&$_loop_id0);

#line 122 "/usr/local/lib/ela/bootstrap/String.ela"
      {

#line 123 "/usr/local/lib/ela/bootstrap/String.ela"

#line 123 "/usr/local/lib/ela/bootstrap/String.ela"
        if (($14_subscript(&(*self), idx) != $14_subscript(&other, idx)))
#line 123 "/usr/local/lib/ela/bootstrap/String.ela"
        {

#line 123 "/usr/local/lib/ela/bootstrap/String.ela"

#line 123 "/usr/local/lib/ela/bootstrap/String.ela"
          return false;
          ;
        };
      }
    }
  };

#line 125 "/usr/local/lib/ela/bootstrap/String.ela"

#line 125 "/usr/local/lib/ela/bootstrap/String.ela"
  return true;
  ;
}
#line 128 "/usr/local/lib/ela/bootstrap/String.ela"
bool $14_starts_with(String *self, u8 *prefix)
#line 128 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 129 "/usr/local/lib/ela/bootstrap/String.ela"

#line 129 "/usr/local/lib/ela/bootstrap/String.ela"
  u32 prefix_len = strlen(prefix);
  ;

#line 130 "/usr/local/lib/ela/bootstrap/String.ela"

#line 130 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((self->length < prefix_len))
#line 130 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 130 "/usr/local/lib/ela/bootstrap/String.ela"

#line 130 "/usr/local/lib/ela/bootstrap/String.ela"
    return false;
    ;
  };

#line 131 "/usr/local/lib/ela/bootstrap/String.ela"

#line 131 "/usr/local/lib/ela/bootstrap/String.ela"
  {
    Range_Base$1 $_range_id0 = (Range_Base$1){.begin = 0, .end = prefix_len};
    Range_Enumerator$1 $_loop_id0 = $53_enumerator(&$_range_id0);
    while (!$85_done($_loop_id0)) {
      s32 i = $85_current($_loop_id0);
      $85_next(&$_loop_id0);

#line 131 "/usr/local/lib/ela/bootstrap/String.ela"
      {

#line 132 "/usr/local/lib/ela/bootstrap/String.ela"

#line 132 "/usr/local/lib/ela/bootstrap/String.ela"
        if ((self->data[i] != prefix[i]))
#line 132 "/usr/local/lib/ela/bootstrap/String.ela"
        {

#line 132 "/usr/local/lib/ela/bootstrap/String.ela"

#line 132 "/usr/local/lib/ela/bootstrap/String.ela"
          return false;
          ;
        };
      }
    }
  };

#line 134 "/usr/local/lib/ela/bootstrap/String.ela"

#line 134 "/usr/local/lib/ela/bootstrap/String.ela"
  return true;
  ;
}
#line 137 "/usr/local/lib/ela/bootstrap/String.ela"
bool $14_ends_with(String *self, u8 *suffix)
#line 137 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 138 "/usr/local/lib/ela/bootstrap/String.ela"

#line 138 "/usr/local/lib/ela/bootstrap/String.ela"
  u32 suffix_len = strlen(suffix);
  ;

#line 139 "/usr/local/lib/ela/bootstrap/String.ela"

#line 139 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((self->length < suffix_len))
#line 139 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 139 "/usr/local/lib/ela/bootstrap/String.ela"

#line 139 "/usr/local/lib/ela/bootstrap/String.ela"
    return false;
    ;
  };

#line 140 "/usr/local/lib/ela/bootstrap/String.ela"

#line 140 "/usr/local/lib/ela/bootstrap/String.ela"
  {
    Range_Base$1 $_range_id0 = (Range_Base$1){.begin = 0, .end = suffix_len};
    Range_Enumerator$1 $_loop_id0 = $53_enumerator(&$_range_id0);
    while (!$85_done($_loop_id0)) {
      s32 i = $85_current($_loop_id0);
      $85_next(&$_loop_id0);

#line 140 "/usr/local/lib/ela/bootstrap/String.ela"
      {

#line 141 "/usr/local/lib/ela/bootstrap/String.ela"

#line 141 "/usr/local/lib/ela/bootstrap/String.ela"
        if ((self->data[((self->length - suffix_len) + i)] != suffix[i]))
#line 141 "/usr/local/lib/ela/bootstrap/String.ela"
        {

#line 141 "/usr/local/lib/ela/bootstrap/String.ela"

#line 141 "/usr/local/lib/ela/bootstrap/String.ela"
          return false;
          ;
        };
      }
    }
  };

#line 143 "/usr/local/lib/ela/bootstrap/String.ela"

#line 143 "/usr/local/lib/ela/bootstrap/String.ela"
  return true;
  ;
}
#line 146 "/usr/local/lib/ela/bootstrap/String.ela"
u8 $14_front(String *self)
#line 146 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 147 "/usr/local/lib/ela/bootstrap/String.ela"

#line 147 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((self->length == 0))
#line 147 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 147 "/usr/local/lib/ela/bootstrap/String.ela"

#line 147 "/usr/local/lib/ela/bootstrap/String.ela"
    return (u8)'\0';
    ;
  };

#line 148 "/usr/local/lib/ela/bootstrap/String.ela"

#line 148 "/usr/local/lib/ela/bootstrap/String.ela"
  return self->data[0];
  ;
}
#line 151 "/usr/local/lib/ela/bootstrap/String.ela"
u8 $14_back(String *self)
#line 151 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 152 "/usr/local/lib/ela/bootstrap/String.ela"

#line 152 "/usr/local/lib/ela/bootstrap/String.ela"
  if ((self->length == 0))
#line 152 "/usr/local/lib/ela/bootstrap/String.ela"
  {

#line 152 "/usr/local/lib/ela/bootstrap/String.ela"

#line 152 "/usr/local/lib/ela/bootstrap/String.ela"
    return (u8)'\0';
    ;
  };

#line 153 "/usr/local/lib/ela/bootstrap/String.ela"

#line 153 "/usr/local/lib/ela/bootstrap/String.ela"
  return self->data[(self->length - 1)];
  ;
};

#line 158 "/usr/local/lib/ela/bootstrap/String.ela"
Iter$7 $14_iter(String *self)
#line 158 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 159 "/usr/local/lib/ela/bootstrap/String.ela"

#line 159 "/usr/local/lib/ela/bootstrap/String.ela"
  return (Iter$7){.ptr = (u8 *)self->data,
                  .end = (u8 *)(self->data + self->length)};
  ;
};

#line 167 "/usr/local/lib/ela/bootstrap/String.ela"
Slice$5 $14_as_char_slice(String self)
#line 167 "/usr/local/lib/ela/bootstrap/String.ela"
{

#line 168 "/usr/local/lib/ela/bootstrap/String.ela"

#line 168 "/usr/local/lib/ela/bootstrap/String.ela"
  return (Slice$5){.data = (u32 *)self.data, .length = (u64)(self.length / 4)};
  ;
};
;

#line 1 "/usr/local/lib/ela/bootstrap/reflection.ela"
typedef struct Element Element;
;

#line 2 "/usr/local/lib/ela/bootstrap/reflection.ela"
typedef struct Type Type;
;

#line 5 "/usr/local/lib/ela/bootstrap/reflection.ela"
;
#line 13 "/usr/local/lib/ela/bootstrap/reflection.ela"
;
#line 23 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 24 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 27 "/usr/local/lib/ela/bootstrap/reflection.ela"
;
#line 32 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 32 "/usr/local/lib/ela/bootstrap/reflection.ela"
typedef struct Element {
  u8 *data;
  Type *type;
} Element;
;
#line 37 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 37 "/usr/local/lib/ela/bootstrap/reflection.ela"
List$38 _type_info = (List$38){};
;
;
;

#line 57 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_signed(Type *self)
#line 57 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 58 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 58 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_SIGNED) != 0);
  ;
}
#line 61 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_unsigned(Type *self)
#line 61 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 62 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 62 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_UNSIGNED) != 0);
  ;
}
#line 70 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_array(Type *self)
#line 70 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 71 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 71 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_ARRAY) != 0);
  ;
}
#line 78 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_scalar(Type *self)
#line 78 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 79 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 79 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ($17_has_no_extension(self) &&
          (((((self->flags & TypeFlags_INTEGER) != 0) ||
             ((self->flags & TypeFlags_FLOAT) != 0)) ||
            ((self->flags & TypeFlags_BOOL) != 0)) ||
           ((self->flags & TypeFlags_STRING) != 0)));
  ;
}
#line 86 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_struct(Type *self)
#line 86 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 87 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 87 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_STRUCT) != 0);
  ;
}
#line 106 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_tuple(Type *self)
#line 106 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 107 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 107 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_TUPLE) != 0);
  ;
}
#line 110 "/usr/local/lib/ela/bootstrap/reflection.ela"
bool $17_is_function(Type *self)
#line 110 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 111 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 111 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return ((self->flags & TypeFlags_FUNCTION) != 0);
  ;
}
#line 118 "/usr/local/lib/ela/bootstrap/reflection.ela"
Field *$17_get_field(Type *self, u8 *name)
#line 118 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 119 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 119 "/usr/local/lib/ela/bootstrap/reflection.ela"
  {
    List$28 $_range_id0 = self->fields;
    Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
    while (!$234_done($_loop_id0)) {
      Field *field = $234_current($_loop_id0);
      $234_next(&$_loop_id0);

#line 119 "/usr/local/lib/ela/bootstrap/reflection.ela"
      {

#line 120 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 120 "/usr/local/lib/ela/bootstrap/reflection.ela"
        if ((strcmp(field->name, name) == 0))
#line 120 "/usr/local/lib/ela/bootstrap/reflection.ela"
        {

#line 121 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 121 "/usr/local/lib/ela/bootstrap/reflection.ela"
          return field;
          ;
        };
      }
    }
  };

#line 124 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 124 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return NULL;
  ;
}
#line 127 "/usr/local/lib/ela/bootstrap/reflection.ela"
u64 $17_offset(Type *self, str member)
#line 127 "/usr/local/lib/ela/bootstrap/reflection.ela"
{

#line 128 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 128 "/usr/local/lib/ela/bootstrap/reflection.ela"
  {
    List$28 $_range_id0 = self->fields;
    Iter$28 $_loop_id0 = $220_iter(&$_range_id0);
    while (!$234_done($_loop_id0)) {
      Field field = *$234_current($_loop_id0);
      $234_next(&$_loop_id0);

#line 128 "/usr/local/lib/ela/bootstrap/reflection.ela"
      {

#line 129 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 129 "/usr/local/lib/ela/bootstrap/reflection.ela"
        if ((strncmp(field.name, member.data, (s32)member.length) == 0))
#line 129 "/usr/local/lib/ela/bootstrap/reflection.ela"
        {

#line 130 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 130 "/usr/local/lib/ela/bootstrap/reflection.ela"
          return field.offset;
          ;
        };
      }
    }
  };

#line 133 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 133 "/usr/local/lib/ela/bootstrap/reflection.ela"
  return (u64)(-1);
  ;
};

#line 138 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 149 "/usr/local/lib/ela/bootstrap/reflection.ela"

#line 159 "/usr/local/lib/ela/bootstrap/reflection.ela"
;

#line 14 "/usr/local/lib/ela/bootstrap/lib.ela"
void assert(str message, bool condition)
#line 14 "/usr/local/lib/ela/bootstrap/lib.ela"
{

#line 15 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 15 "/usr/local/lib/ela/bootstrap/lib.ela"
  if ((!condition))
#line 15 "/usr/local/lib/ela/bootstrap/lib.ela"
  {

#line 16 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 16 "/usr/local/lib/ela/bootstrap/lib.ela"
    printf("assertion failed: %s\n", message.data);

#line 17 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 17 "/usr/local/lib/ela/bootstrap/lib.ela"
    exit(1);
  };
};

#line 21 "/usr/local/lib/ela/bootstrap/lib.ela"
;

#line 28 "/usr/local/lib/ela/bootstrap/lib.ela"
;
;
;

#line 39 "/usr/local/lib/ela/bootstrap/lib.ela"
void set_panic_handler(void (*handler)(str))
#line 39 "/usr/local/lib/ela/bootstrap/lib.ela"
{

#line 40 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 40 "/usr/local/lib/ela/bootstrap/lib.ela"
  (panic_handler = (void (*)(str))handler);
};
;

#line 81 "/usr/local/lib/ela/bootstrap/lib.ela"
;
#line 84 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 89 "/usr/local/lib/ela/bootstrap/lib.ela"
static List$13 $29_args()
#line 89 "/usr/local/lib/ela/bootstrap/lib.ela"
{

#line 90 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 90 "/usr/local/lib/ela/bootstrap/lib.ela"
  return $318_clone($29_current()->m_args);
  ;
}
#line 92 "/usr/local/lib/ela/bootstrap/lib.ela"
static void $29_initialize(s32 argc, str *argv)
#line 92 "/usr/local/lib/ela/bootstrap/lib.ela"
{

#line 93 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 93 "/usr/local/lib/ela/bootstrap/lib.ela"
  Env *self = $29_current();
  ;

#line 94 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 94 "/usr/local/lib/ela/bootstrap/lib.ela"
  {
    Range_Base$1 $_range_id0 = (Range_Base$1){.begin = 0, .end = argc};
    Range_Enumerator$1 $_loop_id0 = $53_enumerator(&$_range_id0);
    while (!$85_done($_loop_id0)) {
      s32 i = $85_current($_loop_id0);
      $85_next(&$_loop_id0);

#line 94 "/usr/local/lib/ela/bootstrap/lib.ela"
      {

#line 95 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 95 "/usr/local/lib/ela/bootstrap/lib.ela"
        $318_push(&self->m_args, argv[i]);
      }
    }
  };
};
;

#line 102 "/usr/local/lib/ela/bootstrap/lib.ela"
Slice$5 $5_as_char_slice(u32 self)
#line 102 "/usr/local/lib/ela/bootstrap/lib.ela"
{

#line 103 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 103 "/usr/local/lib/ela/bootstrap/lib.ela"
  static u32 chars[2] = {'\0', '\0'};

#line 106 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 106 "/usr/local/lib/ela/bootstrap/lib.ela"
  (chars[0] = self);

#line 107 "/usr/local/lib/ela/bootstrap/lib.ela"

#line 107 "/usr/local/lib/ela/bootstrap/lib.ela"
  return (Slice$5){.data = (u32 *)chars, .length = (u64)1};
  ;
};
;
;
;
;
;

#line 107 "/usr/local/lib/ela/format.ela"
;
;

#line 147 "/usr/local/lib/ela/format.ela"
;
#line 151 "/usr/local/lib/ela/format.ela"
;
#line 155 "/usr/local/lib/ela/format.ela"
;
#line 159 "/usr/local/lib/ela/format.ela"
;
#line 163 "/usr/local/lib/ela/format.ela"
;
#line 167 "/usr/local/lib/ela/format.ela"

#line 167 "/usr/local/lib/ela/format.ela"
bool utf8_is_alpha(u32 ch)
#line 167 "/usr/local/lib/ela/format.ela"
{

#line 168 "/usr/local/lib/ela/format.ela"

#line 168 "/usr/local/lib/ela/format.ela"
  return ((((utf8_is_cyrillic_alpha(ch) || utf8_is_chinese_alpha(ch)) ||
            utf8_is_korean_alpha(ch)) ||
           utf8_is_japanese_alpha(ch)) ||
          utf8_is_latin_alpha(ch));
  ;
};
;
;
;
;
;

#line 37 "/usr/local/lib/ela/builder.ela"
void $31_init(String_Builder *self)
#line 37 "/usr/local/lib/ela/builder.ela"
{

#line 38 "/usr/local/lib/ela/builder.ela"

#line 38 "/usr/local/lib/ela/builder.ela"
  (self->root = (String_Builder_Block *)NULL);

#line 39 "/usr/local/lib/ela/builder.ela"

#line 39 "/usr/local/lib/ela/builder.ela"
  (self->current = (String_Builder_Block *)NULL);
}
#line 49 "/usr/local/lib/ela/builder.ela"
void $31_clear(String_Builder *self)
#line 49 "/usr/local/lib/ela/builder.ela"
{

#line 50 "/usr/local/lib/ela/builder.ela"

#line 50 "/usr/local/lib/ela/builder.ela"
  $31_deinit(self);
}
#line 81 "/usr/local/lib/ela/builder.ela"

#line 116 "/usr/local/lib/ela/builder.ela"

#line 121 "/usr/local/lib/ela/builder.ela"

#line 142 "/usr/local/lib/ela/builder.ela"
;

#line 181 "/usr/local/lib/ela/format.ela"
;
;

#line 284 "/usr/local/lib/ela/format.ela"
;

#line 290 "/usr/local/lib/ela/format.ela"
;

#line 297 "/usr/local/lib/ela/format.ela"
static void printlnf(str fmt, Init_List$18 list)
#line 297 "/usr/local/lib/ela/format.ela"
{

#line 298 "/usr/local/lib/ela/format.ela"

#line 298 "/usr/local/lib/ela/format.ela"
  String formatted = format(fmt, list);
  ;

#line 299 "/usr/local/lib/ela/format.ela"

#line 299 "/usr/local/lib/ela/format.ela"
  printf("%s\n", formatted.data);

#line 300 "/usr/local/lib/ela/format.ela"

#line 300 "/usr/local/lib/ela/format.ela"
  $14_deinit(&formatted);
};
;

#line 312 "/usr/local/lib/ela/format.ela"
u32 $32_current(UTF8_Enumerator self)
#line 312 "/usr/local/lib/ela/format.ela"
{

#line 313 "/usr/local/lib/ela/format.ela"

#line 313 "/usr/local/lib/ela/format.ela"
  return self.current_char;
  ;
}
#line 315 "/usr/local/lib/ela/format.ela"
void $32_next(UTF8_Enumerator *self)
#line 315 "/usr/local/lib/ela/format.ela"
{

#line 316 "/usr/local/lib/ela/format.ela"

#line 316 "/usr/local/lib/ela/format.ela"
  Slice$7 subslice =
      $172_slice(self->slice, (Range_Base$1){.begin = (s32)self->position,
                                             .end = (s32)(self->position + 4)});
  ;

#line 317 "/usr/local/lib/ela/format.ela"

#line 317 "/usr/local/lib/ela/format.ela"
  auto $temp_tuple$0 = utf8_to_code_point(subslice);

#line 317 "/usr/local/lib/ela/format.ela"
  auto ch = $temp_tuple$0.$0;
  auto advance = $temp_tuple$0.$1;

#line 317 "/usr/local/lib/ela/format.ela"

#line 317 "/usr/local/lib/ela/format.ela"
  ;

#line 318 "/usr/local/lib/ela/format.ela"

#line 318 "/usr/local/lib/ela/format.ela"
  (self->position += advance);

#line 319 "/usr/local/lib/ela/format.ela"

#line 319 "/usr/local/lib/ela/format.ela"
  (self->current_char = ch);
}
#line 321 "/usr/local/lib/ela/format.ela"
bool $32_done(UTF8_Enumerator self)
#line 321 "/usr/local/lib/ela/format.ela"
{

#line 322 "/usr/local/lib/ela/format.ela"

#line 322 "/usr/local/lib/ela/format.ela"
  return (self.position >= self.slice.length);
  ;
};

#line 327 "/usr/local/lib/ela/format.ela"
UTF8_Enumerator $14_chars(String self)
#line 327 "/usr/local/lib/ela/format.ela"
{

#line 328 "/usr/local/lib/ela/format.ela"

#line 328 "/usr/local/lib/ela/format.ela"
  return (UTF8_Enumerator){.slice = (Slice$7)$14_as_byte_slice(self),
                           .position = (u32)0,
                           .current_char = (u32)'\0'};
  ;
};

#line 337 "/usr/local/lib/ela/format.ela"
void $31_append_utf8(String_Builder *self, u32 ch)
#line 337 "/usr/local/lib/ela/format.ela"
{

#line 338 "/usr/local/lib/ela/format.ela"

#line 338 "/usr/local/lib/ela/format.ela"
  List$7 bytes = utf8_encode(ch);
  ;

#line 339 "/usr/local/lib/ela/format.ela"

#line 339 "/usr/local/lib/ela/format.ela"
  {
    List$7 $_range_id0 = bytes;
    Iter$7 $_loop_id0 = $356_iter(&$_range_id0);
    while (!$177_done($_loop_id0)) {
      u8 byte = *$177_current($_loop_id0);
      $177_next(&$_loop_id0);

#line 339 "/usr/local/lib/ela/format.ela"
      {

#line 340 "/usr/local/lib/ela/format.ela"

#line 340 "/usr/local/lib/ela/format.ela"
        $31_append_byte(self, byte);
      }
    }
  };
};
;
;
;
;
;
;
;

#line 96 "/home/josh_arch/source/ela/gl-test/test.ela"
void __ela_main_()
#line 96 "/home/josh_arch/source/ela/gl-test/test.ela"
{

#line 98 "/home/josh_arch/source/ela/gl-test/test.ela"

#line 98 "/home/josh_arch/source/ela/gl-test/test.ela"
  List$35 cubular = cube(1.0f);
  ;

#line 100 "/home/josh_arch/source/ela/gl-test/test.ela"

#line 100 "/home/josh_arch/source/ela/gl-test/test.ela"
  {
    List$35 $_range_id0 = cubular;
    Iter$35 $_loop_id0 = $432_iter(&$_range_id0);
    while (!$446_done($_loop_id0)) {
      Vertex vert = *$446_current($_loop_id0);
      $446_next(&$_loop_id0);

#line 100 "/home/josh_arch/source/ela/gl-test/test.ela"
      {

#line 101 "/home/josh_arch/source/ela/gl-test/test.ela"

#line 101 "/home/josh_arch/source/ela/gl-test/test.ela"
        String formatted = format(
            (str){.data = "pos: % % %, normal: % % %, texcoord: % %",
                  .length = 40},
            (Init_List$18){.data = (any[]){$18_new$9((&vert.position.x)),
                                           $18_new$9((&vert.position.y)),
                                           $18_new$9((&vert.position.z)),
                                           $18_new$9((&vert.normal.x)),
                                           $18_new$9((&vert.normal.y)),
                                           $18_new$9((&vert.normal.z)),
                                           $18_new$9((&vert.texcoord.x)),
                                           $18_new$9((&vert.texcoord.y))},
                           .length = 8});
        ;

#line 113 "/home/josh_arch/source/ela/gl-test/test.ela"

#line 113 "/home/josh_arch/source/ela/gl-test/test.ela"
        println$14(formatted);

#line 114 "/home/josh_arch/source/ela/gl-test/test.ela"

#line 114 "/home/josh_arch/source/ela/gl-test/test.ela"
        $14_deinit(&formatted);
      }
    }
  };
};
#line 0 "boilerplate.h"
void $initialize_reflection_system() {
  _type_info.length = _type_info.capacity = 16;
  _type_info.data = realloc(_type_info.data, sizeof(Type *) * 470);
  _type_info.data[11] = malloc(sizeof(Type));
  *_type_info.data[11] = (Type){
      .id = 11,
      .name = "void",
      .size = sizeof(void),
      .flags = 0,
      .element_type = NULL,
  };
  ;
  _type_info.data[37] = malloc(sizeof(Type));
  *_type_info.data[37] = (Type){
      .id = 37,
      .name = "void*",
      .size = sizeof(void *),
      .flags = 1024,
      .element_type = _type_info.data[11],
  };
  ;
  _type_info.data[7] = malloc(sizeof(Type));
  *_type_info.data[7] = (Type){
      .id = 7,
      .name = "u8",
      .size = sizeof(u8),
      .flags = 4097,
      .element_type = NULL,
  };
  ;
  _type_info.data[1] = malloc(sizeof(Type));
  *_type_info.data[1] = (Type){
      .id = 1,
      .name = "s32",
      .size = sizeof(s32),
      .flags = 2049,
      .element_type = NULL,
  };
  ;
  _type_info.data[6] = malloc(sizeof(Type));
  *_type_info.data[6] = (Type){
      .id = 6,
      .name = "u16",
      .size = sizeof(u16),
      .flags = 4097,
      .element_type = NULL,
  };
  ;
  _type_info.data[5] = malloc(sizeof(Type));
  *_type_info.data[5] = (Type){
      .id = 5,
      .name = "u32",
      .size = sizeof(u32),
      .flags = 4097,
      .element_type = NULL,
  };
  ;
  _type_info.data[4] = malloc(sizeof(Type));
  *_type_info.data[4] = (Type){
      .id = 4,
      .name = "u64",
      .size = sizeof(u64),
      .flags = 4097,
      .element_type = NULL,
  };
  ;
  _type_info.data[3] = malloc(sizeof(Type));
  *_type_info.data[3] = (Type){
      .id = 3,
      .name = "s8",
      .size = sizeof(s8),
      .flags = 2049,
      .element_type = NULL,
  };
  ;
  _type_info.data[2] = malloc(sizeof(Type));
  *_type_info.data[2] = (Type){
      .id = 2,
      .name = "s16",
      .size = sizeof(s16),
      .flags = 2049,
      .element_type = NULL,
  };
  ;
  _type_info.data[0] = malloc(sizeof(Type));
  *_type_info.data[0] = (Type){
      .id = 0,
      .name = "s64",
      .size = sizeof(s64),
      .flags = 2049,
      .element_type = NULL,
  };
  ;
  _type_info.data[9] = malloc(sizeof(Type));
  *_type_info.data[9] = (Type){
      .id = 9,
      .name = "f32",
      .size = sizeof(f32),
      .flags = 2,
      .element_type = NULL,
  };
  ;
  _type_info.data[8] = malloc(sizeof(Type));
  *_type_info.data[8] = (Type){
      .id = 8,
      .name = "f64",
      .size = sizeof(f64),
      .flags = 2,
      .element_type = NULL,
  };
  ;
  _type_info.data[10] = malloc(sizeof(Type));
  *_type_info.data[10] = (Type){
      .id = 10,
      .name = "bool",
      .size = sizeof(bool),
      .flags = 4,
      .element_type = NULL,
  };
  ;
  _type_info.data[36] = malloc(sizeof(Type));
  *_type_info.data[36] = (Type){
      .id = 36,
      .name = "u8*",
      .size = sizeof(u8 *),
      .flags = 8,
      .element_type = _type_info.data[7],
  };
  ;
  _type_info.data[14] = malloc(sizeof(Type));
  *_type_info.data[14] = (Type){
      .id = 14,
      .name = "String",
      .size = sizeof(String),
      .flags = 16,
      .element_type = NULL,
  };
  _type_info.data[14]->fields.data = malloc(3 * sizeof(Field));
  _type_info.data[14]->fields.length = 3;
  _type_info.data[14]->fields.capacity = 3;
  _type_info.data[14]->fields.data[0] =
      (Field){.name = "data",
              .type = _type_info.data[36],
              .size = sizeof(u8 *),
              .offset = offsetof(String, data)};
  _type_info.data[14]->fields.data[1] =
      (Field){.name = "length",
              .type = _type_info.data[4],
              .size = sizeof(u64),
              .offset = offsetof(String, length)};
  _type_info.data[14]->fields.data[2] =
      (Field){.name = "capacity",
              .type = _type_info.data[4],
              .size = sizeof(u64),
              .offset = offsetof(String, capacity)};
  ;
  _type_info.data[13] = malloc(sizeof(Type));
  *_type_info.data[13] = (Type){
      .id = 13,
      .name = "str",
      .size = sizeof(str),
      .flags = 16,
      .element_type = NULL,
  };
  _type_info.data[13]->fields.data = malloc(2 * sizeof(Field));
  _type_info.data[13]->fields.length = 2;
  _type_info.data[13]->fields.capacity = 2;
  _type_info.data[13]->fields.data[0] = (Field){.name = "data",
                                                .type = _type_info.data[36],
                                                .size = sizeof(u8 *),
                                                .offset = offsetof(str, data)};
  _type_info.data[13]->fields.data[1] =
      (Field){.name = "length",
              .type = _type_info.data[4],
              .size = sizeof(u64),
              .offset = offsetof(str, length)};
  ;
  ;
}
#line 0 "boilerplate.h"
#line 0 "boilerplate.h"
int main(int argc, char **argv) {
  $29_initialize(argc, argv);
  $initialize_reflection_system();
  __ela_main_();
}
