
typedef unsigned long long int u64;
typedef signed long long int s64;

typedef signed int s32;
typedef unsigned int u32;

typedef double f64;
typedef float f32;

typedef short int s16;
typedef unsigned short int u16;

/* 
  TODO: replace the 'signed' attribute on s8.
  * We did this because we can't use main() in 
  * freestanding with a signed char, because of 
  * command line args, and C restrictions.
*/
typedef char s8;
typedef unsigned char u8;

/* static initializers. */
void ela_run_global_initializers();

#include <stddef.h>
#include <stdarg.h>

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
extern const Type refl_ty$11;
extern const Type refl_ty$14;
extern const Type refl_ty$13;
extern const Type refl_ty$36;
extern const Type refl_ty$68;
extern const Type refl_ty$70;
extern const Type refl_ty$62;
extern const Type refl_ty$831;
extern const Type refl_ty$7;
extern const Type refl_ty$6;
extern const Type refl_ty$215;
extern const Type refl_ty$5;
extern const Type refl_ty$4;
extern const Type refl_ty$3;
extern const Type refl_ty$2;
extern const Type refl_ty$1;
extern const Type refl_ty$0;
extern const Type refl_ty$69;
extern const Type refl_ty$9;
extern const Type refl_ty$8;
extern const Type refl_ty$34;
extern const Type refl_ty$24;
extern const Type refl_ty$35;
extern const Type refl_ty$21;
extern const Type refl_ty$181;
extern const Type refl_ty$51;
extern const Type refl_ty$61;
extern const Type refl_ty$193;
extern const Type refl_ty$435;
extern const Type refl_ty$67;
extern const Type refl_ty$33;
extern const Type refl_ty$12;
extern const Type refl_ty$29;
extern const Type refl_ty$410;
extern const Type refl_ty$32;
extern const Type refl_ty$10;
extern const Type refl_ty$15;
extern const Type refl_ty$402;
extern const Type refl_ty$2025;
extern const Type refl_ty$2030;
extern const Type refl_ty$852;
extern const Type refl_ty$890;
extern const Type refl_ty$898;
extern const Type refl_ty$1866;
extern const Type refl_ty$903;
extern const Type refl_ty$886;
extern const Type refl_ty$1707;
#define USE_STD_LIB 1
typedef struct str str;
typedef struct Slice$32 {
  str* data;
  u64 length;
} Slice$32;
typedef struct Env {
  Slice$32 args_slice;
} Env;
typedef struct Env Env;
Env* Env$current() {
  static Env self  = (Env){.args_slice = (Slice$32){},};
  return (&self);
}
typedef struct str {
  u8* data;
  u64 length;
} str;
extern void*  malloc(u64);
typedef struct RangeIter$1 {
  s32 begin;
  s32 end;
  s32 idx;
} RangeIter$1;
typedef struct RangeBase$1 {
  s32 begin;
  s32 end;
} RangeBase$1;
typedef struct RangeBase$1 RangeBase$1;
RangeIter$1 RangeBase$1$iter(RangeBase$1* self) {
  return (RangeIter$1)(RangeIter$1){
    .begin = (s32)self->begin,
    .end = (s32)self->end,
    .idx = (s32)self->begin,};
}
typedef struct $tuple1 {
  s32 $0;
} $tuple1;
typedef struct Option$1 Option$1;
typedef $tuple1 Option$1$Some;
typedef struct Option$1 {
  int index;
  union {
    Option$1$Some Some;
  };
} Option$1;
typedef struct RangeIter$1 RangeIter$1;
static inline Option$1 Some$1(s32 t) {
  return (Option$1) {
.index = 2,
.Some = ($tuple1) {.$0 = t}};
}
Option$1 RangeIter$1$next(RangeIter$1* self) {
  
  if ((self->idx == self->end)) {
    return  (Option$1) { .index = 1};
  }
;
  Option$1 value  = Some$1(self->idx);
  
  if ((self->begin > self->end)) {
    self->idx--;
  }
  else{
    self->idx++;
  }
;
  return value;
}
u32 Env$env_strlen(u8* s) {
  s32 i  = 0;
  while ((*s)) {
    i++;
    s++;
  }
  return i;
}
void Env$initialize(s32 argc, u8** argv) {
  Env* self  = Env$current();
str* data  = malloc((argc * sizeof(str)));
  {
    RangeBase$1 $iterable = (RangeBase$1) {.begin = 0, .end = argc};
    RangeIter$1 $iterator = RangeBase$1$iter(&$iterable);


    for (auto $next = RangeIter$1$next(&$iterator);
$next.index != 1; $next = RangeIter$1$next(&$iterator)) {
    s32 i = $next.Some.$0;
    {
      (data[i] = (str)(str){
        .data = (u8*)argv[i],
        .length = (u64)Env$env_strlen(argv[i]),});
    }
  }
}
(self->args_slice = (Slice$32)(Slice$32){
  .data = (str*)data,
  .length = (u64)argc,});
}
typedef struct gl$GLFWwindow gl$GLFWwindow;
typedef struct gl$Window {
  gl$GLFWwindow* handle;
} gl$Window;
extern s32  glfwInit();
extern s32  vprintf(u8*, va_list);
static inline s32 std$printf(str format, ...) {
  va_list list  = (va_list){};
  va_start(list);
  s32 result  = vprintf(format.data,list);
  va_end(list);
  return result;
}
typedef struct gl$GLFWmonitor gl$GLFWmonitor;
extern gl$GLFWwindow*  glfwCreateWindow(s32, s32, u8*, gl$GLFWmonitor*, gl$GLFWwindow*);
extern void  glfwTerminate();
extern void  glfwMakeContextCurrent(gl$GLFWwindow*);
extern bool  glewInit();
gl$Window gl$Window$create(s32 width, s32 height, str title) {
  gl$Window self  = (gl$Window){};
  
  if ((!glfwInit())) {
    std$printf((str) { .data = "Failed to initialize glfw\n", .length = 26 });
    return self;
  }
;
  (self.handle = glfwCreateWindow(width,height,title.data,NULL,NULL));
  
  if ((self.handle == NULL)) {
    std$printf((str) { .data = "Failed to create window\n", .length = 24 });
    glfwTerminate();
    return self;
  }
;
  glfwMakeContextCurrent(self.handle);
  
  if ((glewInit() != 0)) {
    std$printf((str) { .data = "Failed to initialize glew\n", .length = 26 });
    glfwTerminate();
    return self;
  }
;
  return self;
}
typedef enum: u32 {
  gl$GL$STATIC_DRAW = 35044,
  gl$GL$ARRAY_BUFFER = 34962,
  gl$GL$INFO_LOG_LENGTH = 35716,
  gl$GL$COMPILE_STATUS = 35713,
  gl$GL$LINK_STATUS = 35714,
  gl$GL$VERTEX_SHADER = 35633,
  gl$GL$FRAGMENT_SHADER = 35632,
  gl$GL$ZERO = 0,
  gl$GL$FALSE = 0,
  gl$GL$LOGIC_OP = 0x0BF1,
  gl$GL$NONE = 0,
  gl$GL$TEXTURE_COMPONENTS = 0x1003,
  gl$GL$NO_ERROR = 0,
  gl$GL$POINTS = 0x0000,
  gl$GL$CURRENT_BIT = 0x00000001,
  gl$GL$TRUE = 1,
  gl$GL$ONE = 1,
  gl$GL$CLIENT_PIXEL_STORE_BIT = 0x00000001,
  gl$GL$LINES = 0x0001,
  gl$GL$LINE_LOOP = 0x0002,
  gl$GL$POINT_BIT = 0x00000002,
  gl$GL$CLIENT_VERTEX_ARRAY_BIT = 0x00000002,
  gl$GL$LINE_STRIP = 0x0003,
  gl$GL$LINE_BIT = 0x00000004,
  gl$GL$TRIANGLES = 0x0004,
  gl$GL$TRIANGLE_STRIP = 0x0005,
  gl$GL$TRIANGLE_FAN = 0x0006,
  gl$GL$QUADS = 0x0007,
  gl$GL$QUAD_STRIP = 0x0008,
  gl$GL$POLYGON_BIT = 0x00000008,
  gl$GL$POLYGON = 0x0009,
  gl$GL$POLYGON_STIPPLE_BIT = 0x00000010,
  gl$GL$PIXEL_MODE_BIT = 0x00000020,
  gl$GL$LIGHTING_BIT = 0x00000040,
  gl$GL$FOG_BIT = 0x00000080,
  gl$GL$DEPTH_BUFFER_BIT = 0x00000100,
  gl$GL$ACCUM = 0x0100,
  gl$GL$LOAD = 0x0101,
  gl$GL$RETURN = 0x0102,
  gl$GL$GL_MULT = 0x0103,
  gl$GL$GL_ADD = 0x0104,
  gl$GL$NEVER = 0x0200,
  gl$GL$ACCUM_BUFFER_BIT = 0x00000200,
  gl$GL$GL_LESS = 0x0201,
  gl$GL$GL_EQUAL = 0x0202,
  gl$GL$GL_LEQUAL = 0x0203,
  gl$GL$GL_GREATER = 0x0204,
  gl$GL$GL_NOTEQUAL = 0x0205,
  gl$GL$GEQUAL = 0x0206,
  gl$GL$ALWAYS = 0x0207,
  gl$GL$SRC_COLOR = 0x0300,
  gl$GL$ONE_MINUS_SRC_COLOR = 0x0301,
  gl$GL$SRC_ALPHA = 0x0302,
  gl$GL$ONE_MINUS_SRC_ALPHA = 0x0303,
  gl$GL$DST_ALPHA = 0x0304,
  gl$GL$ONE_MINUS_DST_ALPHA = 0x0305,
  gl$GL$DST_COLOR = 0x0306,
  gl$GL$ONE_MINUS_DST_COLOR = 0x0307,
  gl$GL$SRC_ALPHA_SATURATE = 0x0308,
  gl$GL$STENCIL_BUFFER_BIT = 0x00000400,
  gl$GL$FRONT_LEFT = 0x0400,
  gl$GL$FRONT_RIGHT = 0x0401,
  gl$GL$BACK_LEFT = 0x0402,
  gl$GL$BACK_RIGHT = 0x0403,
  gl$GL$FRONT = 0x0404,
  gl$GL$BACK = 0x0405,
  gl$GL$LEFT = 0x0406,
  gl$GL$RIGHT = 0x0407,
  gl$GL$FRONT_AND_BACK = 0x0408,
  gl$GL$AUX0 = 0x0409,
  gl$GL$AUX1 = 0x040A,
  gl$GL$AUX2 = 0x040B,
  gl$GL$AUX3 = 0x040C,
  gl$GL$INVALID_ENUM = 0x0500,
  gl$GL$INVALID_VALUE = 0x0501,
  gl$GL$INVALID_OPERATION = 0x0502,
  gl$GL$STACK_OVERFLOW = 0x0503,
  gl$GL$STACK_UNDERFLOW = 0x0504,
  gl$GL$OUT_OF_MEMORY = 0x0505,
  gl$GL$_2D = 0x0600,
  gl$GL$_3D = 0x0601,
  gl$GL$_3D_COLOR = 0x0602,
  gl$GL$_3D_COLOR_TEXTURE = 0x0603,
  gl$GL$_4D_COLOR_TEXTURE = 0x0604,
  gl$GL$PASS_THROUGH_TOKEN = 0x0700,
  gl$GL$POINT_TOKEN = 0x0701,
  gl$GL$LINE_TOKEN = 0x0702,
  gl$GL$POLYGON_TOKEN = 0x0703,
  gl$GL$BITMAP_TOKEN = 0x0704,
  gl$GL$DRAW_PIXEL_TOKEN = 0x0705,
  gl$GL$COPY_PIXEL_TOKEN = 0x0706,
  gl$GL$LINE_RESET_TOKEN = 0x0707,
  gl$GL$EXP = 0x0800,
  gl$GL$VIEWPORT_BIT = 0x00000800,
  gl$GL$EXP2 = 0x0801,
  gl$GL$CW = 0x0900,
  gl$GL$CCW = 0x0901,
  gl$GL$COEFF = 0x0A00,
  gl$GL$ORDER = 0x0A01,
  gl$GL$DOMAIN = 0x0A02,
  gl$GL$CURRENT_COLOR = 0x0B00,
  gl$GL$CURRENT_INDEX = 0x0B01,
  gl$GL$CURRENT_NORMAL = 0x0B02,
  gl$GL$CURRENT_TEXTURE_COORDS = 0x0B03,
  gl$GL$CURRENT_RASTER_COLOR = 0x0B04,
  gl$GL$CURRENT_RASTER_INDEX = 0x0B05,
  gl$GL$CURRENT_RASTER_TEXTURE_COORDS = 0x0B06,
  gl$GL$CURRENT_RASTER_POSITION = 0x0B07,
  gl$GL$CURRENT_RASTER_POSITION_VALID = 0x0B08,
  gl$GL$CURRENT_RASTER_DISTANCE = 0x0B09,
  gl$GL$POINT_SMOOTH = 0x0B10,
  gl$GL$POINT_SIZE = 0x0B11,
  gl$GL$POINT_SIZE_RANGE = 0x0B12,
  gl$GL$POINT_SIZE_GRANULARITY = 0x0B13,
  gl$GL$LINE_SMOOTH = 0x0B20,
  gl$GL$LINE_WIDTH = 0x0B21,
  gl$GL$LINE_WIDTH_RANGE = 0x0B22,
  gl$GL$LINE_WIDTH_GRANULARITY = 0x0B23,
  gl$GL$LINE_STIPPLE = 0x0B24,
  gl$GL$LINE_STIPPLE_PATTERN = 0x0B25,
  gl$GL$LINE_STIPPLE_REPEAT = 0x0B26,
  gl$GL$LIST_MODE = 0x0B30,
  gl$GL$MAX_LIST_NESTING = 0x0B31,
  gl$GL$LIST_BASE = 0x0B32,
  gl$GL$LIST_INDEX = 0x0B33,
  gl$GL$POLYGON_MODE = 0x0B40,
  gl$GL$POLYGON_SMOOTH = 0x0B41,
  gl$GL$POLYGON_STIPPLE = 0x0B42,
  gl$GL$EDGE_FLAG = 0x0B43,
  gl$GL$CULL_FACE = 0x0B44,
  gl$GL$CULL_FACE_MODE = 0x0B45,
  gl$GL$FRONT_FACE = 0x0B46,
  gl$GL$LIGHTING = 0x0B50,
  gl$GL$LIGHT_MODEL_LOCAL_VIEWER = 0x0B51,
  gl$GL$LIGHT_MODEL_TWO_SIDE = 0x0B52,
  gl$GL$LIGHT_MODEL_AMBIENT = 0x0B53,
  gl$GL$SHADE_MODEL = 0x0B54,
  gl$GL$COLOR_MATERIAL_FACE = 0x0B55,
  gl$GL$COLOR_MATERIAL_PARAMETER = 0x0B56,
  gl$GL$COLOR_MATERIAL = 0x0B57,
  gl$GL$FOG = 0x0B60,
  gl$GL$FOG_INDEX = 0x0B61,
  gl$GL$FOG_DENSITY = 0x0B62,
  gl$GL$FOG_START = 0x0B63,
  gl$GL$FOG_END = 0x0B64,
  gl$GL$FOG_MODE = 0x0B65,
  gl$GL$FOG_COLOR = 0x0B66,
  gl$GL$DEPTH_RANGE = 0x0B70,
  gl$GL$DEPTH_TEST = 0x0B71,
  gl$GL$DEPTH_WRITEMASK = 0x0B72,
  gl$GL$DEPTH_CLEAR_VALUE = 0x0B73,
  gl$GL$DEPTH_FUNC = 0x0B74,
  gl$GL$ACCUM_CLEAR_VALUE = 0x0B80,
  gl$GL$STENCIL_TEST = 0x0B90,
  gl$GL$STENCIL_CLEAR_VALUE = 0x0B91,
  gl$GL$STENCIL_FUNC = 0x0B92,
  gl$GL$STENCIL_VALUE_MASK = 0x0B93,
  gl$GL$STENCIL_FAIL = 0x0B94,
  gl$GL$STENCIL_PASS_DEPTH_FAIL = 0x0B95,
  gl$GL$STENCIL_PASS_DEPTH_PASS = 0x0B96,
  gl$GL$STENCIL_REF = 0x0B97,
  gl$GL$STENCIL_WRITEMASK = 0x0B98,
  gl$GL$MATRIX_MODE = 0x0BA0,
  gl$GL$NORMALIZE = 0x0BA1,
  gl$GL$VIEWPORT = 0x0BA2,
  gl$GL$MODELVIEW_STACK_DEPTH = 0x0BA3,
  gl$GL$PROJECTION_STACK_DEPTH = 0x0BA4,
  gl$GL$TEXTURE_STACK_DEPTH = 0x0BA5,
  gl$GL$MODELVIEW_MATRIX = 0x0BA6,
  gl$GL$PROJECTION_MATRIX = 0x0BA7,
  gl$GL$TEXTURE_MATRIX = 0x0BA8,
  gl$GL$ATTRIB_STACK_DEPTH = 0x0BB0,
  gl$GL$CLIENT_ATTRIB_STACK_DEPTH = 0x0BB1,
  gl$GL$ALPHA_TEST = 0x0BC0,
  gl$GL$ALPHA_TEST_FUNC = 0x0BC1,
  gl$GL$ALPHA_TEST_REF = 0x0BC2,
  gl$GL$DITHER = 0x0BD0,
  gl$GL$BLEND_DST = 0x0BE0,
  gl$GL$BLEND_SRC = 0x0BE1,
  gl$GL$BLEND = 0x0BE2,
  gl$GL$LOGIC_OP_MODE = 0x0BF0,
  gl$GL$INDEX_LOGIC_OP = 0x0BF1,
  gl$GL$COLOR_LOGIC_OP = 0x0BF2,
  gl$GL$AUX_BUFFERS = 0x0C00,
  gl$GL$DRAW_BUFFER = 0x0C01,
  gl$GL$READ_BUFFER = 0x0C02,
  gl$GL$SCISSOR_BOX = 0x0C10,
  gl$GL$SCISSOR_TEST = 0x0C11,
  gl$GL$INDEX_CLEAR_VALUE = 0x0C20,
  gl$GL$INDEX_WRITEMASK = 0x0C21,
  gl$GL$COLOR_CLEAR_VALUE = 0x0C22,
  gl$GL$COLOR_WRITEMASK = 0x0C23,
  gl$GL$INDEX_MODE = 0x0C30,
  gl$GL$RGBA_MODE = 0x0C31,
  gl$GL$DOUBLEBUFFER = 0x0C32,
  gl$GL$STEREO = 0x0C33,
  gl$GL$RENDER_MODE = 0x0C40,
  gl$GL$PERSPECTIVE_CORRECTION_HINT = 0x0C50,
  gl$GL$POINT_SMOOTH_HINT = 0x0C51,
  gl$GL$LINE_SMOOTH_HINT = 0x0C52,
  gl$GL$POLYGON_SMOOTH_HINT = 0x0C53,
  gl$GL$FOG_HINT = 0x0C54,
  gl$GL$TEXTURE_GEN_S = 0x0C60,
  gl$GL$TEXTURE_GEN_T = 0x0C61,
  gl$GL$TEXTURE_GEN_R = 0x0C62,
  gl$GL$TEXTURE_GEN_Q = 0x0C63,
  gl$GL$PIXEL_MAP_I_TO_I = 0x0C70,
  gl$GL$PIXEL_MAP_S_TO_S = 0x0C71,
  gl$GL$PIXEL_MAP_I_TO_R = 0x0C72,
  gl$GL$PIXEL_MAP_I_TO_G = 0x0C73,
  gl$GL$PIXEL_MAP_I_TO_B = 0x0C74,
  gl$GL$PIXEL_MAP_I_TO_A = 0x0C75,
  gl$GL$PIXEL_MAP_R_TO_R = 0x0C76,
  gl$GL$PIXEL_MAP_G_TO_G = 0x0C77,
  gl$GL$PIXEL_MAP_B_TO_B = 0x0C78,
  gl$GL$PIXEL_MAP_A_TO_A = 0x0C79,
  gl$GL$PIXEL_MAP_I_TO_I_SIZE = 0x0CB0,
  gl$GL$PIXEL_MAP_S_TO_S_SIZE = 0x0CB1,
  gl$GL$PIXEL_MAP_I_TO_R_SIZE = 0x0CB2,
  gl$GL$PIXEL_MAP_I_TO_G_SIZE = 0x0CB3,
  gl$GL$PIXEL_MAP_I_TO_B_SIZE = 0x0CB4,
  gl$GL$PIXEL_MAP_I_TO_A_SIZE = 0x0CB5,
  gl$GL$PIXEL_MAP_R_TO_R_SIZE = 0x0CB6,
  gl$GL$PIXEL_MAP_G_TO_G_SIZE = 0x0CB7,
  gl$GL$PIXEL_MAP_B_TO_B_SIZE = 0x0CB8,
  gl$GL$PIXEL_MAP_A_TO_A_SIZE = 0x0CB9,
  gl$GL$UNPACK_SWAP_BYTES = 0x0CF0,
  gl$GL$UNPACK_LSB_FIRST = 0x0CF1,
  gl$GL$UNPACK_ROW_LENGTH = 0x0CF2,
  gl$GL$UNPACK_SKIP_ROWS = 0x0CF3,
  gl$GL$UNPACK_SKIP_PIXELS = 0x0CF4,
  gl$GL$UNPACK_ALIGNMENT = 0x0CF5,
  gl$GL$PACK_SWAP_BYTES = 0x0D00,
  gl$GL$PACK_LSB_FIRST = 0x0D01,
  gl$GL$PACK_ROW_LENGTH = 0x0D02,
  gl$GL$PACK_SKIP_ROWS = 0x0D03,
  gl$GL$PACK_SKIP_PIXELS = 0x0D04,
  gl$GL$PACK_ALIGNMENT = 0x0D05,
  gl$GL$MAP_COLOR = 0x0D10,
  gl$GL$MAP_STENCIL = 0x0D11,
  gl$GL$INDEX_SHIFT = 0x0D12,
  gl$GL$INDEX_OFFSET = 0x0D13,
  gl$GL$RED_SCALE = 0x0D14,
  gl$GL$RED_BIAS = 0x0D15,
  gl$GL$ZOOM_X = 0x0D16,
  gl$GL$ZOOM_Y = 0x0D17,
  gl$GL$GREEN_SCALE = 0x0D18,
  gl$GL$GREEN_BIAS = 0x0D19,
  gl$GL$BLUE_SCALE = 0x0D1A,
  gl$GL$BLUE_BIAS = 0x0D1B,
  gl$GL$ALPHA_SCALE = 0x0D1C,
  gl$GL$ALPHA_BIAS = 0x0D1D,
  gl$GL$DEPTH_SCALE = 0x0D1E,
  gl$GL$DEPTH_BIAS = 0x0D1F,
  gl$GL$MAX_EVAL_ORDER = 0x0D30,
  gl$GL$MAX_LIGHTS = 0x0D31,
  gl$GL$MAX_CLIP_PLANES = 0x0D32,
  gl$GL$MAX_TEXTURE_SIZE = 0x0D33,
  gl$GL$MAX_PIXEL_MAP_TABLE = 0x0D34,
  gl$GL$MAX_ATTRIB_STACK_DEPTH = 0x0D35,
  gl$GL$MAX_MODELVIEW_STACK_DEPTH = 0x0D36,
  gl$GL$MAX_NAME_STACK_DEPTH = 0x0D37,
  gl$GL$MAX_PROJECTION_STACK_DEPTH = 0x0D38,
  gl$GL$MAX_TEXTURE_STACK_DEPTH = 0x0D39,
  gl$GL$MAX_VIEWPORT_DIMS = 0x0D3A,
  gl$GL$MAX_CLIENT_ATTRIB_STACK_DEPTH = 0x0D3B,
  gl$GL$SUBPIXEL_BITS = 0x0D50,
  gl$GL$INDEX_BITS = 0x0D51,
  gl$GL$RED_BITS = 0x0D52,
  gl$GL$GREEN_BITS = 0x0D53,
  gl$GL$BLUE_BITS = 0x0D54,
  gl$GL$ALPHA_BITS = 0x0D55,
  gl$GL$DEPTH_BITS = 0x0D56,
  gl$GL$STENCIL_BITS = 0x0D57,
  gl$GL$ACCUM_RED_BITS = 0x0D58,
  gl$GL$ACCUM_GREEN_BITS = 0x0D59,
  gl$GL$ACCUM_BLUE_BITS = 0x0D5A,
  gl$GL$ACCUM_ALPHA_BITS = 0x0D5B,
  gl$GL$NAME_STACK_DEPTH = 0x0D70,
  gl$GL$AUTO_NORMAL = 0x0D80,
  gl$GL$MAP1_COLOR_4 = 0x0D90,
  gl$GL$MAP1_INDEX = 0x0D91,
  gl$GL$MAP1_NORMAL = 0x0D92,
  gl$GL$MAP1_TEXTURE_COORD_1 = 0x0D93,
  gl$GL$MAP1_TEXTURE_COORD_2 = 0x0D94,
  gl$GL$MAP1_TEXTURE_COORD_3 = 0x0D95,
  gl$GL$MAP1_TEXTURE_COORD_4 = 0x0D96,
  gl$GL$MAP1_VERTEX_3 = 0x0D97,
  gl$GL$MAP1_VERTEX_4 = 0x0D98,
  gl$GL$MAP2_COLOR_4 = 0x0DB0,
  gl$GL$MAP2_INDEX = 0x0DB1,
  gl$GL$MAP2_NORMAL = 0x0DB2,
  gl$GL$MAP2_TEXTURE_COORD_1 = 0x0DB3,
  gl$GL$MAP2_TEXTURE_COORD_2 = 0x0DB4,
  gl$GL$MAP2_TEXTURE_COORD_3 = 0x0DB5,
  gl$GL$MAP2_TEXTURE_COORD_4 = 0x0DB6,
  gl$GL$MAP2_VERTEX_3 = 0x0DB7,
  gl$GL$MAP2_VERTEX_4 = 0x0DB8,
  gl$GL$MAP1_GRID_DOMAIN = 0x0DD0,
  gl$GL$MAP1_GRID_SEGMENTS = 0x0DD1,
  gl$GL$MAP2_GRID_DOMAIN = 0x0DD2,
  gl$GL$MAP2_GRID_SEGMENTS = 0x0DD3,
  gl$GL$TEXTURE_1D = 0x0DE0,
  gl$GL$TEXTURE_2D = 0x0DE1,
  gl$GL$FEEDBACK_BUFFER_POINTER = 0x0DF0,
  gl$GL$FEEDBACK_BUFFER_SIZE = 0x0DF1,
  gl$GL$FEEDBACK_BUFFER_TYPE = 0x0DF2,
  gl$GL$SELECTION_BUFFER_POINTER = 0x0DF3,
  gl$GL$SELECTION_BUFFER_SIZE = 0x0DF4,
  gl$GL$TEXTURE_WIDTH = 0x1000,
  gl$GL$TRANSFORM_BIT = 0x00001000,
  gl$GL$TEXTURE_HEIGHT = 0x1001,
  gl$GL$TEXTURE_INTERNAL_FORMAT = 0x1003,
  gl$GL$TEXTURE_BORDER_COLOR = 0x1004,
  gl$GL$TEXTURE_BORDER = 0x1005,
  gl$GL$DONT_CARE = 0x1100,
  gl$GL$FASTEST = 0x1101,
  gl$GL$NICEST = 0x1102,
  gl$GL$AMBIENT = 0x1200,
  gl$GL$DIFFUSE = 0x1201,
  gl$GL$SPECULAR = 0x1202,
  gl$GL$POSITION = 0x1203,
  gl$GL$SPOT_DIRECTION = 0x1204,
  gl$GL$SPOT_EXPONENT = 0x1205,
  gl$GL$SPOT_CUTOFF = 0x1206,
  gl$GL$CONSTANT_ATTENUATION = 0x1207,
  gl$GL$LINEAR_ATTENUATION = 0x1208,
  gl$GL$QUADRATIC_ATTENUATION = 0x1209,
  gl$GL$COMPILE = 0x1300,
  gl$GL$COMPILE_AND_EXECUTE = 0x1301,
  gl$GL$BYTE = 0x1400,
  gl$GL$UNSIGNED_BYTE = 0x1401,
  gl$GL$SHORT = 0x1402,
  gl$GL$UNSIGNED_SHORT = 0x1403,
  gl$GL$INT = 0x1404,
  gl$GL$UNSIGNED_INT = 0x1405,
  gl$GL$FLOAT = 0x1406,
  gl$GL$TWO_BYTES = 0x1407,
  gl$GL$THREE_BYTES = 0x1408,
  gl$GL$FOUR_BYTES = 0x1409,
  gl$GL$DOUBLE = 0x140A,
  gl$GL$CLEAR = 0x1500,
  gl$GL$AND = 0x1501,
  gl$GL$AND_REVERSE = 0x1502,
  gl$GL$COPY = 0x1503,
  gl$GL$AND_INVERTED = 0x1504,
  gl$GL$NOOP = 0x1505,
  gl$GL$XOR = 0x1506,
  gl$GL$OR = 0x1507,
  gl$GL$NOR = 0x1508,
  gl$GL$EQUIV = 0x1509,
  gl$GL$INVERT = 0x150A,
  gl$GL$OR_REVERSE = 0x150B,
  gl$GL$COPY_INVERTED = 0x150C,
  gl$GL$OR_INVERTED = 0x150D,
  gl$GL$NAND = 0x150E,
  gl$GL$SET = 0x150F,
  gl$GL$EMISSION = 0x1600,
  gl$GL$SHININESS = 0x1601,
  gl$GL$AMBIENT_AND_DIFFUSE = 0x1602,
  gl$GL$COLOR_INDEXES = 0x1603,
  gl$GL$MODELVIEW = 0x1700,
  gl$GL$PROJECTION = 0x1701,
  gl$GL$TEXTURE = 0x1702,
  gl$GL$COLOR = 0x1800,
  gl$GL$DEPTH = 0x1801,
  gl$GL$STENCIL = 0x1802,
  gl$GL$COLOR_INDEX = 0x1900,
  gl$GL$STENCIL_INDEX = 0x1901,
  gl$GL$DEPTH_COMPONENT = 0x1902,
  gl$GL$RED = 0x1903,
  gl$GL$GREEN = 0x1904,
  gl$GL$BLUE = 0x1905,
  gl$GL$ALPHA = 0x1906,
  gl$GL$RGB = 0x1907,
  gl$GL$RGBA = 0x1908,
  gl$GL$LUMINANCE = 0x1909,
  gl$GL$LUMINANCE_ALPHA = 0x190A,
  gl$GL$BITMAP = 0x1A00,
  gl$GL$POINT = 0x1B00,
  gl$GL$LINE = 0x1B01,
  gl$GL$FILL = 0x1B02,
  gl$GL$RENDER = 0x1C00,
  gl$GL$FEEDBACK = 0x1C01,
  gl$GL$SELECT = 0x1C02,
  gl$GL$FLAT = 0x1D00,
  gl$GL$SMOOTH = 0x1D01,
  gl$GL$KEEP = 0x1E00,
  gl$GL$REPLACE = 0x1E01,
  gl$GL$INCR = 0x1E02,
  gl$GL$DECR = 0x1E03,
  gl$GL$VENDOR = 0x1F00,
  gl$GL$RENDERER = 0x1F01,
  gl$GL$VERSION = 0x1F02,
  gl$GL$EXTENSIONS = 0x1F03,
  gl$GL$ENABLE_BIT = 0x00002000,
  gl$GL$S = 0x2000,
  gl$GL$T = 0x2001,
  gl$GL$R = 0x2002,
  gl$GL$Q = 0x2003,
  gl$GL$MODULATE = 0x2100,
  gl$GL$DECAL = 0x2101,
  gl$GL$TEXTURE_ENV_MODE = 0x2200,
  gl$GL$TEXTURE_ENV_COLOR = 0x2201,
  gl$GL$TEXTURE_ENV = 0x2300,
  gl$GL$EYE_LINEAR = 0x2400,
  gl$GL$OBJECT_LINEAR = 0x2401,
  gl$GL$SPHERE_MAP = 0x2402,
  gl$GL$TEXTURE_GEN_MODE = 0x2500,
  gl$GL$OBJECT_PLANE = 0x2501,
  gl$GL$EYE_PLANE = 0x2502,
  gl$GL$NEAREST = 0x2600,
  gl$GL$LINEAR = 0x2601,
  gl$GL$NEAREST_MIPMAP_NEAREST = 0x2700,
  gl$GL$LINEAR_MIPMAP_NEAREST = 0x2701,
  gl$GL$NEAREST_MIPMAP_LINEAR = 0x2702,
  gl$GL$LINEAR_MIPMAP_LINEAR = 0x2703,
  gl$GL$TEXTURE_MAG_FILTER = 0x2800,
  gl$GL$TEXTURE_MIN_FILTER = 0x2801,
  gl$GL$TEXTURE_WRAP_S = 0x2802,
  gl$GL$TEXTURE_WRAP_T = 0x2803,
  gl$GL$CLAMP = 0x2900,
  gl$GL$REPEAT = 0x2901,
  gl$GL$POLYGON_OFFSET_UNITS = 0x2A00,
  gl$GL$POLYGON_OFFSET_POINT = 0x2A01,
  gl$GL$POLYGON_OFFSET_LINE = 0x2A02,
  gl$GL$R3_G3_B2 = 0x2A10,
  gl$GL$V2F = 0x2A20,
  gl$GL$V3F = 0x2A21,
  gl$GL$C4UB_V2F = 0x2A22,
  gl$GL$C4UB_V3F = 0x2A23,
  gl$GL$C3F_V3F = 0x2A24,
  gl$GL$N3F_V3F = 0x2A25,
  gl$GL$C4F_N3F_V3F = 0x2A26,
  gl$GL$T2F_V3F = 0x2A27,
  gl$GL$T4F_V4F = 0x2A28,
  gl$GL$T2F_C4UB_V3F = 0x2A29,
  gl$GL$T2F_C3F_V3F = 0x2A2A,
  gl$GL$T2F_N3F_V3F = 0x2A2B,
  gl$GL$T2F_C4F_N3F_V3F = 0x2A2C,
  gl$GL$T4F_C4F_N3F_V4F = 0x2A2D,
  gl$GL$CLIP_PLANE0 = 0x3000,
  gl$GL$CLIP_PLANE1 = 0x3001,
  gl$GL$CLIP_PLANE2 = 0x3002,
  gl$GL$CLIP_PLANE3 = 0x3003,
  gl$GL$CLIP_PLANE4 = 0x3004,
  gl$GL$CLIP_PLANE5 = 0x3005,
  gl$GL$LIGHT0 = 0x4000,
  gl$GL$COLOR_BUFFER_BIT = 0x00004000,
  gl$GL$LIGHT1 = 0x4001,
  gl$GL$LIGHT2 = 0x4002,
  gl$GL$LIGHT3 = 0x4003,
  gl$GL$LIGHT4 = 0x4004,
  gl$GL$LIGHT5 = 0x4005,
  gl$GL$LIGHT6 = 0x4006,
  gl$GL$LIGHT7 = 0x4007,
  gl$GL$HINT_BIT = 0x00008000,
  gl$GL$POLYGON_OFFSET_FILL = 0x8037,
  gl$GL$POLYGON_OFFSET_FACTOR = 0x8038,
  gl$GL$ALPHA4 = 0x803B,
  gl$GL$ALPHA8 = 0x803C,
  gl$GL$ALPHA12 = 0x803D,
  gl$GL$ALPHA16 = 0x803E,
  gl$GL$LUMINANCE4 = 0x803F,
  gl$GL$LUMINANCE8 = 0x8040,
  gl$GL$LUMINANCE12 = 0x8041,
  gl$GL$LUMINANCE16 = 0x8042,
  gl$GL$LUMINANCE4_ALPHA4 = 0x8043,
  gl$GL$LUMINANCE6_ALPHA2 = 0x8044,
  gl$GL$LUMINANCE8_ALPHA8 = 0x8045,
  gl$GL$LUMINANCE12_ALPHA4 = 0x8046,
  gl$GL$LUMINANCE12_ALPHA12 = 0x8047,
  gl$GL$LUMINANCE16_ALPHA16 = 0x8048,
  gl$GL$INTENSITY = 0x8049,
  gl$GL$INTENSITY4 = 0x804A,
  gl$GL$INTENSITY8 = 0x804B,
  gl$GL$INTENSITY12 = 0x804C,
  gl$GL$INTENSITY16 = 0x804D,
  gl$GL$RGB4 = 0x804F,
  gl$GL$RGB5 = 0x8050,
  gl$GL$RGB8 = 0x8051,
  gl$GL$RGB10 = 0x8052,
  gl$GL$RGB12 = 0x8053,
  gl$GL$RGB16 = 0x8054,
  gl$GL$RGBA2 = 0x8055,
  gl$GL$RGBA4 = 0x8056,
  gl$GL$RGB5_A1 = 0x8057,
  gl$GL$RGBA8 = 0x8058,
  gl$GL$RGB10_A2 = 0x8059,
  gl$GL$RGBA12 = 0x805A,
  gl$GL$RGBA16 = 0x805B,
  gl$GL$TEXTURE_RED_SIZE = 0x805C,
  gl$GL$TEXTURE_GREEN_SIZE = 0x805D,
  gl$GL$TEXTURE_BLUE_SIZE = 0x805E,
  gl$GL$TEXTURE_ALPHA_SIZE = 0x805F,
  gl$GL$TEXTURE_LUMINANCE_SIZE = 0x8060,
  gl$GL$TEXTURE_INTENSITY_SIZE = 0x8061,
  gl$GL$PROXY_TEXTURE_1D = 0x8063,
  gl$GL$PROXY_TEXTURE_2D = 0x8064,
  gl$GL$TEXTURE_PRIORITY = 0x8066,
  gl$GL$TEXTURE_RESIDENT = 0x8067,
  gl$GL$TEXTURE_BINDING_1D = 0x8068,
  gl$GL$TEXTURE_BINDING_2D = 0x8069,
  gl$GL$VERTEX_ARRAY = 0x8074,
  gl$GL$NORMAL_ARRAY = 0x8075,
  gl$GL$COLOR_ARRAY = 0x8076,
  gl$GL$INDEX_ARRAY = 0x8077,
  gl$GL$TEXTURE_COORD_ARRAY = 0x8078,
  gl$GL$EDGE_FLAG_ARRAY = 0x8079,
  gl$GL$VERTEX_ARRAY_SIZE = 0x807A,
  gl$GL$VERTEX_ARRAY_TYPE = 0x807B,
  gl$GL$VERTEX_ARRAY_STRIDE = 0x807C,
  gl$GL$NORMAL_ARRAY_TYPE = 0x807E,
  gl$GL$NORMAL_ARRAY_STRIDE = 0x807F,
  gl$GL$COLOR_ARRAY_SIZE = 0x8081,
  gl$GL$COLOR_ARRAY_TYPE = 0x8082,
  gl$GL$COLOR_ARRAY_STRIDE = 0x8083,
  gl$GL$INDEX_ARRAY_TYPE = 0x8085,
  gl$GL$INDEX_ARRAY_STRIDE = 0x8086,
  gl$GL$TEXTURE_COORD_ARRAY_SIZE = 0x8088,
  gl$GL$TEXTURE_COORD_ARRAY_TYPE = 0x8089,
  gl$GL$TEXTURE_COORD_ARRAY_STRIDE = 0x808A,
  gl$GL$EDGE_FLAG_ARRAY_STRIDE = 0x808C,
  gl$GL$VERTEX_ARRAY_POINTER = 0x808E,
  gl$GL$NORMAL_ARRAY_POINTER = 0x808F,
  gl$GL$COLOR_ARRAY_POINTER = 0x8090,
  gl$GL$INDEX_ARRAY_POINTER = 0x8091,
  gl$GL$TEXTURE_COORD_ARRAY_POINTER = 0x8092,
  gl$GL$EDGE_FLAG_ARRAY_POINTER = 0x8093,
  gl$GL$COLOR_INDEX1_EXT = 0x80E2,
  gl$GL$COLOR_INDEX2_EXT = 0x80E3,
  gl$GL$COLOR_INDEX4_EXT = 0x80E4,
  gl$GL$COLOR_INDEX8_EXT = 0x80E5,
  gl$GL$COLOR_INDEX12_EXT = 0x80E6,
  gl$GL$COLOR_INDEX16_EXT = 0x80E7,
  gl$GL$EVAL_BIT = 0x00010000,
  gl$GL$LIST_BIT = 0x00020000,
  gl$GL$TEXTURE_BIT = 0x00040000,
  gl$GL$SCISSOR_BIT = 0x00080000,
  gl$GL$ALL_ATTRIB_BITS = 0x000fffff,
  gl$GL$CLIENT_ALL_ATTRIB_BITS = 0xffffffff
} gl$GL;
extern void  glEnable(u32);
extern void  glClearColor(f32, f32, f32, f32);
typedef struct arena$Arena arena$Arena;
typedef struct dyn$Allocator{
void *instance;
void(*destroy)(void*);
void*(*resize)(void*, void*, u64, u64);
void*(*copy)(void*, void*, u64, u64);
void*(*allocate_array)(void*, u64, u64);
void(*free)(void*, void*);
void*(*allocate)(void*, u64);
} dyn$Allocator;
typedef struct String {
  u8* data;
  u64 length;
  u64 capacity;
  dyn$Allocator allocator;
} String;
typedef struct GeneralBuffer$1866 {
  s32 vao;
  s32 vbo;
  String descriptor;
} GeneralBuffer$1866;
extern void  glGenVertexArrays(s32, u32*);
extern void  glGenBuffers(s32, u32*);
typedef struct Type Type;
typedef struct Field Field;
typedef struct List$449 {
  Field* data;
  u64 length;
  u64 capacity;
  dyn$Allocator allocator;
} List$449;
typedef struct List$49 {
  Type** data;
  u64 length;
  u64 capacity;
  dyn$Allocator allocator;
} List$49;
typedef struct Method Method;
typedef struct List$450 {
  Method* data;
  u64 length;
  u64 capacity;
  dyn$Allocator allocator;
} List$450;
typedef struct Type {
  s32 id;
  str name;
  u64 size;
  u64 flags;
  Type* element_type;
  List$449 fields;
  List$49 traits;
  List$49 generic_args;
  List$450 methods;
} Type;
typedef struct gl$Vec3 {
  f32 x;
  f32 y;
  f32 z;
} gl$Vec3;
typedef struct gl$Vec2 {
  f32 x;
  f32 y;
} gl$Vec2;
typedef struct Vertex {
  gl$Vec3 position;
  gl$Vec3 normal;
  gl$Vec2 texcoord;
} Vertex;
extern void  glBindVertexArray(s32);
extern void  glBindBuffer(s32, u32);
typedef enum: u32 {
  fs$fmt$NumberStyle$Decimal = 0,
  fs$fmt$NumberStyle$Binary = 1,
  fs$fmt$NumberStyle$Hexadecimal = 2
} fs$fmt$NumberStyle;
typedef struct fs$fmt$FormatOptions {
  u8 digits_after_decimal;
  bool indented;
  bool quote_strings;
  bool typename;
  u32 number_style;
} fs$fmt$FormatOptions;
fs$fmt$FormatOptions fs$fmt$FormatOptions$$default() {
  return (fs$fmt$FormatOptions)(fs$fmt$FormatOptions){
    .digits_after_decimal = (u8)2,
    .indented = (bool)false,
    .quote_strings = (bool)false,
    .typename = (bool)true,};
}
typedef struct fs$fmt$StringBuilderBlock fs$fmt$StringBuilderBlock;
dyn$Allocator global_allocator;
bool dyn$Allocator$has_instance(dyn$Allocator self) {
  return (self.instance != NULL);
}
dyn$Allocator global_dyn_libc_allocator;
typedef struct Libc_Allocator {
} Libc_Allocator;
Libc_Allocator global_libc_allocator;
typedef struct Libc_Allocator Libc_Allocator;
void Libc_Allocator$destroy(Libc_Allocator* self) {
}
extern void*  realloc(void*, u64);
void* Libc_Allocator$resize(Libc_Allocator* self, void* ptr, u64 element_size, u64 new_size) {
  return realloc(ptr,(element_size * new_size));
}
extern void*  calloc(u64, u64);
void* Libc_Allocator$allocate_array(Libc_Allocator* self, u64 size, u64 n) {
  return calloc(size,n);
}
extern void*  memcpy(void*, void*, u64);
void* Libc_Allocator$copy(Libc_Allocator* self, void* ptr, u64 element_size, u64 n) {
  void* newptr  = Libc_Allocator$allocate_array(self, element_size,n);
  memcpy(newptr,ptr,(n * element_size));
  return newptr;
}
extern void  free(void*);
void Libc_Allocator$free(Libc_Allocator* self, void* ptr) {
  free(ptr);
}
void* std$malloc(u64 nbytes);
void* Libc_Allocator$allocate(Libc_Allocator* self, u64 size) {
  return malloc(size);
}
dyn$Allocator get_global_allocator() {
  
  if ((!dyn$Allocator$has_instance(global_allocator))) {
    
    if ((!dyn$Allocator$has_instance(global_dyn_libc_allocator))) {
      (global_dyn_libc_allocator = (dyn$Allocator) {
.instance = (void*)(&global_libc_allocator),
.destroy = (void(*)(void*))Libc_Allocator$destroy,
.resize = (void*(*)(void*, void*, u64, u64))Libc_Allocator$resize,
.copy = (void*(*)(void*, void*, u64, u64))Libc_Allocator$copy,
.allocate_array = (void*(*)(void*, u64, u64))Libc_Allocator$allocate_array,
.free = (void(*)(void*, void*))Libc_Allocator$free,
.allocate = (void*(*)(void*, u64))Libc_Allocator$allocate,
});
    }
;
    (global_allocator = global_dyn_libc_allocator);
  }
;
  return global_allocator;
}
typedef struct fs$fmt$StringBuilder {
  fs$fmt$StringBuilderBlock* root;
  fs$fmt$StringBuilderBlock* current;
  dyn$Allocator allocator;
  u64 block_size;
} fs$fmt$StringBuilder;
typedef enum: u32 {
  ArenaFlags$None = 1,
  ArenaFlags$Align = 2
} ArenaFlags;
typedef struct arena$Arena {
  u64 ptr;
  u64 size;
  u8* memory;
  u32 flags;
  u64 alignment;
  arena$Arena* next;
} arena$Arena;
void* std$calloc(u64 num, u64 size);
arena$Arena arena$Arena$new(u64 size, u32 flags) {
  return (arena$Arena)(arena$Arena){
    .size = (u64)size,
    .memory = (u8*)calloc(sizeof(u8),size),
    .flags = (ArenaFlags)flags,
    .alignment = (u64)sizeof(void*),
    .next = (arena$Arena*)NULL,};
}
void arena$Arena$destroy(arena$Arena* self);
void std$free(void* ptr);
void arena$Arena$destroy(arena$Arena* self) {
  
  if (self->next) {
    arena$Arena$destroy(self->next);
    free(self->next);
    (self->next = NULL);
  }
;
  free(self->memory);
  (self->memory = NULL);
}
typedef struct fs$fmt$StringBuilder fs$fmt$StringBuilder;
typedef struct Slice$7 {
  u8* data;
  u64 length;
} Slice$7;
Slice$7 str$as_slice(str self) {
  return (Slice$7)(Slice$7){
    .data = (u8*)self.data,
    .length = (u64)self.length,};
}
typedef struct fs$fmt$StringBuilderBlock {
  u8* data;
  u64 length;
  fs$fmt$StringBuilderBlock* next;
  u64 block_size;
  dyn$Allocator allocator;
} fs$fmt$StringBuilderBlock;
fs$fmt$StringBuilderBlock* fs$fmt$StringBuilderBlock$new(dyn$Allocator allocator, u64 size) {
  fs$fmt$StringBuilderBlock* self  = allocator.allocate(allocator.instance, sizeof(fs$fmt$StringBuilderBlock));
  (self->allocator = allocator);
  (self->data = allocator.allocate_array(allocator.instance, sizeof(u8), size));
  (self->length = 0);
  (self->next = NULL);
  (self->block_size = size);
  return self;
}
u64 gl$math$min$4(u64 a, u64 b) {
  
  if ((a > b)) {
    return b;
  }
;
  return a;
}
void fs$fmt$StringBuilder$append$32(fs$fmt$StringBuilder* self, str value) {
  Slice$7 slice  = str$as_slice(value);
  
  if ((slice.length <= 0)) {
    return;
  }
;
  
  if ((!self->root)) {
    (self->root = fs$fmt$StringBuilderBlock$new(self->allocator,self->block_size));
    (self->current = self->root);
  }
;
  s32 slice_index  = 0;
  u64 length  = slice.length;
  
  if (((length == 1) && (slice.data[0] == 0x0))) {
    return;
  }
;
  u64 remaining  = (self->block_size - self->current->length);
  while ((length > 0)) {
    
    if ((remaining == 0)) {
      (self->current->next = fs$fmt$StringBuilderBlock$new(self->allocator,self->block_size));
      (self->current = self->current->next);
      (remaining = self->block_size);
    }
;
    u64 to_copy  = gl$math$min$4(length,remaining);
    memcpy((self->current->data + self->current->length),(slice.data + slice_index),to_copy);
    (self->current->length += to_copy);
    (slice_index += to_copy);
    (length -= to_copy);
    (remaining -= to_copy);
  }
}
typedef struct $tuple1$1 {
  s32 $0;
  s32 $1;
} $tuple1$1;
typedef struct fs$fmt$Formatter {
  fs$fmt$StringBuilder* writer;
  u32 indentation;
  fs$fmt$FormatOptions options;
} fs$fmt$Formatter;
void fs$fmt$StringBuilderBlock$destroy(fs$fmt$StringBuilderBlock* self, bool recursive);
void fs$fmt$StringBuilderBlock$destroy(fs$fmt$StringBuilderBlock* self, bool recursive) {
  
  if (self->data) {
    self->allocator.free(self->allocator.instance, self->data);
  }
;
  
  if (self->next) {
    fs$fmt$StringBuilderBlock$destroy(self->next, true);
    self->allocator.free(self->allocator.instance, self->next);
  }
;
}
void fs$fmt$StringBuilder$destroy(fs$fmt$StringBuilder* self, bool recursive) {
  
  if (self->root) {
    fs$fmt$StringBuilderBlock$destroy(self->root, true);
    self->allocator.free(self->allocator.instance, self->root);
  }
;
}
static inline bool List$449$is_empty(List$449 self) {
  return (self.length == 0);
}
String str$to_string$35(str self, dyn$Allocator allocator) {
  return (String)(String){
    .data = (u8*)allocator.copy(allocator.instance, self.data, sizeof(u8), self.length),
    .length = (u64)self.length,};
}
Slice$7 u32$as_slice(u32 self) {
  static u8 chars[2] = {0x0, 0x0};
  (chars[0] = self);
  return (Slice$7)(Slice$7){
    .data = (u8*)chars,
    .length = (u64)1,};
}
u64 gl$math$min$4(u64 a, u64 b);
void fs$fmt$StringBuilder$append$5(fs$fmt$StringBuilder* self, u32 value) {
  Slice$7 slice  = u32$as_slice(value);
  
  if ((slice.length <= 0)) {
    return;
  }
;
  
  if ((!self->root)) {
    (self->root = fs$fmt$StringBuilderBlock$new(self->allocator,self->block_size));
    (self->current = self->root);
  }
;
  s32 slice_index  = 0;
  u64 length  = slice.length;
  
  if (((length == 1) && (slice.data[0] == 0x0))) {
    return;
  }
;
  u64 remaining  = (self->block_size - self->current->length);
  while ((length > 0)) {
    
    if ((remaining == 0)) {
      (self->current->next = fs$fmt$StringBuilderBlock$new(self->allocator,self->block_size));
      (self->current = self->current->next);
      (remaining = self->block_size);
    }
;
    u64 to_copy  = gl$math$min$4(length,remaining);
    memcpy((self->current->data + self->current->length),(slice.data + slice_index),to_copy);
    (self->current->length += to_copy);
    (slice_index += to_copy);
    (length -= to_copy);
    (remaining -= to_copy);
  }
}
extern s32  printf(u8*, ...);;
extern void  exit(s32);
void $lambda$4 (str msg)
{
  printf("panic(): %s\n",msg.data);
  exit(1);
}

void(*panic_handler)(str) = $lambda$4;
void panic(str msg) {
  panic_handler(msg);
}
typedef struct Field {
  str name;
  Type* _type;
  u64 size;
  u64 offset;
  s64 enum_value;
} Field;
typedef struct List$449 List$449;
Field* List$449$index(List$449* self, u64 idx) {
  return (&self->data[idx]);
}
typedef struct any {
  void* ptr;
  Type* _type;
} any;
typedef struct $tuple1$1 $tuple1$1;
u8* Field$get$402(Field* self, $tuple1$1* source) {
  return ((u8*)source + self->offset);
}
typedef struct fs$fmt$Formatter fs$fmt$Formatter;
typedef struct Iter$49 {
  Type** ptr;
  Type** end;
} Iter$49;
typedef struct List$49 List$49;
static inline Iter$49 List$49$iter(List$49* self) {
  return (Iter$49)(Iter$49){
    .ptr = (Type**)self->data,
    .end = (Type**)(Type**)(self->data + self->length),};
}
typedef struct $tuple49 {
  Type* $0;
} $tuple49;
typedef struct Option$49 Option$49;
typedef $tuple49 Option$49$Some;
typedef struct Option$49 {
  int index;
  union {
    Option$49$Some Some;
  };
} Option$49;
typedef struct Iter$49 Iter$49;
static inline Option$49 Iter$49$next(Iter$49* self) {
  
  if ((self->ptr >= self->end)) {
    return  (Option$49) { .index = 1};
  }
;
  Option$49 value  = (Option$49) {
.index = 2,
.Some = ($tuple49) {.$0 = (*self->ptr)}};
  self->ptr++;
  return value;
}
u8* str$index(str* self, u64 idx) {
  return (&self->data[idx]);
}
bool str$eq(str self, str other) {
  
  if ((self.length != other.length)) {
    return false;
  }
;
  {
    RangeBase$1 $iterable = (RangeBase$1) {.begin = 0, .end = self.length};
    RangeIter$1 $iterator = RangeBase$1$iter(&$iterable);


    for (auto $next = RangeIter$1$next(&$iterator);
$next.index != 1; $next = RangeIter$1$next(&$iterator)) {
    s32 idx = $next.Some.$0;
    {
      
      if (((*(str$index(&self, idx))) != (*(str$index(&other, idx))))) {
        return false;
      }
;
    }
  }
}
return true;
}
bool Type$implements(Type* self, str trait_name) {
  {
    List$49 $iterable = self->traits;
    Iter$49 $iterator = List$49$iter(&$iterable);


    for (auto $next = Iter$49$next(&$iterator);
$next.index != 1; $next = Iter$49$next(&$iterator)) {
    Type* _trait = $next.Some.$0;
    {
      
      if ((str$eq(_trait->name, trait_name))) {
        return true;
      }
;
    }
  }
}
return false;
}
typedef struct List$5 List$5;
typedef struct dyn$fs$fmt$Format{
void *instance;
void(*format)(void*, fs$fmt$Formatter*);
} dyn$fs$fmt$Format;
typedef struct Method {
  str name;
  void* pointer;
} Method;
bool $lambda$6 (Method* method)
{
  return (str$eq(method->name, (str) { .data = "format", .length = 6 }));
}

Method* List$450$find_first_of(List$450 self, bool(*finder)(Method*)) {
  {
    RangeBase$1 $iterable = (RangeBase$1) {.begin = 0, .end = self.length};
    RangeIter$1 $iterator = RangeBase$1$iter(&$iterable);


    for (auto $next = RangeIter$1$next(&$iterator);
$next.index != 1; $next = RangeIter$1$next(&$iterator)) {
    s32 idx = $next.Some.$0;
    {
      
      if (finder((&self.data[idx]))) {
        return (&self.data[idx]);
      }
;
    }
  }
}
return NULL;
}
s32 fs$fmt$printf(u8* format, ...);
dyn$fs$fmt$Format fs$fmt$new_dyn_format(any value) {
any $deconstruction$0 = value;
auto instance = $deconstruction$0.ptr;
auto _type = $deconstruction$0._type;
  Method* method  = List$450$find_first_of(_type->methods, $lambda$6);
  
  if ((!method)) {
    printf("unable to find 'format' in _type %s\n",_type->name);
    panic((str) { .data = "DynFormat failure", .length = 17 });
  }
;
  dyn$fs$fmt$Format dynamic  = (dyn$fs$fmt$Format){0};
  (dynamic.instance = instance);
  (dynamic.format = (void(*)(void*, fs$fmt$Formatter*))method->pointer);
  return dynamic;
}
void fs$fmt$StringBuilder$append$32(fs$fmt$StringBuilder* self, str value);
Slice$7 String$as_slice(String self) {
  return (Slice$7)(Slice$7){
    .data = (u8*)self.data,
    .length = (u64)self.length,};
}
void fs$fmt$StringBuilder$append$33(fs$fmt$StringBuilder* self, String value) {
  Slice$7 slice  = String$as_slice(value);
  
  if ((slice.length <= 0)) {
    return;
  }
;
  
  if ((!self->root)) {
    (self->root = fs$fmt$StringBuilderBlock$new(self->allocator,self->block_size));
    (self->current = self->root);
  }
;
  s32 slice_index  = 0;
  u64 length  = slice.length;
  
  if (((length == 1) && (slice.data[0] == 0x0))) {
    return;
  }
;
  u64 remaining  = (self->block_size - self->current->length);
  while ((length > 0)) {
    
    if ((remaining == 0)) {
      (self->current->next = fs$fmt$StringBuilderBlock$new(self->allocator,self->block_size));
      (self->current = self->current->next);
      (remaining = self->block_size);
    }
;
    u64 to_copy  = gl$math$min$4(length,remaining);
    memcpy((self->current->data + self->current->length),(slice.data + slice_index),to_copy);
    (self->current->length += to_copy);
    (slice_index += to_copy);
    (length -= to_copy);
    (remaining -= to_copy);
  }
}
typedef enum: u32 {
  TypeFlags$INTEGER = 1,
  TypeFlags$FLOAT = 2,
  TypeFlags$BOOL = 4,
  TypeFlags$STRUCT = 8,
  TypeFlags$CHOICE = 16,
  TypeFlags$ENUM = 32,
  TypeFlags$TUPLE = 64,
  TypeFlags$ARRAY = 128,
  TypeFlags$FUNCTION = 256,
  TypeFlags$POINTER = 512,
  TypeFlags$SIGNED = 1024,
  TypeFlags$UNSIGNED = 2048,
  TypeFlags$TRAIT = 4096,
  TypeFlags$DYN = 8192,
  TypeFlags$UNION = 16384,
  TypeFlags$FLAGS_ENUM = 32768
} TypeFlags;
bool Type$is_pointer(Type* self) {
  return ((self->flags & TypeFlags$POINTER) != 0);
}
extern s32  snprintf(u8*, u64, u8*, ...);;
String fs$fmt$to_string$36(void* value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$36));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
      (format_buffer[0] = 0x25);
      (format_buffer[1] = 0x70);
      (format_buffer[2] = 0x0);
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
typedef struct String String;
static inline void String$get_allocator_if_needed(String* self) {
  
  if ((!dyn$Allocator$has_instance(self->allocator))) {
    (self->allocator = get_global_allocator());
  }
;
}
void String$destroy(String* self, bool recursive) {
  String$get_allocator_if_needed(self);
  self->allocator.free(self->allocator.instance, self->data);
  (self->data = NULL);
  (self->capacity = 0);
  (self->length = 0);
}
void fs$fmt$StringBuilder$append_then_free$33(fs$fmt$StringBuilder* self, String value) {
  fs$fmt$StringBuilder$append$33(self, value);
  String$destroy(&value, true);
}
bool Type$is_struct(Type* self) {
  return ((self->flags & TypeFlags$STRUCT) != 0);
}
typedef struct Iter$449 {
  Field* ptr;
  Field* end;
} Iter$449;
static inline Iter$449 List$449$iter(List$449* self) {
  return (Iter$449)(Iter$449){
    .ptr = (Field*)self->data,
    .end = (Field*)(Field*)(self->data + self->length),};
}
typedef struct $tuple449 {
  Field $0;
} $tuple449;
typedef struct Option$449 Option$449;
typedef $tuple449 Option$449$Some;
typedef struct Option$449 {
  int index;
  union {
    Option$449$Some Some;
  };
} Option$449;
typedef struct Iter$449 Iter$449;
static inline Option$449 Iter$449$next(Iter$449* self) {
  
  if ((self->ptr >= self->end)) {
    return  (Option$449) { .index = 1};
  }
;
  Option$449 value  = (Option$449) {
.index = 2,
.Some = ($tuple449) {.$0 = (*self->ptr)}};
  self->ptr++;
  return value;
}
u8* Field$get$11(Field* self, void* source) {
  return ((u8*)source + self->offset);
}
void fs$fmt$format_any(any value, fs$fmt$Formatter* formatter);
void fs$fmt$format_struct(any value, fs$fmt$Formatter* formatter) {
  fs$fmt$StringBuilder$append$32(formatter->writer, value._type->name);
  fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = " {", .length = 2 });
  
  if (formatter->options.indented) {
    fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "\n", .length = 1 });
  }
;
  s32 idx  = 0;
  {
    List$449 $iterable = value._type->fields;
    Iter$449 $iterator = List$449$iter(&$iterable);


    for (auto $next = Iter$449$next(&$iterator);
$next.index != 1; $next = Iter$449$next(&$iterator)) {
    Field field = $next.Some.$0;
    {
      
      if (formatter->options.indented) {
        fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "  ", .length = 2 });
      }
;
      fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = " ", .length = 1 });
      fs$fmt$StringBuilder$append$32(formatter->writer, field.name);
      fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = ": ", .length = 2 });
      fs$fmt$format_any((any)(any){
        .ptr = (void*)Field$get$11(&field, value.ptr),
        ._type = (Type*)field._type,},formatter);
      
      if ((idx != (value._type->fields.length - 1))) {
        fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = ",", .length = 1 });
      }
;
      
      if (formatter->options.indented) {
        fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "\n", .length = 1 });
      }
;
      idx++;
    }
  }
}

if (formatter->options.indented) {
  fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "}", .length = 1 });
}
else{
  fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = " }", .length = 2 });
}
;
}
bool Type$is_tuple(Type* self) {
  return ((self->flags & TypeFlags$TUPLE) != 0);
}
u8* Field$get$11(Field* self, void* source);
void fs$fmt$format_tuple(any value, fs$fmt$Formatter* formatter) {
  fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "(", .length = 1 });
  {
    RangeBase$1 $iterable = (RangeBase$1) {.begin = 0, .end = value._type->fields.length};
    RangeIter$1 $iterator = RangeBase$1$iter(&$iterable);


    for (auto $next = RangeIter$1$next(&$iterator);
$next.index != 1; $next = RangeIter$1$next(&$iterator)) {
    s32 i = $next.Some.$0;
    {
      Field field  = (*(List$449$index(&value._type->fields, i)));
      fs$fmt$format_any((any)(any){
        .ptr = (void*)Field$get$11(&field, value.ptr),
        ._type = (Type*)field._type,},formatter);
      
      if ((i != (value._type->fields.length - 1))) {
        fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = ", ", .length = 2 });
      }
;
    }
  }
}
fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = ")", .length = 1 });
}
typedef struct any any;
u8* any$unwrap$29(any* self) {
  return (*(u8**)self->ptr);
}
extern u32  strlen(u8*);
String String$from_ptr(u8* data) {
  u32 length  = strlen(data);
  return (String)(String){
    .data = (u8*)get_global_allocator().copy(get_global_allocator().instance, data, sizeof(u8), length),
    .length = (u64)length,
    .capacity = (u64)length,
    .allocator = (dyn$Allocator)get_global_allocator(),};
}
bool Type$is_flags_enum(Type* self) {
  return ((self->flags & TypeFlags$FLAGS_ENUM) != 0);
}
s32 any$unwrap$1(any* self) {
  return (*(s32*)self->ptr);
}
bool Type$is_enum(Type* self) {
  return ((self->flags & TypeFlags$ENUM) != 0);
}
s32 any$unwrap$1(any* self);
u8 any$unwrap$7(any* self) {
  return (*(u8*)self->ptr);
}
String fs$fmt$to_string$7(u8 value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$7));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
      (format_buffer[0] = 0x25);
      (format_buffer[1] = 0x63);
      (format_buffer[2] = 0x0);
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
void fs$fmt$StringBuilder$append_then_free$33(fs$fmt$StringBuilder* self, String value);
u16 any$unwrap$6(any* self) {
  return (*(u16*)self->ptr);
}
String fs$fmt$to_string$6(u16 value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$6));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
{
                fs$fmt$NumberStyle $switch_target$0 = options.number_style;
        if ($switch_target$0 == fs$fmt$NumberStyle$Decimal) {
          memcpy(format_buffer,"%u",3);
        }
        else         if ($switch_target$0 == fs$fmt$NumberStyle$Binary) {
          memcpy(format_buffer,"0b%b",5);
        }
        else         if ($switch_target$0 == fs$fmt$NumberStyle$Hexadecimal) {
          memcpy(format_buffer,"%#0dX",5);
        }
;
      }
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
u32 any$unwrap$5(any* self) {
  return (*(u32*)self->ptr);
}
String fs$fmt$to_string$5(u32 value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$5));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
{
                fs$fmt$NumberStyle $switch_target$1 = options.number_style;
        if ($switch_target$1 == fs$fmt$NumberStyle$Decimal) {
          memcpy(format_buffer,"%u",3);
        }
        else         if ($switch_target$1 == fs$fmt$NumberStyle$Binary) {
          memcpy(format_buffer,"0b%b",5);
        }
        else         if ($switch_target$1 == fs$fmt$NumberStyle$Hexadecimal) {
          memcpy(format_buffer,"%#0dX",5);
        }
;
      }
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
u64 any$unwrap$4(any* self) {
  return (*(u64*)self->ptr);
}
String fs$fmt$to_string$4(u64 value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$4));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
{
                fs$fmt$NumberStyle $switch_target$2 = options.number_style;
        if ($switch_target$2 == fs$fmt$NumberStyle$Decimal) {
          memcpy(format_buffer,"%lu",4);
        }
        else         if ($switch_target$2 == fs$fmt$NumberStyle$Binary) {
          memcpy(format_buffer,"0b%b",5);
        }
        else         if ($switch_target$2 == fs$fmt$NumberStyle$Hexadecimal) {
          memcpy(format_buffer,"%#0dX",5);
        }
;
      }
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
s8 any$unwrap$3(any* self) {
  return (*(s8*)self->ptr);
}
String fs$fmt$to_string$3(s8 value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$3));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
s16 any$unwrap$2(any* self) {
  return (*(s16*)self->ptr);
}
String fs$fmt$to_string$2(s16 value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$2));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
{
                fs$fmt$NumberStyle $switch_target$3 = options.number_style;
        if ($switch_target$3 == fs$fmt$NumberStyle$Decimal) {
          memcpy(format_buffer,"%d",3);
        }
        else         if ($switch_target$3 == fs$fmt$NumberStyle$Binary) {
          memcpy(format_buffer,"0b%b",5);
        }
        else         if ($switch_target$3 == fs$fmt$NumberStyle$Hexadecimal) {
          memcpy(format_buffer,"%#0dX",5);
        }
;
      }
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
String fs$fmt$to_string$1(s32 value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$1));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
{
                fs$fmt$NumberStyle $switch_target$4 = options.number_style;
        if ($switch_target$4 == fs$fmt$NumberStyle$Decimal) {
          memcpy(format_buffer,"%d",3);
        }
        else         if ($switch_target$4 == fs$fmt$NumberStyle$Binary) {
          memcpy(format_buffer,"0b%b",5);
        }
        else         if ($switch_target$4 == fs$fmt$NumberStyle$Hexadecimal) {
          memcpy(format_buffer,"%#0dX",5);
        }
;
      }
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
s64 any$unwrap$0(any* self) {
  return (*(s64*)self->ptr);
}
String fs$fmt$to_string$0(s64 value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$0));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
{
                fs$fmt$NumberStyle $switch_target$5 = options.number_style;
        if ($switch_target$5 == fs$fmt$NumberStyle$Decimal) {
          memcpy(format_buffer,"%ld",4);
        }
        else         if ($switch_target$5 == fs$fmt$NumberStyle$Binary) {
          memcpy(format_buffer,"0b%b",5);
        }
        else         if ($switch_target$5 == fs$fmt$NumberStyle$Hexadecimal) {
          memcpy(format_buffer,"%#0dX",5);
        }
;
      }
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
f32 any$unwrap$9(any* self) {
  return (*(f32*)self->ptr);
}
extern s32  sprintf(u8*, u8*, ...);;
String fs$fmt$to_string$9(f32 value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$9));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
      sprintf(format_buffer,"%%.%df",options.digits_after_decimal);
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
f64 any$unwrap$8(any* self) {
  return (*(f64*)self->ptr);
}
s32 std$sprintf(u8* buffer, u8* format, ...);
String fs$fmt$to_string$8(f64 value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    Type* _type  = ((Type *)(&refl_ty$8));
    str format  = (str){};
    u8 format_buffer[255] = {0};
{
      sprintf(format_buffer,"%%.%dlf",options.digits_after_decimal);
    }
    u8 buffer[1024] = {0};
    s32 length  = snprintf(buffer,(1024 * sizeof(u8)),format_buffer,value);
    return (String)(String){
      .data = (u8*)allocator.copy(allocator.instance, buffer, sizeof(u8), length),
      .length = (u64)length,};
  }
}
bool any$unwrap$10(any* self) {
  return (*(bool*)self->ptr);
}
String str$to_string$35(str self, dyn$Allocator allocator);
String fs$fmt$to_string$10(bool value, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
{
    
    if (value) {
      return str$to_string$35((str) { .data = "true", .length = 4 }, allocator);
    }
    else{
      return str$to_string$35((str) { .data = "false", .length = 5 }, allocator);
    }
;
  }
}
void fs$fmt$format_any(any value, fs$fmt$Formatter* formatter) {
  
  if (Type$implements(value._type, (str) { .data = "Format", .length = 6 })) {
    dyn$fs$fmt$Format dyn_format  = fs$fmt$new_dyn_format(value);
    dyn_format.format(dyn_format.instance, formatter);
    return;
  }
;
  
  if ((value._type == ((Type *)(&refl_ty$33)))) {
    
    if (formatter->options.quote_strings) {
      fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "\"", .length = 1 });
    }
;
    fs$fmt$StringBuilder$append$33(formatter->writer, (*(String*)value.ptr));
    
    if (formatter->options.quote_strings) {
      fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "\"", .length = 1 });
    }
;
  }
  else

  if ((value._type == ((Type *)(&refl_ty$32)))) {
    
    if (formatter->options.quote_strings) {
      fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "\"", .length = 1 });
    }
;
    fs$fmt$StringBuilder$append$32(formatter->writer, (*(str*)value.ptr));
    
    if (formatter->options.quote_strings) {
      fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "\"", .length = 1 });
    }
;
  }
  else

  if (Type$is_pointer(value._type)) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$36(value.ptr,formatter->options,get_global_allocator()));
  }
  else

  if (Type$is_struct(value._type)) {
    fs$fmt$format_struct(value,formatter);
  }
  else

  if (Type$is_tuple(value._type)) {
    fs$fmt$format_tuple(value,formatter);
  }
  else

  if ((value.ptr == NULL)) {
    fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "null", .length = 4 });
  }
  else

  if ((value._type == ((Type *)(&refl_ty$29)))) {
    fs$fmt$StringBuilder$append$33(formatter->writer, String$from_ptr(any$unwrap$29(&value)));
  }
  else

  if (Type$is_flags_enum(value._type)) {
    
    if (formatter->options.typename) {
      fs$fmt$StringBuilder$append$32(formatter->writer, value._type->name);
      fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "::(", .length = 3 });
    }
;
    s32 input_value  = any$unwrap$1(&value);
    bool found_any  = false;
    {
      List$449 $iterable = value._type->fields;
      Iter$449 $iterator = List$449$iter(&$iterable);


      for (auto $next = Iter$449$next(&$iterator);
$next.index != 1; $next = Iter$449$next(&$iterator)) {
      Field field = $next.Some.$0;
      {
        
        if ((input_value & field.enum_value)) {
          
          if (found_any) {
            fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = " | ", .length = 3 });
          }
;
          fs$fmt$StringBuilder$append$32(formatter->writer, field.name);
          (found_any = true);
        }
;
      }
    }
  }
  
  if ((!found_any)) {
    fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "invalid flags enum value)", .length = 25 });
    return;
  }
  else{
    fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = ")", .length = 1 });
  }
;
}
else

if (Type$is_enum(value._type)) {
  
  if (formatter->options.typename) {
    fs$fmt$StringBuilder$append$32(formatter->writer, value._type->name);
    fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "::", .length = 2 });
  }
;
  s32 val  = any$unwrap$1(&value);
  {
    List$449 $iterable = value._type->fields;
    Iter$449 $iterator = List$449$iter(&$iterable);


    for (auto $next = Iter$449$next(&$iterator);
$next.index != 1; $next = Iter$449$next(&$iterator)) {
    Field field = $next.Some.$0;
    {
      
      if ((field.enum_value == val)) {
        fs$fmt$StringBuilder$append$32(formatter->writer, field.name);
        return;
      }
;
    }
  }
}
fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "(invalid enum value)", .length = 20 });
}
else{
    Type* $switch_target$6 = value._type;
  if ($switch_target$6 == ((Type *)(&refl_ty$7))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$7(any$unwrap$7(&value),formatter->options,get_global_allocator()));
  }
  else   if ($switch_target$6 == ((Type *)(&refl_ty$6))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$6(any$unwrap$6(&value),formatter->options,get_global_allocator()));
  }
  else   if ($switch_target$6 == ((Type *)(&refl_ty$5))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$5(any$unwrap$5(&value),formatter->options,get_global_allocator()));
  }
  else   if ($switch_target$6 == ((Type *)(&refl_ty$4))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$4(any$unwrap$4(&value),formatter->options,get_global_allocator()));
  }
  else   if ($switch_target$6 == ((Type *)(&refl_ty$3))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$3(any$unwrap$3(&value),formatter->options,get_global_allocator()));
  }
  else   if ($switch_target$6 == ((Type *)(&refl_ty$2))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$2(any$unwrap$2(&value),formatter->options,get_global_allocator()));
  }
  else   if ($switch_target$6 == ((Type *)(&refl_ty$1))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$1(any$unwrap$1(&value),formatter->options,get_global_allocator()));
  }
  else   if ($switch_target$6 == ((Type *)(&refl_ty$0))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$0(any$unwrap$0(&value),formatter->options,get_global_allocator()));
  }
  else   if ($switch_target$6 == ((Type *)(&refl_ty$9))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$9(any$unwrap$9(&value),formatter->options,get_global_allocator()));
  }
  else   if ($switch_target$6 == ((Type *)(&refl_ty$8))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$8(any$unwrap$8(&value),formatter->options,get_global_allocator()));
  }
  else   if ($switch_target$6 == ((Type *)(&refl_ty$10))) {
    fs$fmt$StringBuilder$append_then_free$33(formatter->writer, fs$fmt$to_string$10(any$unwrap$10(&value),formatter->options,get_global_allocator()));
  }
else {
{
    fs$fmt$StringBuilder$append$32(formatter->writer, (str) { .data = "$$(unsupported fmt _type)$$", .length = 27 });
  }
}
;
}
;
}
typedef struct $tuple35 {
  dyn$Allocator $0;
} $tuple35;
typedef struct Option$35 Option$35;
typedef $tuple35 Option$35$Some;
typedef struct Option$35 {
  int index;
  union {
    Option$35$Some Some;
  };
} Option$35;
static inline Option$35 Some$35(dyn$Allocator t) {
  return (Option$35) {
.index = 2,
.Some = ($tuple35) {.$0 = t}};
}
static inline Option$35 None$1350() {
  return  (Option$35) { .index = 1};
}
static inline u64 fs$fmt$StringBuilder$length(fs$fmt$StringBuilder* self) {
  
  if ((!self->root)) {
    return 0;
  }
;
  fs$fmt$StringBuilderBlock* current  = self->root;
  u64 len  = (u64){0};
  while (current) {
    (len += current->length);
    (current = current->next);
  }
  return len;
}
dyn$Allocator Option$35$unwrap(Option$35 self) {
    Option$35 $switch_target$7 = self;
if ($switch_target$7.index == 2) {
dyn$Allocator v = ($switch_target$7.Some.$0);
{
    return v;
  }
}
else {
{
    panic((str) { .data = "unwrapped a 'none' option", .length = 25 });
  }
}
;
}
static inline String fs$fmt$StringBuilder$get_string(fs$fmt$StringBuilder* self, Option$35 allocator) {
  u64 length  = fs$fmt$StringBuilder$length(self);
  u8* data  = (u8*){0};
  Option$35* $pat_match_target0 = &allocator;
if ($pat_match_target0->index == 1) {
{
    (data = self->allocator.allocate(self->allocator.instance, ((sizeof(u8) * length) + 1)));
  }
}
  else{
    (data = Option$35$unwrap(allocator).allocate(Option$35$unwrap(allocator).instance, ((sizeof(u8) * length) + 1)));
  }
;
  (data[length] = 0x0);
  fs$fmt$StringBuilderBlock* current  = self->root;
  s32 offset  = 0;
  while (current) {
    memcpy((data + offset),current->data,current->length);
    (offset += current->length);
    (current = current->next);
  }
  return (String)(String){
    .data = (u8*)data,
    .length = (u64)length,};
}
String fs$fmt$format$402(str fmt, $tuple1$1 tuple, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
  
  if ((fmt.length == 0)) {
    String $defer$return$value = (String)(String){};
    return $defer$return$value;
  }
;
  fs$fmt$StringBuilder builder  = (fs$fmt$StringBuilder)(fs$fmt$StringBuilder){
    .allocator = (dyn$Allocator)allocator,
    .block_size = (u64)8192,};
  fs$fmt$Formatter formatter  = (fs$fmt$Formatter)(fs$fmt$Formatter){
    .writer = (fs$fmt$StringBuilder*)(&builder),
    .indentation = (u32)0,
    .options = (fs$fmt$FormatOptions)options,};
{
    s32 value_index  = 0;
    List$449 fields  = ((Type *)(&refl_ty$402))->fields;
    
    if (List$449$is_empty(fields)) {
      return str$to_string$35((str) { .data = "()", .length = 2 }, allocator);
    }
;
    while ((*fmt.data)) {
      
      if ((((*fmt.data) == 0x5c) && ((*(fmt.data + 1)) == 0x25))) {
        fs$fmt$StringBuilder$append$5(formatter.writer, 0x25);
        (fmt.data += 2);
        continue;
      }
;
      
      if ((((*fmt.data) == 0x25) && (value_index >= fields.length))) {
        panic((str) { .data = "too few data arguments provided to 'format'", .length = 43 });
      }
;
      
      if ((((*fmt.data) == 0x25) && (value_index < fields.length))) {
        Field field  = (*(List$449$index(&fields, value_index)));
        any value  = (any)(any){
          .ptr = (void*)Field$get$402(&field, (&tuple)),
          ._type = (Type*)field._type,};
        fs$fmt$format_any(value,(&formatter));
        value_index++;
      }
      else{
        fs$fmt$StringBuilder$append$5(formatter.writer, (u32)(*fmt.data));
      }
;
      fmt.data++;
    }
  }
  String $defer$return$value = fs$fmt$StringBuilder$get_string(formatter.writer, Some$35(allocator));
{
    fs$fmt$StringBuilder$destroy(formatter.writer, true);
  }
  return $defer$return$value;
{
    fs$fmt$StringBuilder$destroy(formatter.writer, true);
  }
}
void fs$fmt$StringBuilder$appendf$402(fs$fmt$StringBuilder* self, str fmt, $tuple1$1 values, fs$fmt$FormatOptions options) {
  String formatted  = fs$fmt$format$402(fmt,values,options,get_global_allocator());
  fs$fmt$StringBuilder$append$33(self, formatted);
  String$destroy(&formatted, true);
}
typedef struct $tuple32$1$4 {
  str $0;
  s32 $1;
  u64 $2;
} $tuple32$1$4;
typedef struct $tuple32$1$4 $tuple32$1$4;
u8* Field$get$2025(Field* self, $tuple32$1$4* source) {
  return ((u8*)source + self->offset);
}
Option$35 Some$35(dyn$Allocator t);
String fs$fmt$format$2025(str fmt, $tuple32$1$4 tuple, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
  
  if ((fmt.length == 0)) {
    String $defer$return$value = (String)(String){};
    return $defer$return$value;
  }
;
  fs$fmt$StringBuilder builder  = (fs$fmt$StringBuilder)(fs$fmt$StringBuilder){
    .allocator = (dyn$Allocator)allocator,
    .block_size = (u64)8192,};
  fs$fmt$Formatter formatter  = (fs$fmt$Formatter)(fs$fmt$Formatter){
    .writer = (fs$fmt$StringBuilder*)(&builder),
    .indentation = (u32)0,
    .options = (fs$fmt$FormatOptions)options,};
{
    s32 value_index  = 0;
    List$449 fields  = ((Type *)(&refl_ty$2025))->fields;
    
    if (List$449$is_empty(fields)) {
      return str$to_string$35((str) { .data = "()", .length = 2 }, allocator);
    }
;
    while ((*fmt.data)) {
      
      if ((((*fmt.data) == 0x5c) && ((*(fmt.data + 1)) == 0x25))) {
        fs$fmt$StringBuilder$append$5(formatter.writer, 0x25);
        (fmt.data += 2);
        continue;
      }
;
      
      if ((((*fmt.data) == 0x25) && (value_index >= fields.length))) {
        panic((str) { .data = "too few data arguments provided to 'format'", .length = 43 });
      }
;
      
      if ((((*fmt.data) == 0x25) && (value_index < fields.length))) {
        Field field  = (*(List$449$index(&fields, value_index)));
        any value  = (any)(any){
          .ptr = (void*)Field$get$2025(&field, (&tuple)),
          ._type = (Type*)field._type,};
        fs$fmt$format_any(value,(&formatter));
        value_index++;
      }
      else{
        fs$fmt$StringBuilder$append$5(formatter.writer, (u32)(*fmt.data));
      }
;
      fmt.data++;
    }
  }
  String $defer$return$value = fs$fmt$StringBuilder$get_string(formatter.writer, Some$35(allocator));
{
    fs$fmt$StringBuilder$destroy(formatter.writer, true);
  }
  return $defer$return$value;
{
    fs$fmt$StringBuilder$destroy(formatter.writer, true);
  }
}
void fs$fmt$StringBuilder$appendf$2025(fs$fmt$StringBuilder* self, str fmt, $tuple32$1$4 values, fs$fmt$FormatOptions options) {
  String formatted  = fs$fmt$format$2025(fmt,values,options,get_global_allocator());
  fs$fmt$StringBuilder$append$33(self, formatted);
  String$destroy(&formatted, true);
}
bool Type$is_float(Type* self) {
  return ((self->flags & TypeFlags$FLOAT) != 0);
}
extern void  glVertexAttribPointer(s32, s64, s32, bool, s64, void*);
bool Type$is_integral(Type* self) {
  return ((self->flags & TypeFlags$INTEGER) != 0);
}
extern void  glVertexAttribIPointer(s32, s32, s32, s64, void*);
typedef struct gl$Mat4 {
  f32 M00;
  f32 M01;
  f32 M02;
  f32 M03;
  f32 M10;
  f32 M11;
  f32 M12;
  f32 M13;
  f32 M20;
  f32 M21;
  f32 M22;
  f32 M23;
  f32 M30;
  f32 M31;
  f32 M32;
  f32 M33;
} gl$Mat4;
typedef struct gl$Vec4 {
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} gl$Vec4;
typedef struct $tuple1$4 {
  s32 $0;
  u64 $1;
} $tuple1$4;
typedef struct $tuple1$4 $tuple1$4;
u8* Field$get$2030(Field* self, $tuple1$4* source) {
  return ((u8*)source + self->offset);
}
String fs$fmt$format$2030(str fmt, $tuple1$4 tuple, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
  
  if ((fmt.length == 0)) {
    String $defer$return$value = (String)(String){};
    return $defer$return$value;
  }
;
  fs$fmt$StringBuilder builder  = (fs$fmt$StringBuilder)(fs$fmt$StringBuilder){
    .allocator = (dyn$Allocator)allocator,
    .block_size = (u64)8192,};
  fs$fmt$Formatter formatter  = (fs$fmt$Formatter)(fs$fmt$Formatter){
    .writer = (fs$fmt$StringBuilder*)(&builder),
    .indentation = (u32)0,
    .options = (fs$fmt$FormatOptions)options,};
{
    s32 value_index  = 0;
    List$449 fields  = ((Type *)(&refl_ty$2030))->fields;
    
    if (List$449$is_empty(fields)) {
      return str$to_string$35((str) { .data = "()", .length = 2 }, allocator);
    }
;
    while ((*fmt.data)) {
      
      if ((((*fmt.data) == 0x5c) && ((*(fmt.data + 1)) == 0x25))) {
        fs$fmt$StringBuilder$append$5(formatter.writer, 0x25);
        (fmt.data += 2);
        continue;
      }
;
      
      if ((((*fmt.data) == 0x25) && (value_index >= fields.length))) {
        panic((str) { .data = "too few data arguments provided to 'format'", .length = 43 });
      }
;
      
      if ((((*fmt.data) == 0x25) && (value_index < fields.length))) {
        Field field  = (*(List$449$index(&fields, value_index)));
        any value  = (any)(any){
          .ptr = (void*)Field$get$2030(&field, (&tuple)),
          ._type = (Type*)field._type,};
        fs$fmt$format_any(value,(&formatter));
        value_index++;
      }
      else{
        fs$fmt$StringBuilder$append$5(formatter.writer, (u32)(*fmt.data));
      }
;
      fmt.data++;
    }
  }
  String $defer$return$value = fs$fmt$StringBuilder$get_string(formatter.writer, Some$35(allocator));
{
    fs$fmt$StringBuilder$destroy(formatter.writer, true);
  }
  return $defer$return$value;
{
    fs$fmt$StringBuilder$destroy(formatter.writer, true);
  }
}
void fs$fmt$StringBuilder$appendf$2030(fs$fmt$StringBuilder* self, str fmt, $tuple1$4 values, fs$fmt$FormatOptions options) {
  String formatted  = fs$fmt$format$2030(fmt,values,options,get_global_allocator());
  fs$fmt$StringBuilder$append$33(self, formatted);
  String$destroy(&formatted, true);
}
extern void  glEnableVertexAttribArray(s32);
extern void  glVertexAttribDivisor(u32, u32);
typedef struct fs$fmt$FormatOptions fs$fmt$FormatOptions;
fs$fmt$FormatOptions* fs$fmt$FormatOptions$current() {
  static fs$fmt$FormatOptions current  = (fs$fmt$FormatOptions){
.digits_after_decimal = 2,
.indented = false,
.quote_strings = false,
.typename = false,};
  return (&current);
}
typedef struct $tuple32 {
  str $0;
} $tuple32;
typedef struct $tuple32 $tuple32;
u8* Field$get$852(Field* self, $tuple32* source) {
  return ((u8*)source + self->offset);
}
String fs$fmt$format$852(str fmt, $tuple32 tuple, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
  
  if ((fmt.length == 0)) {
    String $defer$return$value = (String)(String){};
    return $defer$return$value;
  }
;
  fs$fmt$StringBuilder builder  = (fs$fmt$StringBuilder)(fs$fmt$StringBuilder){
    .allocator = (dyn$Allocator)allocator,
    .block_size = (u64)8192,};
  fs$fmt$Formatter formatter  = (fs$fmt$Formatter)(fs$fmt$Formatter){
    .writer = (fs$fmt$StringBuilder*)(&builder),
    .indentation = (u32)0,
    .options = (fs$fmt$FormatOptions)options,};
{
    s32 value_index  = 0;
    List$449 fields  = ((Type *)(&refl_ty$852))->fields;
    
    if (List$449$is_empty(fields)) {
      return str$to_string$35((str) { .data = "()", .length = 2 }, allocator);
    }
;
    while ((*fmt.data)) {
      
      if ((((*fmt.data) == 0x5c) && ((*(fmt.data + 1)) == 0x25))) {
        fs$fmt$StringBuilder$append$5(formatter.writer, 0x25);
        (fmt.data += 2);
        continue;
      }
;
      
      if ((((*fmt.data) == 0x25) && (value_index >= fields.length))) {
        panic((str) { .data = "too few data arguments provided to 'format'", .length = 43 });
      }
;
      
      if ((((*fmt.data) == 0x25) && (value_index < fields.length))) {
        Field field  = (*(List$449$index(&fields, value_index)));
        any value  = (any)(any){
          .ptr = (void*)Field$get$852(&field, (&tuple)),
          ._type = (Type*)field._type,};
        fs$fmt$format_any(value,(&formatter));
        value_index++;
      }
      else{
        fs$fmt$StringBuilder$append$5(formatter.writer, (u32)(*fmt.data));
      }
;
      fmt.data++;
    }
  }
  String $defer$return$value = fs$fmt$StringBuilder$get_string(formatter.writer, Some$35(allocator));
{
    fs$fmt$StringBuilder$destroy(formatter.writer, true);
  }
  return $defer$return$value;
{
    fs$fmt$StringBuilder$destroy(formatter.writer, true);
  }
}
void fs$fmt$println$32(str message, fs$fmt$FormatOptions options) {
{
    String formatted  = fs$fmt$format$852((str) { .data = "%", .length = 1 },($tuple32) {.$0 = message},options,get_global_allocator());
    printf("%s\n",formatted.data);
    String$destroy(&formatted, true);
  }
}
GeneralBuffer$1866 GeneralBuffer$1866$new() {
  GeneralBuffer$1866 buffer  = (GeneralBuffer$1866){.descriptor = (String){},};
  glGenVertexArrays(1,(&buffer.vao));
  glGenBuffers(1,(&buffer.vbo));
  Type* the_type  = ((Type *)(&refl_ty$1866));
  u64 stride  = sizeof(Vertex);
  glBindVertexArray(buffer.vao);
  glBindBuffer(gl$GL$ARRAY_BUFFER,buffer.vbo);
  fs$fmt$FormatOptions options  = fs$fmt$FormatOptions$$default();
  fs$fmt$StringBuilder descriptor  = (fs$fmt$StringBuilder){
.allocator = get_global_allocator(),
.block_size = 8192,};
  arena$Arena temp_alloc  = arena$Arena$new(8192,ArenaFlags$Align);
  fs$fmt$StringBuilder$append$32(&descriptor, (str) { .data = "buffer descriptor:\n", .length = 19 });
  fs$fmt$StringBuilder$appendf$402(&descriptor, (str) { .data = "Buffer { vao:   %, vbo:    % }\n", .length = 31 },($tuple1$1) {.$0 = buffer.vao, .$1 = buffer.vbo},options);
  s32 index  = 0;
  {
    List$449 $iterable = the_type->fields;
    Iter$449 $iterator = List$449$iter(&$iterable);


    for (auto $next = Iter$449$next(&$iterator);
$next.index != 1; $next = Iter$449$next(&$iterator)) {
    Field field = $next.Some.$0;
    {
      fs$fmt$StringBuilder$appendf$2025(&descriptor, (str) { .data = "  %s { index: %d, offset: %d }\n", .length = 31 },($tuple32$1$4) {.$0 = field._type->name, .$1 = index, .$2 = field.offset},options);
      
      if (Type$is_float(field._type)) {
        glVertexAttribPointer(index,(s32)field.size,gl$GL$FLOAT,false,stride,(void*)field.offset);
      }
      else

      if (Type$is_integral(field._type)) {
        glVertexAttribIPointer(index,(s32)field.size,gl$GL$INT,stride,(void*)field.offset);
      }
      else

      if ((field._type == ((Type *)(&refl_ty$903)))) {
        {
          RangeBase$1 $iterable = (RangeBase$1) {.begin = 0, .end = 4};
          RangeIter$1 $iterator = RangeBase$1$iter(&$iterable);


          for (auto $next = RangeIter$1$next(&$iterator);
$next.index != 1; $next = RangeIter$1$next(&$iterator)) {
          s32 i = $next.Some.$0;
          {
            u64 offset  = (field.offset + (i * sizeof(gl$Vec4)));
            fs$fmt$StringBuilder$appendf$2030(&descriptor, (str) { .data = "    f32 { index: %, offset: % }\n", .length = 32 },($tuple1$4) {.$0 = index, .$1 = offset},options);
            glVertexAttribPointer(index,4,gl$GL$FLOAT,false,stride,(void*)offset);
            glEnableVertexAttribArray(index);
            glVertexAttribDivisor(index,1);
            (index += 1);
          }
        }
      }
      continue;
    }
    else

    if ((field._type == ((Type *)(&refl_ty$886)))) {
      glVertexAttribPointer(index,4,gl$GL$FLOAT,false,stride,(void*)field.offset);
    }
    else

    if ((field._type == ((Type *)(&refl_ty$890)))) {
      glVertexAttribPointer(index,3,gl$GL$FLOAT,false,stride,(void*)field.offset);
    }
    else

    if ((field._type == ((Type *)(&refl_ty$898)))) {
      glVertexAttribPointer(index,2,gl$GL$FLOAT,false,stride,(void*)field.offset);
    }
    else{
      fs$fmt$println$32((str) { .data = "unsupported type in GeneralBuffer, T can only contain (floats|ints|Vec2|Vec3|Vec4|Mat4)", .length = 87 },(*fs$fmt$FormatOptions$current()));
    }
;
    glEnableVertexAttribArray(index);
    index++;
  }
}
}
(buffer.descriptor = fs$fmt$StringBuilder$get_string(&descriptor, None$1350()));
glBindVertexArray(0);
glBindBuffer(gl$GL$ARRAY_BUFFER,0);
GeneralBuffer$1866 $defer$return$value = buffer;
arena$Arena$destroy(&temp_alloc);
{
  fs$fmt$StringBuilder$destroy(&descriptor, true);
}
return $defer$return$value;
arena$Arena$destroy(&temp_alloc);
{
  fs$fmt$StringBuilder$destroy(&descriptor, true);
}
}
typedef struct $tuple33 {
  String $0;
} $tuple33;
typedef struct $tuple33 $tuple33;
u8* Field$get$1707(Field* self, $tuple33* source) {
  return ((u8*)source + self->offset);
}
String fs$fmt$format$1707(str fmt, $tuple33 tuple, fs$fmt$FormatOptions options, dyn$Allocator allocator) {
  
  if ((fmt.length == 0)) {
    String $defer$return$value = (String)(String){};
    return $defer$return$value;
  }
;
  fs$fmt$StringBuilder builder  = (fs$fmt$StringBuilder)(fs$fmt$StringBuilder){
    .allocator = (dyn$Allocator)allocator,
    .block_size = (u64)8192,};
  fs$fmt$Formatter formatter  = (fs$fmt$Formatter)(fs$fmt$Formatter){
    .writer = (fs$fmt$StringBuilder*)(&builder),
    .indentation = (u32)0,
    .options = (fs$fmt$FormatOptions)options,};
{
    s32 value_index  = 0;
    List$449 fields  = ((Type *)(&refl_ty$1707))->fields;
    
    if (List$449$is_empty(fields)) {
      return str$to_string$35((str) { .data = "()", .length = 2 }, allocator);
    }
;
    while ((*fmt.data)) {
      
      if ((((*fmt.data) == 0x5c) && ((*(fmt.data + 1)) == 0x25))) {
        fs$fmt$StringBuilder$append$5(formatter.writer, 0x25);
        (fmt.data += 2);
        continue;
      }
;
      
      if ((((*fmt.data) == 0x25) && (value_index >= fields.length))) {
        panic((str) { .data = "too few data arguments provided to 'format'", .length = 43 });
      }
;
      
      if ((((*fmt.data) == 0x25) && (value_index < fields.length))) {
        Field field  = (*(List$449$index(&fields, value_index)));
        any value  = (any)(any){
          .ptr = (void*)Field$get$1707(&field, (&tuple)),
          ._type = (Type*)field._type,};
        fs$fmt$format_any(value,(&formatter));
        value_index++;
      }
      else{
        fs$fmt$StringBuilder$append$5(formatter.writer, (u32)(*fmt.data));
      }
;
      fmt.data++;
    }
  }
  String $defer$return$value = fs$fmt$StringBuilder$get_string(formatter.writer, Some$35(allocator));
{
    fs$fmt$StringBuilder$destroy(formatter.writer, true);
  }
  return $defer$return$value;
{
    fs$fmt$StringBuilder$destroy(formatter.writer, true);
  }
}
void fs$fmt$println$33(String message, fs$fmt$FormatOptions options) {
{
    String formatted  = fs$fmt$format$1707((str) { .data = "%", .length = 1 },($tuple33) {.$0 = message},options,get_global_allocator());
    printf("%s\n",formatted.data);
    String$destroy(&formatted, true);
  }
}
typedef struct gl$Shader {
  u32 handle;
} gl$Shader;
typedef struct Result$33_32 Result$33_32;
typedef $tuple33 Result$33_32$Ok;
typedef $tuple32 Result$33_32$Err;
typedef struct Result$33_32 {
  int index;
  union {
    Result$33_32$Ok Ok;
    Result$33_32$Err Err;
  };
} Result$33_32;
typedef struct fs$_IO_FILE fs$_IO_FILE;
typedef struct fs$File {
  fs$_IO_FILE* fd;
} fs$File;
typedef struct fs$_IO_FILE fs$_IO_FILE;
extern fs$_IO_FILE*  fopen(u8*, u8*);
void String$resize(String* self, u64 new_size) {
  
  if ((new_size < self->length)) {
    (self->length = new_size);
  }
;
  (self->capacity = new_size);
  String$get_allocator_if_needed(self);
  (self->data = self->allocator.resize(self->allocator.instance, self->data, sizeof(u8), (new_size + 1)));
  (self->data[self->length] = 0);
}
extern s8  fgetc(fs$_IO_FILE*);
const static s32 fs$EOF  = (s32)(-1);
void String$push(String* self, u8 ch) {
  
  if ((self->capacity == 0)) {
    (self->capacity = (256 / 3));
  }
;
  
  if (((!self->data) || ((self->length + 1) >= self->capacity))) {
    String$resize(self, ((self->capacity * 3) + 1));
  }
;
  (self->data[self->length] = ch);
  self->length++;
  (self->data[self->length] = 0x0);
}
extern void  fclose(fs$_IO_FILE*);
Result$33_32 fs$File$read_all$32(str filename_path) {
  Slice$7 filename  = str$as_slice(filename_path);
  fs$_IO_FILE* file  = fopen(filename.data,"r");
  
  if ((!file)) {
    return (Result$33_32) {
.index = 2,
.Err = ($tuple32) {.$0 = (str) { .data = "Couldnt open file", .length = 17 }}};
  }
;
  String string  = (String){};
  String$resize(&string, 1024);
  while (true) {
    s8 c  = fgetc(file);
    
    if ((c == fs$EOF)) {
      break;
    }
;
    String$push(&string, c);
  }
  fclose(file);
  return (Result$33_32) {
.index = 1,
.Ok = ($tuple33) {.$0 = string}};
}
String Result$33_32$unwrap(Result$33_32 self) {
  Result$33_32* $pat_match_target1 = &self;
if ($pat_match_target1->index == 1) {
String ok = ($pat_match_target1->Ok.$0);
{
    return ok;
  }
}
;
  panic((str) { .data = "called 'unwrap' on an Err result", .length = 32 });
  String $default  = (String){};
  return $default;
}
Result$33_32 fs$File$read_all$32(str filename_path);
extern u32  glCreateShader(u32);
extern void  glShaderSource(u32, s32, u8**, s32*);
extern void  glCompileShader(u32);
extern void  glGetShaderiv(u32, u32, s32*);
extern void  glGetShaderInfoLog(u32, s32, s32*, u8*);
u32 gl$Shader$compile(u32 kind, u8* source) {
  u32 shader  = glCreateShader(kind);
  glShaderSource(shader,1,(&source),NULL);
  glCompileShader(shader);
  s32 success  = (s32){0};
  glGetShaderiv(shader,gl$GL$COMPILE_STATUS,(&success));
  
  if ((success == 0)) {
    s32 length  = (s32){0};
    glGetShaderiv(shader,gl$GL$INFO_LOG_LENGTH,(&length));
    u8* info_log  = malloc((sizeof(u8*) * length));
    glGetShaderInfoLog(shader,length,(&length),info_log);
    std$printf((str) { .data = "Shader compilation failed: %s\n", .length = 30 },info_log);
    free(info_log);
    return 0;
  }
;
  return shader;
}
extern u32  glCreateProgram();
extern void  glAttachShader(u32, u32);
extern void  glLinkProgram(u32);
extern void  glGetProgramiv(u32, u32, s32*);
extern void  glGetProgramInfoLog(u32, s32, s32*, u8*);
extern void  glDeleteShader(s32);
u32 gl$Shader$compile_program(u8* vert_source, u8* frag_source) {
  u32 vertex_shader  = gl$Shader$compile(gl$GL$VERTEX_SHADER,vert_source);
  u32 fragment_shader  = gl$Shader$compile(gl$GL$FRAGMENT_SHADER,frag_source);
  
  if (((vertex_shader == 0) || (fragment_shader == 0))) {
    return (u32)0;
  }
;
  u32 program  = glCreateProgram();
  glAttachShader(program,vertex_shader);
  glAttachShader(program,fragment_shader);
  glLinkProgram(program);
  s32 success  = (s32){0};
  glGetProgramiv(program,gl$GL$LINK_STATUS,(&success));
  
  if ((success == 0)) {
    s32 length  = (s32){0};
    glGetProgramiv(program,gl$GL$INFO_LOG_LENGTH,(&length));
    u8* info_log  = malloc((sizeof(u8*) * length));
    glGetProgramInfoLog(program,length,(&length),info_log);
    std$printf((str) { .data = "Program linking failed: %s\n", .length = 27 },info_log);
    free(info_log);
    return (u32)0;
  }
;
  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
  return program;
}
gl$Shader gl$Shader$create(String vertexSource, String fragSource) {
  return (gl$Shader)(gl$Shader){
    .handle = (u32)gl$Shader$compile_program(vertexSource.data,fragSource.data),};
}
typedef struct gl$Shader gl$Shader;
extern void  glUseProgram(u32);
void gl$Shader$use(gl$Shader* self) {
  glUseProgram(self->handle);
}
typedef struct List$5 {
  u32* data;
  u64 length;
  u64 capacity;
  dyn$Allocator allocator;
} List$5;
extern void  glfwSetWindowUserPointer(gl$GLFWwindow*, void*);
extern void*  glfwGetWindowUserPointer(gl$GLFWwindow*);
typedef enum: u32 {
  gl$GLFW$KEY_UNKNOWN = (s32)(-1),
  gl$GLFW$KEY_SPACE = 32,
  gl$GLFW$KEY_APOSTROPHE = 39,
  gl$GLFW$KEY_COMMA = 44,
  gl$GLFW$KEY_MINUS = 45,
  gl$GLFW$KEY_PERIOD = 46,
  gl$GLFW$KEY_SLASH = 47,
  gl$GLFW$KEY_0 = 48,
  gl$GLFW$KEY_1 = 49,
  gl$GLFW$KEY_2 = 50,
  gl$GLFW$KEY_3 = 51,
  gl$GLFW$KEY_4 = 52,
  gl$GLFW$KEY_5 = 53,
  gl$GLFW$KEY_6 = 54,
  gl$GLFW$KEY_7 = 55,
  gl$GLFW$KEY_8 = 56,
  gl$GLFW$KEY_9 = 57,
  gl$GLFW$KEY_SEMICOLON = 59,
  gl$GLFW$KEY_EQUAL = 61,
  gl$GLFW$KEY_A = 65,
  gl$GLFW$KEY_B = 66,
  gl$GLFW$KEY_C = 67,
  gl$GLFW$KEY_D = 68,
  gl$GLFW$KEY_E = 69,
  gl$GLFW$KEY_F = 70,
  gl$GLFW$KEY_G = 71,
  gl$GLFW$KEY_H = 72,
  gl$GLFW$KEY_I = 73,
  gl$GLFW$KEY_J = 74,
  gl$GLFW$KEY_K = 75,
  gl$GLFW$KEY_L = 76,
  gl$GLFW$KEY_M = 77,
  gl$GLFW$KEY_N = 78,
  gl$GLFW$KEY_O = 79,
  gl$GLFW$KEY_P = 80,
  gl$GLFW$KEY_Q = 81,
  gl$GLFW$KEY_R = 82,
  gl$GLFW$KEY_S = 83,
  gl$GLFW$KEY_T = 84,
  gl$GLFW$KEY_U = 85,
  gl$GLFW$KEY_V = 86,
  gl$GLFW$KEY_W = 87,
  gl$GLFW$KEY_X = 88,
  gl$GLFW$KEY_Y = 89,
  gl$GLFW$KEY_Z = 90,
  gl$GLFW$KEY_LEFT_BRACKET = 91,
  gl$GLFW$KEY_BACKSLASH = 92,
  gl$GLFW$KEY_RIGHT_BRACKET = 93,
  gl$GLFW$KEY_GRAVE_ACCENT = 96,
  gl$GLFW$KEY_WORLD_1 = 161,
  gl$GLFW$KEY_WORLD_2 = 162,
  gl$GLFW$KEY_ESCAPE = 256,
  gl$GLFW$KEY_ENTER = 257,
  gl$GLFW$KEY_TAB = 258,
  gl$GLFW$KEY_BACKSPACE = 259,
  gl$GLFW$KEY_INSERT = 260,
  gl$GLFW$KEY_DELETE = 261,
  gl$GLFW$KEY_RIGHT = 262,
  gl$GLFW$KEY_LEFT = 263,
  gl$GLFW$KEY_DOWN = 264,
  gl$GLFW$KEY_UP = 265,
  gl$GLFW$KEY_PAGE_UP = 266,
  gl$GLFW$KEY_PAGE_DOWN = 267,
  gl$GLFW$KEY_HOME = 268,
  gl$GLFW$KEY_END = 269,
  gl$GLFW$KEY_CAPS_LOCK = 280,
  gl$GLFW$KEY_SCROLL_LOCK = 281,
  gl$GLFW$KEY_NUM_LOCK = 282,
  gl$GLFW$KEY_PRINT_SCREEN = 283,
  gl$GLFW$KEY_PAUSE = 284,
  gl$GLFW$KEY_F1 = 290,
  gl$GLFW$KEY_F2 = 291,
  gl$GLFW$KEY_F3 = 292,
  gl$GLFW$KEY_F4 = 293,
  gl$GLFW$KEY_F5 = 294,
  gl$GLFW$KEY_F6 = 295,
  gl$GLFW$KEY_F7 = 296,
  gl$GLFW$KEY_F8 = 297,
  gl$GLFW$KEY_F9 = 298,
  gl$GLFW$KEY_F10 = 299,
  gl$GLFW$KEY_F11 = 300,
  gl$GLFW$KEY_F12 = 301,
  gl$GLFW$KEY_F13 = 302,
  gl$GLFW$KEY_F14 = 303,
  gl$GLFW$KEY_F15 = 304,
  gl$GLFW$KEY_F16 = 305,
  gl$GLFW$KEY_F17 = 306,
  gl$GLFW$KEY_F18 = 307,
  gl$GLFW$KEY_F19 = 308,
  gl$GLFW$KEY_F20 = 309,
  gl$GLFW$KEY_F21 = 310,
  gl$GLFW$KEY_F22 = 311,
  gl$GLFW$KEY_F23 = 312,
  gl$GLFW$KEY_F24 = 313,
  gl$GLFW$KEY_F25 = 314,
  gl$GLFW$KEY_KP_0 = 320,
  gl$GLFW$KEY_KP_1 = 321,
  gl$GLFW$KEY_KP_2 = 322,
  gl$GLFW$KEY_KP_3 = 323,
  gl$GLFW$KEY_KP_4 = 324,
  gl$GLFW$KEY_KP_5 = 325,
  gl$GLFW$KEY_KP_6 = 326,
  gl$GLFW$KEY_KP_7 = 327,
  gl$GLFW$KEY_KP_8 = 328,
  gl$GLFW$KEY_KP_9 = 329,
  gl$GLFW$KEY_KP_DECIMAL = 330,
  gl$GLFW$KEY_KP_DIVIDE = 331,
  gl$GLFW$KEY_KP_MULTIPLY = 332,
  gl$GLFW$KEY_KP_SUBTRACT = 333,
  gl$GLFW$KEY_KP_ADD = 334,
  gl$GLFW$KEY_KP_ENTER = 335,
  gl$GLFW$KEY_KP_EQUAL = 336,
  gl$GLFW$KEY_LEFT_SHIFT = 340,
  gl$GLFW$KEY_LEFT_CONTROL = 341,
  gl$GLFW$KEY_LEFT_ALT = 342,
  gl$GLFW$KEY_LEFT_SUPER = 343,
  gl$GLFW$KEY_RIGHT_SHIFT = 344,
  gl$GLFW$KEY_RIGHT_CONTROL = 345,
  gl$GLFW$KEY_RIGHT_ALT = 346,
  gl$GLFW$KEY_RIGHT_SUPER = 347,
  gl$GLFW$KEY_MENU = 348,
  gl$GLFW$MOD_SHIFT = 0x0001,
  gl$GLFW$MOD_CONTROL = 0x0002,
  gl$GLFW$MOD_ALT = 0x0004,
  gl$GLFW$MOD_SUPER = 0x0008,
  gl$GLFW$MOD_CAPS_LOCK = 0x0010,
  gl$GLFW$MOD_NUM_LOCK = 0x0020,
  gl$GLFW$PRESS = 1,
  gl$GLFW$RELEASE = 0,
  gl$GLFW$REPEAT = 2
} gl$GLFW;
static inline void List$5$get_allocator_if_needed(List$5* self) {
  
  if ((!dyn$Allocator$has_instance(self->allocator))) {
    (self->allocator = get_global_allocator());
  }
;
}
static inline void List$5$resize(List$5* self, u64 new_capacity) {
  
  if (((new_capacity < self->capacity) && (new_capacity < self->length))) {
    (self->length = new_capacity);
  }
;
  (self->capacity = new_capacity);
  List$5$get_allocator_if_needed(self);
  (self->data = self->allocator.resize(self->allocator.instance, self->data, sizeof(u32), self->capacity));
}
static inline void List$5$push(List$5* self, u32 v) {
  
  if (((self->length + 1) >= self->capacity)) {
    
    if ((self->capacity == 0)) {
      (self->capacity = 4);
    }
;
    List$5$resize(self, (self->capacity * 2));
  }
;
  (self->data[self->length] = v);
  self->length++;
}
static inline u32 List$5$pop(List$5* self) {
  u32 value  = self->data[(self->length - 1)];
  (self->length -= 1);
  return value;
}
void $lambda$7 (gl$GLFWwindow* window, s32 key, s32 scancode, s32 action, s32 mod)
{
  List$5* data  = glfwGetWindowUserPointer(window);
  
  if ((((action == gl$GLFW$PRESS) && (key == gl$GLFW$KEY_C)) && (mod & gl$GLFW$MOD_CONTROL))) {
    glfwTerminate();
  }
;
  
  if (((action == gl$GLFW$PRESS) || (action == gl$GLFW$REPEAT))) {
    
    if (((key >= gl$GLFW$KEY_A) && (key <= gl$GLFW$KEY_Z))) {
      
      if ((mod & gl$GLFW$MOD_SHIFT)) {
        List$5$push(data, (u32)key);
      }
      else{
        List$5$push(data, (((u32)key + 0x61) - 0x41));
      }
;
    }
    else

    if (((key >= gl$GLFW$KEY_0) && (key <= gl$GLFW$KEY_9))) {
      
      if ((mod & gl$GLFW$MOD_SHIFT)) {
                s32 $switch_target$8 = key;
        if ($switch_target$8 == gl$GLFW$KEY_1) {
          return List$5$push(data, 0x21);
        }
        else         if ($switch_target$8 == gl$GLFW$KEY_2) {
          return List$5$push(data, 0x40);
        }
        else         if ($switch_target$8 == gl$GLFW$KEY_3) {
          return List$5$push(data, 0x23);
        }
        else         if ($switch_target$8 == gl$GLFW$KEY_4) {
          return List$5$push(data, 0x24);
        }
        else         if ($switch_target$8 == gl$GLFW$KEY_5) {
          return List$5$push(data, 0x25);
        }
        else         if ($switch_target$8 == gl$GLFW$KEY_6) {
          return List$5$push(data, 0x5e);
        }
        else         if ($switch_target$8 == gl$GLFW$KEY_7) {
          return List$5$push(data, 0x26);
        }
        else         if ($switch_target$8 == gl$GLFW$KEY_8) {
          return List$5$push(data, 0x2a);
        }
        else         if ($switch_target$8 == gl$GLFW$KEY_9) {
          return List$5$push(data, 0x28);
        }
        else         if ($switch_target$8 == gl$GLFW$KEY_0) {
          return List$5$push(data, 0x29);
        }
;
      }
      else{
        List$5$push(data, (u32)key);
      }
;
    }
    else{
            s32 $switch_target$9 = key;
      if ($switch_target$9 == gl$GLFW$KEY_BACKSPACE) {
        
        if ((data->length > 0)) {
          List$5$pop(data);
        }
;
      }
      else       if ($switch_target$9 == gl$GLFW$KEY_ENTER) {
        List$5$push(data, 0xa);
      }
      else       if ($switch_target$9 == gl$GLFW$KEY_TAB) {
        List$5$push(data, 0x9);
      }
      else       if ($switch_target$9 == gl$GLFW$KEY_SPACE) {
        List$5$push(data, 0x20);
      }
;
    }
;
  }
;
}

typedef struct gl$Window gl$Window;
extern void(*glfwSetKeyCallback(gl$GLFWwindow*, void(*)(gl$GLFWwindow*, s32, s32, s32, s32)));
void gl$Window$set_key_callback(gl$Window* self, void(*callback)(gl$GLFWwindow*, s32, s32, s32, s32)) {
  glfwSetKeyCallback(self->handle,callback);
}
typedef struct List$1866 List$1866;
typedef struct Cube {
  gl$Vec3 scale;
  gl$Vec3 position;
  gl$Vec3 rotation;
  List$1866* vertices;
} Cube;
typedef struct Vertex Vertex;
typedef struct List$1866 {
  Vertex* data;
  u64 length;
  u64 capacity;
  dyn$Allocator allocator;
} List$1866;
static inline bool List$1866$is_empty(List$1866 self) {
  return (self.length == 0);
}
gl$Vec3 gl$Vec3$new(f32 x, f32 y, f32 z) {
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)x,
    .y = (f32)y,
    .z = (f32)z,};
}
gl$Vec2 gl$Vec2$new(f32 x, f32 y) {
  return (gl$Vec2)(gl$Vec2){
    .x = (f32)x,
    .y = (f32)y,};
}
Vertex Vertex$new(gl$Vec3 position, gl$Vec3 normal, gl$Vec2 texcoord) {
  return (Vertex)(Vertex){
    .position = (gl$Vec3)position,
    .normal = (gl$Vec3)normal,
    .texcoord = (gl$Vec2)texcoord,};
}
typedef struct InitList$1866 {
  Vertex* data;
  u64 length;
} InitList$1866;
static inline void List$1866$get_allocator_if_needed(List$1866* self) {
  
  if ((!dyn$Allocator$has_instance(self->allocator))) {
    (self->allocator = get_global_allocator());
  }
;
}
static inline void List$1866$resize(List$1866* self, u64 new_capacity) {
  
  if (((new_capacity < self->capacity) && (new_capacity < self->length))) {
    (self->length = new_capacity);
  }
;
  (self->capacity = new_capacity);
  List$1866$get_allocator_if_needed(self);
  (self->data = self->allocator.resize(self->allocator.instance, self->data, sizeof(Vertex), self->capacity));
}
static inline List$1866 List$1866$init(InitList$1866 init) {
  List$1866 self  = (List$1866){};
  List$1866$resize(&self, init.length);
  memcpy(self.data,init.data,(sizeof(Vertex) * init.length));
  (self.length = init.length);
  return self;
}
List$1866 cube(f32 scale) {
  return List$1866$init((InitList$1866){ .data = (Vertex[]) {Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(f32)(-(scale / 2)),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,0.0f,(f32)(-scale)),gl$Vec2$new(0.0f,0.0f)), Vertex$new(gl$Vec3$new((scale / 2),(f32)(-(scale / 2)),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,0.0f,(f32)(-scale)),gl$Vec2$new(scale,0.0f)), Vertex$new(gl$Vec3$new((scale / 2),(scale / 2),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,0.0f,(f32)(-scale)),gl$Vec2$new(scale,scale)), Vertex$new(gl$Vec3$new((scale / 2),(scale / 2),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,0.0f,(f32)(-scale)),gl$Vec2$new(scale,scale)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(scale / 2),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,0.0f,(f32)(-scale)),gl$Vec2$new(0.0f,scale)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(f32)(-(scale / 2)),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,0.0f,(f32)(-scale)),gl$Vec2$new(0.0f,0.0f)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(f32)(-(scale / 2)),(scale / 2)),gl$Vec3$new(0.0f,0.0f,scale),gl$Vec2$new(0.0f,0.0f)), Vertex$new(gl$Vec3$new((scale / 2),(f32)(-(scale / 2)),(scale / 2)),gl$Vec3$new(0.0f,0.0f,scale),gl$Vec2$new(scale,0.0f)), Vertex$new(gl$Vec3$new((scale / 2),(scale / 2),(scale / 2)),gl$Vec3$new(0.0f,0.0f,scale),gl$Vec2$new(scale,scale)), Vertex$new(gl$Vec3$new((scale / 2),(scale / 2),(scale / 2)),gl$Vec3$new(0.0f,0.0f,scale),gl$Vec2$new(scale,scale)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(scale / 2),(scale / 2)),gl$Vec3$new(0.0f,0.0f,scale),gl$Vec2$new(0.0f,scale)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(f32)(-(scale / 2)),(scale / 2)),gl$Vec3$new(0.0f,0.0f,scale),gl$Vec2$new(0.0f,0.0f)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(scale / 2),(scale / 2)),gl$Vec3$new((f32)(-scale),0.0f,0.0f),gl$Vec2$new(scale,0.0f)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(scale / 2),(f32)(-(scale / 2))),gl$Vec3$new((f32)(-scale),0.0f,0.0f),gl$Vec2$new(scale,scale)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(f32)(-(scale / 2)),(f32)(-(scale / 2))),gl$Vec3$new((f32)(-scale),0.0f,0.0f),gl$Vec2$new(0.0f,scale)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(f32)(-(scale / 2)),(f32)(-(scale / 2))),gl$Vec3$new((f32)(-scale),0.0f,0.0f),gl$Vec2$new(0.0f,scale)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(f32)(-(scale / 2)),(scale / 2)),gl$Vec3$new((f32)(-scale),0.0f,0.0f),gl$Vec2$new(0.0f,0.0f)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(scale / 2),(scale / 2)),gl$Vec3$new((f32)(-scale),0.0f,0.0f),gl$Vec2$new(scale,0.0f)), Vertex$new(gl$Vec3$new((scale / 2),(scale / 2),(scale / 2)),gl$Vec3$new(scale,0.0f,0.0f),gl$Vec2$new(scale,0.0f)), Vertex$new(gl$Vec3$new((scale / 2),(scale / 2),(f32)(-(scale / 2))),gl$Vec3$new(scale,0.0f,0.0f),gl$Vec2$new(scale,scale)), Vertex$new(gl$Vec3$new((scale / 2),(f32)(-(scale / 2)),(f32)(-(scale / 2))),gl$Vec3$new(scale,0.0f,0.0f),gl$Vec2$new(0.0f,scale)), Vertex$new(gl$Vec3$new((scale / 2),(f32)(-(scale / 2)),(f32)(-(scale / 2))),gl$Vec3$new(scale,0.0f,0.0f),gl$Vec2$new(0.0f,scale)), Vertex$new(gl$Vec3$new((scale / 2),(f32)(-(scale / 2)),(scale / 2)),gl$Vec3$new(scale,0.0f,0.0f),gl$Vec2$new(0.0f,0.0f)), Vertex$new(gl$Vec3$new((scale / 2),(scale / 2),(scale / 2)),gl$Vec3$new(scale,0.0f,0.0f),gl$Vec2$new(scale,0.0f)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(f32)(-(scale / 2)),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,(f32)(-scale),0.0f),gl$Vec2$new(0.0f,scale)), Vertex$new(gl$Vec3$new((scale / 2),(f32)(-(scale / 2)),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,(f32)(-scale),0.0f),gl$Vec2$new(scale,scale)), Vertex$new(gl$Vec3$new((scale / 2),(f32)(-(scale / 2)),(scale / 2)),gl$Vec3$new(0.0f,(f32)(-scale),0.0f),gl$Vec2$new(scale,0.0f)), Vertex$new(gl$Vec3$new((scale / 2),(f32)(-(scale / 2)),(scale / 2)),gl$Vec3$new(0.0f,(f32)(-scale),0.0f),gl$Vec2$new(scale,0.0f)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(f32)(-(scale / 2)),(scale / 2)),gl$Vec3$new(0.0f,(f32)(-scale),0.0f),gl$Vec2$new(0.0f,0.0f)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(f32)(-(scale / 2)),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,(f32)(-scale),0.0f),gl$Vec2$new(0.0f,scale)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(scale / 2),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,scale,0.0f),gl$Vec2$new(0.0f,scale)), Vertex$new(gl$Vec3$new((scale / 2),(scale / 2),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,scale,0.0f),gl$Vec2$new(scale,scale)), Vertex$new(gl$Vec3$new((scale / 2),(scale / 2),(scale / 2)),gl$Vec3$new(0.0f,scale,0.0f),gl$Vec2$new(scale,0.0f)), Vertex$new(gl$Vec3$new((scale / 2),(scale / 2),(scale / 2)),gl$Vec3$new(0.0f,scale,0.0f),gl$Vec2$new(scale,0.0f)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(scale / 2),(scale / 2)),gl$Vec3$new(0.0f,scale,0.0f),gl$Vec2$new(0.0f,0.0f)), Vertex$new(gl$Vec3$new((f32)(-(scale / 2)),(scale / 2),(f32)(-(scale / 2))),gl$Vec3$new(0.0f,scale,0.0f),gl$Vec2$new(0.0f,scale))}, .length = 36});
}
Cube Cube$new(f32 scale) {
  static List$1866 vertices  = (List$1866){};
  
  if (List$1866$is_empty(vertices)) {
    (vertices = cube(1.0f));
  }
;
  return (Cube)(Cube){
    .scale = (gl$Vec3)gl$Vec3$new(scale,scale,scale),
    .position = (gl$Vec3)(gl$Vec3)(gl$Vec3){},
    .rotation = (gl$Vec3)(gl$Vec3)(gl$Vec3){},
    .vertices = (List$1866*)(&vertices),};
}
typedef struct Cube Cube;
void Cube$set_position(Cube* self, gl$Vec3 position) {
  (self->position = position);
}
typedef struct gl$Camera {
  gl$Vec3 position;
  gl$Vec3 target;
  gl$Vec3 up;
  f32 fov;
  f32 aspect_ratio;
  f32 near;
  f32 far;
  gl$Mat4 view;
  gl$Mat4 projection;
} gl$Camera;
gl$Vec3 gl$Vec3$up() {
  static gl$Vec3 up  = (gl$Vec3)(gl$Vec3){
    .x = (f32)0,
    .y = (f32)1,
    .z = (f32)0,};
  return up;
}
gl$Vec3 gl$Vec3$zero() {
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)0.0f,
    .y = (f32)0.0f,
    .z = (f32)0.0f,};
}
gl$Camera gl$Camera$new(gl$Vec3 up, f32 fov, f32 aspect, f32 near, f32 far) {
  return (gl$Camera)(gl$Camera){
    .position = (gl$Vec3)gl$Vec3$zero(),
    .target = (gl$Vec3)gl$Vec3$zero(),
    .up = (gl$Vec3)up,
    .fov = (f32)fov,
    .aspect_ratio = (f32)aspect,
    .near = (f32)near,
    .far = (f32)far,.view = (gl$Mat4){},.projection = (gl$Mat4){},};
}
typedef struct gl$Vec3 gl$Vec3;
extern s32  glGetUniformLocation(u32, u8*);
extern void  glUniform3fv(s32, s32, f32*);
void gl$Shader$set_vec3(gl$Shader* self, str name, gl$Vec3* v) {
  s32 index  = glGetUniformLocation(self->handle,name.data);
  
  if ((index != (s32)(-1))) {
    glUniform3fv(index,1,(f32*)v);
  }
  else{
    std$printf((str) { .data = "failed to get uniform : %s\n", .length = 27 },name.data);
  }
;
}
void gl$Shader$set$890(gl$Shader* self, str name, gl$Vec3 v) {
{
    gl$Shader$set_vec3(self, name,(gl$Vec3*)(&v));
  }
}
void gl$Shader$set$890(gl$Shader* self, str name, gl$Vec3 v);
extern void  glUniform1f(s32, f32);
void gl$Shader$set_float(gl$Shader* self, str name, f32 v) {
  s32 index  = glGetUniformLocation(self->handle,name.data);
  
  if ((index != (s32)(-1))) {
    glUniform1f(index,v);
  }
  else{
    std$printf((str) { .data = "failed to get uniform : %s\n", .length = 27 },name.data);
  }
;
}
void gl$Shader$set$9(gl$Shader* self, str name, f32 v) {
{
    gl$Shader$set_float(self, name,(*(f32*)(&v)));
  }
}
typedef struct Slice$1866 {
  Vertex* data;
  u64 length;
} Slice$1866;
Slice$1866 List$1866$as_slice(List$1866 self) {
  return (Slice$1866)(Slice$1866){
    .data = (Vertex*)self.data,
    .length = (u64)self.length,};
}
Slice$1866 Slice$1866$slice$81(Slice$1866 self, RangeBase$1 range) {
  
  if ((range.begin < 0)) {
    (range.begin = 0);
  }
;
  
  if (((range.end == (s32)(-1)) || (range.end > self.length))) {
    (range.end = self.length);
  }
;
  s32 length  = (range.end - range.begin);
  
  if ((length < 0)) {
    return (Slice$1866)(Slice$1866){};
  }
;
  return (Slice$1866)(Slice$1866){
    .data = (Vertex*)(self.data + range.begin),
    .length = (u64)length,};
}
Slice$1866 Cube$vertex_slice(Cube self) {
  return Slice$1866$slice$81(List$1866$as_slice(*self.vertices), (RangeBase$1) {.begin = 0, .end = self.vertices->length});
}
extern void  glBufferData(s32, s64, void*, s32);
void GeneralBuffer$1866$bind_and_buffer_data(GeneralBuffer$1866 self, Slice$1866 slice) {
  glBindVertexArray(self.vao);
  glBindBuffer(gl$GL$ARRAY_BUFFER,self.vbo);
  glBufferData(gl$GL$ARRAY_BUFFER,(sizeof(Vertex) * slice.length),slice.data,gl$GL$STATIC_DRAW);
}
extern s32  glfwWindowShouldClose(gl$GLFWwindow*);
bool gl$Window$should_close(gl$Window* self) {
  return (bool)glfwWindowShouldClose(self->handle);
}
gl$Vec3 gl$Vec3$add(gl$Vec3 self, gl$Vec3 other) {
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)(self.x + other.x),
    .y = (f32)(self.y + other.y),
    .z = (f32)(self.z + other.z),};
}
gl$Mat4 gl$Mat4$identity() {
  gl$Mat4 matrix  = (gl$Mat4){};
  (matrix.M00 = 1.0f);
  (matrix.M01 = 0.0f);
  (matrix.M02 = 0.0f);
  (matrix.M03 = 0.0f);
  (matrix.M10 = 0.0f);
  (matrix.M11 = 1.0f);
  (matrix.M12 = 0.0f);
  (matrix.M13 = 0.0f);
  (matrix.M20 = 0.0f);
  (matrix.M21 = 0.0f);
  (matrix.M22 = 1.0f);
  (matrix.M23 = 0.0f);
  (matrix.M30 = 0.0f);
  (matrix.M31 = 0.0f);
  (matrix.M32 = 0.0f);
  (matrix.M33 = 1.0f);
  return matrix;
}
gl$Mat4 gl$Mat4$scalar(gl$Vec3 scale) {
  gl$Mat4 matrix  = gl$Mat4$identity();
  (matrix.M00 = scale.x);
  (matrix.M11 = scale.y);
  (matrix.M22 = scale.z);
  return matrix;
}
extern f64  cos(f64);
extern f64  sin(f64);
gl$Mat4 gl$Mat4$rotation(gl$Vec3 rotation) {
  f32 cx  = (f32)cos(rotation.x);
  f32 sx  = (f32)sin(rotation.x);
  f32 cy  = (f32)cos(rotation.y);
  f32 sy  = (f32)sin(rotation.y);
  f32 cz  = (f32)cos(rotation.z);
  f32 sz  = (f32)sin(rotation.z);
  gl$Mat4 matrix  = gl$Mat4$identity();
  (matrix.M00 = (cy * cz));
  (matrix.M01 = ((f32)(-cy) * sz));
  (matrix.M02 = sy);
  (matrix.M10 = (((sx * sy) * cz) + (cx * sz)));
  (matrix.M11 = ((((f32)(-sx) * sy) * sz) + (cx * cz)));
  (matrix.M12 = ((f32)(-sx) * cy));
  (matrix.M20 = ((((f32)(-cx) * sy) * cz) + (sx * sz)));
  (matrix.M21 = (((cx * sy) * sz) + (sx * cz)));
  (matrix.M22 = (cx * cy));
  return matrix;
}
gl$Mat4 gl$Mat4$translation(gl$Vec3 translation) {
  gl$Mat4 matrix  = gl$Mat4$identity();
  (matrix.M03 = translation.x);
  (matrix.M13 = translation.y);
  (matrix.M23 = translation.z);
  return matrix;
}
gl$Mat4 gl$Mat4$mul(gl$Mat4 self, gl$Mat4 other) {
  gl$Mat4 matrix  = (gl$Mat4){};
  (matrix.M00 = ((((self.M00 * other.M00) + (self.M01 * other.M10)) + (self.M02 * other.M20)) + (self.M03 * other.M30)));
  (matrix.M01 = ((((self.M00 * other.M01) + (self.M01 * other.M11)) + (self.M02 * other.M21)) + (self.M03 * other.M31)));
  (matrix.M02 = ((((self.M00 * other.M02) + (self.M01 * other.M12)) + (self.M02 * other.M22)) + (self.M03 * other.M32)));
  (matrix.M03 = ((((self.M00 * other.M03) + (self.M01 * other.M13)) + (self.M02 * other.M23)) + (self.M03 * other.M33)));
  (matrix.M10 = ((((self.M10 * other.M00) + (self.M11 * other.M10)) + (self.M12 * other.M20)) + (self.M13 * other.M30)));
  (matrix.M11 = ((((self.M10 * other.M01) + (self.M11 * other.M11)) + (self.M12 * other.M21)) + (self.M13 * other.M31)));
  (matrix.M12 = ((((self.M10 * other.M02) + (self.M11 * other.M12)) + (self.M12 * other.M22)) + (self.M13 * other.M32)));
  (matrix.M13 = ((((self.M10 * other.M03) + (self.M11 * other.M13)) + (self.M12 * other.M23)) + (self.M13 * other.M33)));
  (matrix.M20 = ((((self.M20 * other.M00) + (self.M21 * other.M10)) + (self.M22 * other.M20)) + (self.M23 * other.M30)));
  (matrix.M21 = ((((self.M20 * other.M01) + (self.M21 * other.M11)) + (self.M22 * other.M21)) + (self.M23 * other.M31)));
  (matrix.M22 = ((((self.M20 * other.M02) + (self.M21 * other.M12)) + (self.M22 * other.M22)) + (self.M23 * other.M32)));
  (matrix.M23 = ((((self.M20 * other.M03) + (self.M21 * other.M13)) + (self.M22 * other.M23)) + (self.M23 * other.M33)));
  (matrix.M30 = ((((self.M30 * other.M00) + (self.M31 * other.M10)) + (self.M32 * other.M20)) + (self.M33 * other.M30)));
  (matrix.M31 = ((((self.M30 * other.M01) + (self.M31 * other.M11)) + (self.M32 * other.M21)) + (self.M33 * other.M31)));
  (matrix.M32 = ((((self.M30 * other.M02) + (self.M31 * other.M12)) + (self.M32 * other.M22)) + (self.M33 * other.M32)));
  (matrix.M33 = ((((self.M30 * other.M03) + (self.M31 * other.M13)) + (self.M32 * other.M23)) + (self.M33 * other.M33)));
  return matrix;
}
gl$Mat4 Cube$matrix(Cube self) {
  return (gl$Mat4$mul((gl$Mat4$mul(gl$Mat4$translation(self.position), gl$Mat4$rotation(self.rotation))), gl$Mat4$scalar(self.scale)));
}
typedef struct gl$Camera gl$Camera;
gl$Vec3 gl$Vec3$sub(gl$Vec3 self, gl$Vec3 other) {
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)(self.x - other.x),
    .y = (f32)(self.y - other.y),
    .z = (f32)(self.z - other.z),};
}
extern f64  sqrt(f64);
f32 gl$math$sqrt$9(f32 f) {
  return (f32)sqrt((f32)f);
}
gl$Vec3 gl$Vec3$normalize(gl$Vec3 self) {
  f32 mag  = (f32)gl$math$sqrt$9((((self.x * self.x) + (self.y * self.y)) + (self.z * self.z)));
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)(self.x / mag),
    .y = (f32)(self.y / mag),
    .z = (f32)(self.z / mag),};
}
gl$Vec3 gl$Vec3$cross(gl$Vec3 self, gl$Vec3 other) {
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)((self.y * other.z) - (self.z * other.y)),
    .y = (f32)((self.z * other.x) - (self.x * other.z)),
    .z = (f32)((self.x * other.y) - (self.y * other.x)),};
}
f32 gl$Vec3$dot(gl$Vec3 self, gl$Vec3 other) {
  return (((self.x * other.x) + (self.y * other.y)) + (self.z * other.z));
}
gl$Mat4 gl$Mat4$look_at(gl$Vec3 eye, gl$Vec3 center, gl$Vec3 up) {
  gl$Vec3 f  = gl$Vec3$normalize((gl$Vec3$sub(center, eye)));
  gl$Vec3 s  = gl$Vec3$normalize(gl$Vec3$cross(f, up));
  gl$Vec3 u  = gl$Vec3$cross(s, f);
  gl$Mat4 matrix  = gl$Mat4$identity();
  (matrix.M00 = s.x);
  (matrix.M01 = s.y);
  (matrix.M02 = s.z);
  (matrix.M10 = u.x);
  (matrix.M11 = u.y);
  (matrix.M12 = u.z);
  (matrix.M20 = (f32)(-f.x));
  (matrix.M21 = (f32)(-f.y));
  (matrix.M22 = (f32)(-f.z));
  (matrix.M30 = (f32)(-gl$Vec3$dot(s, eye)));
  (matrix.M31 = (f32)(-gl$Vec3$dot(u, eye)));
  (matrix.M32 = gl$Vec3$dot(f, eye));
  return matrix;
}
extern f64  tan(f64);
gl$Mat4 gl$Mat4$zero() {
  return (gl$Mat4)(gl$Mat4){
    .M00 = (f32)0.0f,
    .M01 = (f32)0.0f,
    .M02 = (f32)0.0f,
    .M03 = (f32)0.0f,
    .M10 = (f32)0.0f,
    .M11 = (f32)0.0f,
    .M12 = (f32)0.0f,
    .M13 = (f32)0.0f,
    .M20 = (f32)0.0f,
    .M21 = (f32)0.0f,
    .M22 = (f32)0.0f,
    .M23 = (f32)0.0f,
    .M30 = (f32)0.0f,
    .M31 = (f32)0.0f,
    .M32 = (f32)0.0f,
    .M33 = (f32)0.0f,};
}
gl$Mat4 gl$Mat4$perspective(f32 fov, f32 aspect, f32 near, f32 far) {
  f32 tan_half_fov  = (f32)tan((fov / 2.0f));
  gl$Mat4 matrix  = gl$Mat4$zero();
  (matrix.M00 = (1.0f / (aspect * tan_half_fov)));
  (matrix.M11 = (1.0f / tan_half_fov));
  (matrix.M22 = ((f32)(-(far + near)) / (far - near)));
  (matrix.M23 = (f32)(-1.0f));
  (matrix.M32 = ((f32)(-((2.0f * far) * near)) / (far - near)));
  (matrix.M33 = 0.0f);
  return matrix;
}
void gl$Camera$update(gl$Camera* self) {
  (self->view = gl$Mat4$look_at(self->position,self->target,self->up));
  (self->projection = gl$Mat4$perspective(self->fov,self->aspect_ratio,self->near,self->far));
}
gl$Vec3 gl$Mat4$get_translation(gl$Mat4 self) {
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)self.M03,
    .y = (f32)self.M13,
    .z = (f32)self.M23,};
}
typedef struct gl$Mat4 gl$Mat4;
extern void  glUniformMatrix4fv(s32, s32, bool, f32*);
void gl$Shader$set_mat4(gl$Shader* self, str name, gl$Mat4* v) {
  s32 index  = glGetUniformLocation(self->handle,name.data);
  
  if ((index != (s32)(-1))) {
    glUniformMatrix4fv(index,1,false,(f32*)v);
  }
  else{
    std$printf((str) { .data = "failed to get uniform : %s\n", .length = 27 },name.data);
  }
;
}
void gl$Shader$set$903(gl$Shader* self, str name, gl$Mat4 v) {
{
    gl$Shader$set_mat4(self, name,(gl$Mat4*)(&v));
  }
}
extern void  glClear(u32);
const static s32 NUM_VERTICES  = 36;
extern void  glDrawArrays(u32, s32, s32);
extern void  glfwSwapBuffers(gl$GLFWwindow*);
extern void  glfwPollEvents();
void gl$Window$present(gl$Window* self) {
  glfwSwapBuffers(self->handle);
  glfwPollEvents();
}
void __ela_main_()
{
  gl$Window window  = gl$Window$create(800,600,(str) { .data = "Привет, Мир!", .length = 21 });
  glEnable(gl$GL$DEPTH_TEST);
  glClearColor(0.005f,0.005f,0.005f,1.0f);
  GeneralBuffer$1866 buffer  = GeneralBuffer$1866$new();
  fs$fmt$println$33(buffer.descriptor,(*fs$fmt$FormatOptions$current()));
  gl$Shader shader  = (gl$Shader){};
{
    String vertex  = Result$33_32$unwrap(fs$File$read_all$32((str) { .data = "shader/vert.glsl", .length = 16 }));
    String fragment  = Result$33_32$unwrap(fs$File$read_all$32((str) { .data = "shader/frag.glsl", .length = 16 }));
    (shader = gl$Shader$create(vertex,fragment));
    gl$Shader$use(&shader);
    String$destroy(&vertex, true);
    String$destroy(&fragment, true);
  }
  List$5 key_buffer  = (List$5){};
{
    glfwSetWindowUserPointer(window.handle,(&key_buffer));
    gl$Window$set_key_callback(&window, $lambda$7);
  }
  Cube model  = (Cube){.scale = (gl$Vec3){},.position = (gl$Vec3){},.rotation = (gl$Vec3){},};
{
    (model = Cube$new(0.1f));
    Cube$set_position(&model, gl$Vec3$new(0.0f,0.0f,(f32)(-5.0f)));
  }
  gl$Camera camera  = (gl$Camera){.position = (gl$Vec3){},.target = (gl$Vec3){},.up = (gl$Vec3){},.view = (gl$Mat4){},.projection = (gl$Mat4){},};
{
    f32 fov  = 45.0f;
    f32 aspect_ratio  = (800.0f / 600.0f);
    f32 near  = 0.1f;
    f32 far  = 100.0f;
    (camera = gl$Camera$new(gl$Vec3$up(),fov,aspect_ratio,near,far));
    (camera.position = gl$Vec3$new(0.0f,0.0f,3.0f));
    (camera.target = model.position);
  }
{
    gl$Vec3 lightColor  = gl$Vec3$new(0.0f,1.0f,1.0f);
    gl$Vec3 objectColor  = gl$Vec3$new(1.0f,0.25f,0.31f);
    gl$Vec3 lightPos  = gl$Vec3$new(0.0f,1.0f,1.0f);
    gl$Shader$set$890(&shader, (str) { .data = "lightPos", .length = 8 },lightPos);
    gl$Shader$set$890(&shader, (str) { .data = "lightColor", .length = 10 },lightColor);
    gl$Shader$set$890(&shader, (str) { .data = "objectColor", .length = 11 },objectColor);
    gl$Shader$set$9(&shader, (str) { .data = "specularStrength", .length = 16 },1.5f);
    gl$Shader$set$9(&shader, (str) { .data = "ambientStrength", .length = 15 },1.0f);
  }
  gl$Vec3 model_pos  = gl$Vec3$new(0.0f,0.0f,(f32)(-5.0f));
  GeneralBuffer$1866$bind_and_buffer_data(buffer, Cube$vertex_slice(model));
  while ((!gl$Window$should_close(&window))) {
    while ((key_buffer.length > 0)) {
      gl$Vec3 move_vector  = ({gl$Vec3 register$0;      u32 $switch_target$10 = List$5$pop(&key_buffer);
      if ($switch_target$10 == 0x77) {
register$0 = gl$Vec3$new(0.0f,0.0f,(f32)(-1.0f));
      }
      else       if ($switch_target$10 == 0x61) {
register$0 = gl$Vec3$new(1.0f,0.0f,0.0f);
      }
      else       if ($switch_target$10 == 0x73) {
register$0 = gl$Vec3$new(0.0f,0.0f,1.0f);
      }
      else       if ($switch_target$10 == 0x64) {
register$0 = gl$Vec3$new((f32)(-1.0f),0.0f,0.0f);
      }
else {
{
register$0 = gl$Vec3$zero();
      }
}
register$0;});
      (model.position = (gl$Vec3$add(model.position, move_vector)));
      std$printf((str) { .data = "moving := %.1f, %.1f, %.1f\n", .length = 27 },model.position.x,model.position.y,model.position.z);
    }
    gl$Mat4 matrix  = Cube$matrix(model);
    (camera.target = model.position);
    gl$Camera$update(&camera);
    gl$Vec3 viewPos  = gl$Mat4$get_translation(camera.view);
    gl$Shader$set$890(&shader, (str) { .data = "viewPos", .length = 7 },viewPos);
    gl$Shader$set$903(&shader, (str) { .data = "model", .length = 5 },matrix);
    gl$Shader$set$903(&shader, (str) { .data = "view", .length = 4 },camera.view);
    gl$Shader$set$903(&shader, (str) { .data = "projection", .length = 10 },camera.projection);
    glClear((gl$GL$COLOR_BUFFER_BIT | gl$GL$DEPTH_BUFFER_BIT));
    glDrawArrays(gl$GL$TRIANGLES,0,NUM_VERTICES);
    gl$Window$present(&window);
  }
}
bool str$neq(str self, str right) {
  return (!str$eq(self, right));
}
Slice$7 Slice$7$slice$81(Slice$7 self, RangeBase$1 range) {
  
  if ((range.begin < 0)) {
    (range.begin = 0);
  }
;
  
  if (((range.end == (s32)(-1)) || (range.end > self.length))) {
    (range.end = self.length);
  }
;
  s32 length  = (range.end - range.begin);
  
  if ((length < 0)) {
    return (Slice$7)(Slice$7){};
  }
;
  return (Slice$7)(Slice$7){
    .data = (u8*)(self.data + range.begin),
    .length = (u64)length,};
}
Slice$7 str$subslice(str self, RangeBase$1 range) {
  return Slice$7$slice$81(str$as_slice(self), range);
}
typedef struct IterMut$7 {
  u8* ptr;
  u8* end;
} IterMut$7;
IterMut$7 str$iter_mut(str* self) {
  return (IterMut$7)(IterMut$7){
    .ptr = (u8*)(u8*)self->data,
    .end = (u8*)(self->data + self->length),};
}
u64 HASH_INITIAL_VALUE;
u64 HASH_FACTOR;
u64 u64$hash(u64 self) {
  u64 hash  = HASH_INITIAL_VALUE;
  (hash ^= self);
  (hash *= HASH_FACTOR);
  return hash;
}
u64 u64$max_value() {
  return 18446744073709551615;
}
u64 u64$min_value() {
  return 0;
}
typedef struct Iter$7 {
  u8* ptr;
  u8* end;
} Iter$7;
Iter$7 str$iter(str* self) {
  return (Iter$7)(Iter$7){
    .ptr = (u8*)(u8*)self->data,
    .end = (u8*)(self->data + self->length),};
}
typedef struct $tuple7 {
  u8 $0;
} $tuple7;
typedef struct Option$7 Option$7;
typedef $tuple7 Option$7$Some;
typedef struct Option$7 {
  int index;
  union {
    Option$7$Some Some;
  };
} Option$7;
static inline Option$7 None$184() {
  return  (Option$7) { .index = 1};
}
static inline Option$7 Some$7(u8 t) {
  return (Option$7) {
.index = 2,
.Some = ($tuple7) {.$0 = t}};
}
Option$7 str$front(str self) {
  
  if ((self.length == 0)) {
    return None$184();
  }
;
  return Some$7(self.data[0]);
}
Slice$7 str$slice(str* self, RangeBase$1 range) {
$tuple1$1 $deconstruction$1 = ($tuple1$1) {.$0 = range.begin, .$1 = range.end};
auto start = $deconstruction$1.$0;
auto end = $deconstruction$1.$1;
  s32 length  = (end - start);
  
  if ((((start < 0) || (length < 0)) || ((start + length) > self->length))) {
    return (Slice$7)(Slice$7){};
  }
;
  return (Slice$7)(Slice$7){
    .data = (u8*)(self->data + start),
    .length = (u64)length,};
}
extern s32  toupper(s32);
u8 u8$to_upper(u8 self) {
  return (u8)toupper(self);
}
extern s32  tolower(s32);
u8 u8$to_lower(u8 self) {
  return (u8)tolower(self);
}
extern s32  isgraph(s32);
bool u8$is_graph(u8 self) {
  return (isgraph(self) != 0);
}
extern s32  islower(s32);
bool u8$is_lowercase(u8 self) {
  return (islower(self) != 0);
}
u8 u8$max_value() {
  return 255;
}
u64 u8$hash(u8 self) {
  u64 hash  = HASH_INITIAL_VALUE;
  (hash ^= self);
  (hash *= HASH_FACTOR);
  return hash;
}
extern s32  isalpha(s32);
bool u8$is_alpha(u8 self) {
  return (isalpha(self) != 0);
}
extern s32  ispunct(s32);
bool u8$is_ascii_punctuation(u8 self) {
  return (ispunct(self) != 0);
}
extern s32  isalnum(s32);
bool u8$is_alphanumeric(u8 self) {
  return (isalnum(self) != 0);
}
extern s32  isdigit(s32);
bool u8$is_digit(u8 self) {
  return (isdigit(self) != 0);
}
extern s32  isprint(s32);
bool u8$is_printable(u8 self) {
  return (isprint(self) != 0);
}
extern s32  isupper(s32);
bool u8$is_uppercase(u8 self) {
  return (isupper(self) != 0);
}
extern s32  isspace(s32);
bool u8$is_whitespace(u8 self) {
  return (isspace(self) != 0);
}
extern s32  isxdigit(s32);
bool u8$is_hex_digit(u8 self) {
  return (isxdigit(self) != 0);
}
u8 u8$min_value() {
  return 0;
}
extern s32  iscntrl(s32);
bool u8$is_control(u8 self) {
  return (iscntrl(self) != 0);
}
bool str$is_empty_or_whitespace(str self) {
  {
    RangeBase$1 $iterable = (RangeBase$1) {.begin = 0, .end = self.length};
    RangeIter$1 $iterator = RangeBase$1$iter(&$iterable);


    for (auto $next = RangeIter$1$next(&$iterator);
$next.index != 1; $next = RangeIter$1$next(&$iterator)) {
    s32 i = $next.Some.$0;
    {
      u8 ch  = self.data[i];
      
      if ((ch != 0x20)) {
        return false;
      }
;
    }
  }
}
return true;
}
typedef struct Iter$7 Iter$7;
static inline Option$7 Iter$7$next(Iter$7* self) {
  
  if ((self->ptr >= self->end)) {
    return  (Option$7) { .index = 1};
  }
;
  Option$7 value  = (Option$7) {
.index = 2,
.Some = ($tuple7) {.$0 = (*self->ptr)}};
  self->ptr++;
  return value;
}
u64 str$hash(str self) {
  u64 hash  = 0xCBF29CE484222325;
  {
    str $iterable = self;
    Iter$7 $iterator = str$iter(&$iterable);


    for (auto $next = Iter$7$next(&$iterator);
$next.index != 1; $next = Iter$7$next(&$iterator)) {
    u8 byte = $next.Some.$0;
    {
      (hash ^= byte);
      (hash *= 0x100000001B3);
    }
  }
}
return hash;
}
str str$empty() {
  return (str)(str){};
}
Option$7 None$184();
Option$7 str$back(str self) {
  
  if ((self.length == 0)) {
    return None$184();
  }
;
  return Some$7(self.data[(self.length - 1)]);
}
bool str$is_empty(str self) {
  return (self.length == 0);
}
u8* str$index_mut(str* self, u64 idx) {
  return (&self->data[idx]);
}
gl$Vec3 gl$Vec3$div(gl$Vec3 self, f32 scalar) {
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)(self.x / scalar),
    .y = (f32)(self.y / scalar),
    .z = (f32)(self.z / scalar),};
}
u64 f32$hash(f32 self) {
  u64 hash  = HASH_INITIAL_VALUE;
  (hash ^= (u32)self);
  (hash *= HASH_FACTOR);
  return hash;
}
f32 f32$max_value() {
  return 340282350000000000000000000000000000000.0f;
}
f32 f32$min_value() {
  return (f32)(-340282350000000000000000000000000000000.0f);
}
f32 gl$Vec3$sqr_mag(gl$Vec3* self) {
  return (((self->x * self->x) + (self->y * self->y)) + (self->z * self->z));
}
gl$Vec3 gl$Vec3$one() {
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)1.0f,
    .y = (f32)1.0f,
    .z = (f32)1.0f,};
}
gl$Vec3 gl$Vec3$mul(gl$Vec3 self, f32 scalar) {
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)(self.x * scalar),
    .y = (f32)(self.y * scalar),
    .z = (f32)(self.z * scalar),};
}
gl$Vec4 gl$Vec4$zero() {
  return (gl$Vec4)(gl$Vec4){
    .x = (f32)0.0f,
    .y = (f32)0.0f,
    .z = (f32)0.0f,
    .w = (f32)0.0f,};
}
gl$Vec4 gl$Vec4$one() {
  return (gl$Vec4)(gl$Vec4){
    .x = (f32)1.0f,
    .y = (f32)1.0f,
    .z = (f32)1.0f,
    .w = (f32)1.0f,};
}
typedef struct gl$Vec4 gl$Vec4;
f32 gl$Vec4$sqr_mag(gl$Vec4* self) {
  return ((((self->x * self->x) + (self->y * self->y)) + (self->z * self->z)) + (self->w * self->w));
}
u64 s32$hash(s32 self) {
  u64 hash  = HASH_INITIAL_VALUE;
  (hash ^= self);
  (hash *= HASH_FACTOR);
  return hash;
}
s32 s32$max_value() {
  return 2147483647;
}
s32 s32$min_value() {
  return (s32)(-2147483648);
}
f32 gl$math$sqrt$9(f32 f);
gl$Vec3 gl$Mat4$get_scale(gl$Mat4 self) {
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)(f32)gl$math$sqrt$9((((self.M00 * self.M00) + (self.M01 * self.M01)) + (self.M02 * self.M02))),
    .y = (f32)(f32)gl$math$sqrt$9((((self.M10 * self.M10) + (self.M11 * self.M11)) + (self.M12 * self.M12))),
    .z = (f32)(f32)gl$math$sqrt$9((((self.M20 * self.M20) + (self.M21 * self.M21)) + (self.M22 * self.M22))),};
}
extern f64  atan2(f64, f64);
gl$Vec3 gl$Mat4$get_rotation(gl$Mat4 self) {
  gl$Vec3 scale  = gl$Mat4$get_scale(self);
  return (gl$Vec3)(gl$Vec3){
    .x = (f32)(f32)atan2((self.M21 / scale.z),(self.M22 / scale.z)),
    .y = (f32)(f32)atan2(((f32)(-self.M20) / scale.z),(gl$math$sqrt$9(((self.M21 * self.M21) + (self.M22 * self.M22))) / scale.z)),
    .z = (f32)(f32)atan2((self.M10 / scale.y),(self.M00 / scale.x)),};
}
gl$Mat4 gl$Mat4$scale(gl$Mat4* self, f32 factor) {
  gl$Mat4 matrix  = (gl$Mat4){};
  (matrix.M00 = (self->M00 * factor));
  (matrix.M01 = (self->M01 * factor));
  (matrix.M02 = (self->M02 * factor));
  (matrix.M03 = (self->M03 * factor));
  (matrix.M10 = (self->M10 * factor));
  (matrix.M11 = (self->M11 * factor));
  (matrix.M12 = (self->M12 * factor));
  (matrix.M13 = (self->M13 * factor));
  (matrix.M20 = (self->M20 * factor));
  (matrix.M21 = (self->M21 * factor));
  (matrix.M22 = (self->M22 * factor));
  (matrix.M23 = (self->M23 * factor));
  (matrix.M30 = (self->M30 * factor));
  (matrix.M31 = (self->M31 * factor));
  (matrix.M32 = (self->M32 * factor));
  (matrix.M33 = (self->M33 * factor));
  return matrix;
}
gl$Mat4 gl$Mat4$normalize(gl$Mat4* self) {
  f32 mag  = (f32)gl$math$sqrt$9(((((((((((((((((self->M00 * self->M00) + (self->M01 * self->M01)) + (self->M02 * self->M02)) + (self->M03 * self->M03)) + (self->M10 * self->M10)) + (self->M11 * self->M11)) + (self->M12 * self->M12)) + (self->M13 * self->M13)) + (self->M20 * self->M20)) + (self->M21 * self->M21)) + (self->M22 * self->M22)) + (self->M23 * self->M23)) + (self->M30 * self->M30)) + (self->M31 * self->M31)) + (self->M32 * self->M32)) + (self->M33 * self->M33)));
  return gl$Mat4$scale(self, (1.0f / mag));
}
f32 gl$Mat4$determinant(gl$Mat4* self) {
  f32 r0  = (self->M00 * (((self->M11 * ((self->M22 * self->M33) - (self->M23 * self->M32))) - (self->M12 * ((self->M21 * self->M33) - (self->M23 * self->M31)))) + (self->M13 * ((self->M21 * self->M32) - (self->M22 * self->M31)))));
  f32 r1  = (self->M01 * (((self->M10 * ((self->M22 * self->M33) - (self->M23 * self->M32))) - (self->M12 * ((self->M20 * self->M33) - (self->M23 * self->M30)))) + (self->M13 * ((self->M20 * self->M32) - (self->M22 * self->M30)))));
  f32 r2  = (self->M02 * (((self->M10 * ((self->M21 * self->M33) - (self->M23 * self->M31))) - (self->M11 * ((self->M20 * self->M33) - (self->M23 * self->M30)))) + (self->M13 * ((self->M20 * self->M31) - (self->M21 * self->M30)))));
  f32 r3  = (self->M03 * (((self->M10 * ((self->M21 * self->M32) - (self->M22 * self->M31))) - (self->M11 * ((self->M20 * self->M32) - (self->M22 * self->M30)))) + (self->M12 * ((self->M20 * self->M31) - (self->M21 * self->M30)))));
  return (((r0 - r1) + r2) - r3);
}
typedef struct gl$Vec2 gl$Vec2;
gl$Vec2 gl$Vec2$normalize(gl$Vec2* self) {
  f32 mag  = (f32)gl$math$sqrt$9(((self->x * self->x) + (self->y * self->y)));
  return (gl$Vec2)(gl$Vec2){
    .x = (f32)(self->x / mag),
    .y = (f32)(self->y / mag),};
}
gl$Vec2 gl$Vec2$zero() {
  return (gl$Vec2)(gl$Vec2){
    .x = (f32)0.0f,
    .y = (f32)0.0f,};
}
gl$Vec2 gl$Vec2$one() {
  return (gl$Vec2)(gl$Vec2){
    .x = (f32)1.0f,
    .y = (f32)1.0f,};
}
f32 gl$Vec2$sqr_mag(gl$Vec2* self) {
  return ((self->x * self->x) + (self->y * self->y));
}
u64 f64$hash(f64 self) {
  u64 hash  = HASH_INITIAL_VALUE;
  (hash ^= (u32)self);
  (hash *= HASH_FACTOR);
  return hash;
}
f64 f64$max_value() {
  return 179769313486231570000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
}
f64 f64$min_value() {
  return (f64)(-179769313486231570000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0);
}
u64 s64$hash(s64 self) {
  u64 hash  = HASH_INITIAL_VALUE;
  (hash ^= self);
  (hash *= HASH_FACTOR);
  return hash;
}
s64 s64$max_value() {
  return 9223372036854775807;
}
s64 s64$min_value() {
  return (s64)(-9223372036854775808);
}
str String$as_str(String self) {
  return (str)(str){
    .data = (u8*)self.data,
    .length = (u64)self.length,};
}
u64 String$hash(String self) {
  return str$hash(String$as_str(self));
}
Slice$7 Slice$7$slice$81(Slice$7 self, RangeBase$1 range);
Slice$7 String$subslice(String self, RangeBase$1 range) {
  return Slice$7$slice$81(String$as_slice(self), range);
}
Iter$7 String$iter(String* self) {
  return (Iter$7)(Iter$7){
    .ptr = (u8*)self->data,
    .end = (u8*)(self->data + self->length),};
}
u8* String$index(String* self, u64 idx) {
  return (&self->data[idx]);
}
bool String$eq(String self, String other) {
  
  if ((self.length != other.length)) {
    return false;
  }
;
  {
    RangeBase$1 $iterable = (RangeBase$1) {.begin = 0, .end = self.length};
    RangeIter$1 $iterator = RangeBase$1$iter(&$iterable);


    for (auto $next = RangeIter$1$next(&$iterator);
$next.index != 1; $next = RangeIter$1$next(&$iterator)) {
    s32 idx = $next.Some.$0;
    {
      
      if (((*(String$index(&self, idx))) != (*(String$index(&other, idx))))) {
        return false;
      }
;
    }
  }
}
return true;
}
bool String$neq(String self, String right) {
  return (!String$eq(self, right));
}
Slice$7 String$slice(String self, RangeBase$1 range) {
  return (Slice$7)(Slice$7){
    .data = (u8*)(self.data + range.begin),
    .length = (u64)(range.end - range.begin),};
}
u8* String$index_mut(String* self, u64 idx) {
  return (&self->data[idx]);
}
IterMut$7 String$iter_mut(String* self) {
  return (IterMut$7)(IterMut$7){
    .ptr = (u8*)self->data,
    .end = (u8*)(self->data + self->length),};
}
String String$clone(String self) {
  dyn$Allocator allocator  = self.allocator;
  
  if ((!dyn$Allocator$has_instance(allocator))) {
    (allocator = get_global_allocator());
  }
;
  return (String)(String){
    .data = (u8*)allocator.copy(allocator.instance, self.data, sizeof(u8), self.length),
    .length = (u64)self.length,
    .capacity = (u64)self.capacity,
    .allocator = (dyn$Allocator)allocator,};
}
extern s32  memmove(void*, void*, s64);
void String$erase_at(String* self, u64 index) {
  
  if ((index >= self->length)) {
    return;
  }
;
  memmove((self->data + index),((self->data + index) + 1),((self->length - index) - 1));
  self->length--;
  (self->data[self->length] = 0x0);
}
Option$7 String$back(String self) {
  
  if ((self.length == 0)) {
    return None$184();
  }
;
  return Some$7(self.data[(self.length - 1)]);
}
String String$empty() {
  return (String)(String){};
}
bool String$is_empty_or_whitespace(String self) {
  {
    RangeBase$1 $iterable = (RangeBase$1) {.begin = 0, .end = self.length};
    RangeIter$1 $iterator = RangeBase$1$iter(&$iterable);


    for (auto $next = RangeIter$1$next(&$iterator);
$next.index != 1; $next = RangeIter$1$next(&$iterator)) {
    s32 i = $next.Some.$0;
    {
      u8 ch  = self.data[i];
      
      if ((ch != 0x20)) {
        return false;
      }
;
    }
  }
}
return true;
}
typedef struct SliceMut$7 {
  u8* data;
  u64 length;
} SliceMut$7;
SliceMut$7 String$slice_mut(String self, RangeBase$1 range) {
  return (SliceMut$7)(SliceMut$7){
    .data = (u8*)(u8*)(self.data + range.begin),
    .length = (u64)(range.end - range.begin),};
}
Option$7 String$front(String self) {
  
  if ((self.length == 0)) {
    return None$184();
  }
;
  return Some$7(self.data[0]);
}
bool String$is_empty(String self) {
  return (self.length == 0);
}
u8 String$pop_front(String* self) {
  
  if ((self->length == 0)) {
    return (u8)0x0;
  }
;
  u8 ch  = self->data[0];
  memmove(self->data,(self->data + 1),(self->length - 1));
  self->length--;
  (self->data[self->length] = 0x0);
  return ch;
}
void String$insert_at(String* self, u64 index, u8 ch) {
  
  if ((index > self->length)) {
    return;
  }
;
  
  if ((self->capacity == 0)) {
    (self->capacity = (256 / 3));
  }
;
  
  if (((!self->data) || ((self->length + 1) >= self->capacity))) {
    String$resize(self, (self->capacity * 3));
  }
;
  memmove(((self->data + index) + 1),(self->data + index),(self->length - index));
  (self->data[index] = ch);
  self->length++;
  (self->data[self->length] = 0x0);
}
u8 String$pop(String* self) {
  
  if ((self->length == 0)) {
    return (u8)0x0;
  }
;
  u8 ch  = self->data[self->length--];
  (self->data[self->length] = 0x0);
  return ch;
}
void String$push_front(String* self, u8 ch) {
  
  if ((self->capacity == 0)) {
    (self->capacity = (256 / 3));
  }
;
  
  if (((self->length + 1) >= self->capacity)) {
    String$resize(self, (self->capacity * 3));
  }
;
  memmove((self->data + 1),self->data,self->length);
  (self->data[0] = ch);
  self->length++;
  (self->data[self->length] = 0x0);
}
String String$substr(String self, u64 start, u64 length) {
  
  if ((start >= self.length)) {
    return (String)(String){};
  }
;
  
  if (((start + length) > self.length)) {
    (length = (self.length - start));
  }
;
  return (String)(String){
    .data = (u8*)self.allocator.copy(self.allocator.instance, (self.data + start), sizeof(u8), length),
    .length = (u64)length,
    .capacity = (u64)length,};
}
u64 s16$hash(s16 self) {
  u64 hash  = HASH_INITIAL_VALUE;
  (hash ^= self);
  (hash *= HASH_FACTOR);
  return hash;
}
s16 s16$max_value() {
  return 32767;
}
s16 s16$min_value() {
  return (s16)(-32768);
}
u64 u16$hash(u16 self) {
  u64 hash  = HASH_INITIAL_VALUE;
  (hash ^= self);
  (hash *= HASH_FACTOR);
  return hash;
}
u16 u16$max_value() {
  return 65535;
}
u16 u16$min_value() {
  return 0;
}
Slice$7 u32$subslice(u32 self, RangeBase$1 range) {
  return Slice$7$slice$81(u32$as_slice(self), range);
}
u32 u32$to_upper(u32 self) {
  return (u32)toupper(self);
}
u32 u32$to_lower(u32 self) {
  return (u32)tolower(self);
}
bool u32$is_graph(u32 self) {
  return (isgraph(self) != 0);
}
bool u32$is_lowercase(u32 self) {
  return (islower(self) != 0);
}
u32 u32$max_value() {
  return 4294967295;
}
u64 u32$hash(u32 self) {
  u64 hash  = HASH_INITIAL_VALUE;
  (hash ^= self);
  (hash *= HASH_FACTOR);
  return hash;
}
bool u32$is_alpha(u32 self) {
  return (isalpha(self) != 0);
}
bool u32$is_ascii_punctuation(u32 self) {
  return (ispunct(self) != 0);
}
bool u32$is_alphanumeric(u32 self) {
  return (isalnum(self) != 0);
}
bool u32$is_digit(u32 self) {
  return (isdigit(self) != 0);
}
bool u32$is_printable(u32 self) {
  return (isprint(self) != 0);
}
bool u32$is_uppercase(u32 self) {
  return (isupper(self) != 0);
}
bool u32$is_whitespace(u32 self) {
  return (isspace(self) != 0);
}
bool u32$is_hex_digit(u32 self) {
  return (isxdigit(self) != 0);
}
u32 u32$min_value() {
  return 0;
}
bool u32$is_control(u32 self) {
  return (iscntrl(self) != 0);
}
u64 s8$hash(s8 self) {
  u64 hash  = HASH_INITIAL_VALUE;
  (hash ^= self);
  (hash *= HASH_FACTOR);
  return hash;
}
s8 s8$max_value() {
  return 127;
}
s8 s8$min_value() {
  return (s8)(-128);
}

#ifdef TESTING
  #define ___MAIN___\
    for (int i = 0; i < sizeof(tests) / sizeof($ela_test); i++) { $ela_test_run(&tests[i]); }
#else 
  #define ___MAIN___\
    __ela_main_();
#endif
  void ela_run_global_initializers() {
global_allocator = (dyn$Allocator){0};
global_dyn_libc_allocator = (dyn$Allocator){0};
global_libc_allocator = (Libc_Allocator){};
HASH_INITIAL_VALUE = 0xCBF29CE484222325;
HASH_FACTOR = 0x100000001B3;
}

int main (int argc, char** argv) {
  /* initialize command line args. */
  Env$initialize(argc, argv);
  /* run the global initializers */
  ela_run_global_initializers();
  /* call user main, or dispatch tests, depending on the build type. */
  ___MAIN___;
}
const Type refl_ty$11 = (Type){ .id = 11, .name = (str){.data="void", .length = 4}, .size = sizeof(void), .flags = 0,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0}, .methods = {},  };
const Type refl_ty$14 = (Type){ .id = 14, .name = (str){.data="IsPointer", .length = 9}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
const Type refl_ty$13 = (Type){ .id = 13, .name = (str){.data="IsMutPointer", .length = 12}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$traits_array36[] = {((Type *)(&refl_ty$14)), 
((Type *)(&refl_ty$13)), 
};
const Type refl_ty$36 = (Type){ .id = 36, .name = (str){.data="*mut void", .length = 9}, .size = sizeof(void*), .flags = 512,
.element_type = ((Type *)(&refl_ty$11)),
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array36, .length = 2, .capacity = 2}, .methods = {},  };
const Type refl_ty$68 = (Type){ .id = 68, .name = (str){.data="IsNumeric", .length = 9}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
const Type refl_ty$70 = (Type){ .id = 70, .name = (str){.data="IsInteger", .length = 9}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
const Type refl_ty$62 = (Type){ .id = 62, .name = (str){.data="Hash", .length = 4}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
const Type refl_ty$831 = (Type){ .id = 831, .name = (str){.data="CharUtils", .length = 9}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$traits_array7[] = {((Type *)(&refl_ty$68)), 
((Type *)(&refl_ty$70)), 
((Type *)(&refl_ty$62)), 
((Type *)(&refl_ty$831)), 
};
Method $methods_array7[] = {{ .name = (str){.data = "to_upper", .length =  8}, .pointer = u8$to_upper }, { .name = (str){.data = "to_lower", .length =  8}, .pointer = u8$to_lower }, { .name = (str){.data = "is_graph", .length =  8}, .pointer = u8$is_graph }, { .name = (str){.data = "is_lowercase", .length =  12}, .pointer = u8$is_lowercase }, { .name = (str){.data = "hash", .length =  4}, .pointer = u8$hash }, { .name = (str){.data = "is_alpha", .length =  8}, .pointer = u8$is_alpha }, { .name = (str){.data = "is_ascii_punctuation", .length =  20}, .pointer = u8$is_ascii_punctuation }, { .name = (str){.data = "is_alphanumeric", .length =  15}, .pointer = u8$is_alphanumeric }, { .name = (str){.data = "is_digit", .length =  8}, .pointer = u8$is_digit }, { .name = (str){.data = "is_printable", .length =  12}, .pointer = u8$is_printable }, { .name = (str){.data = "is_uppercase", .length =  12}, .pointer = u8$is_uppercase }, { .name = (str){.data = "is_whitespace", .length =  13}, .pointer = u8$is_whitespace }, { .name = (str){.data = "is_hex_digit", .length =  12}, .pointer = u8$is_hex_digit }, { .name = (str){.data = "is_control", .length =  10}, .pointer = u8$is_control }, };
const Type refl_ty$7 = (Type){ .id = 7, .name = (str){.data="u8", .length = 2}, .size = sizeof(u8), .flags = 2049,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array7, .length = 4, .capacity = 4}, .methods = { .data = $methods_array7, .length = 14, .capacity = 14},  };
Type *$traits_array6[] = {((Type *)(&refl_ty$68)), 
((Type *)(&refl_ty$70)), 
((Type *)(&refl_ty$62)), 
};
Method $methods_array6[] = {{ .name = (str){.data = "hash", .length =  4}, .pointer = u16$hash }, };
const Type refl_ty$6 = (Type){ .id = 6, .name = (str){.data="u16", .length = 3}, .size = sizeof(u16), .flags = 2049,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array6, .length = 3, .capacity = 3}, .methods = { .data = $methods_array6, .length = 1, .capacity = 1},  };
Type *$gen_args_array215[] = {((Type *)(&refl_ty$7)), };

const Type refl_ty$215 = (Type){ .id = 215, .name = (str){.data="AsSlice!<u8>", .length = 12}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = {.data = $gen_args_array215, .length = 1, .capacity = 1}, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$traits_array5[] = {((Type *)(&refl_ty$68)), 
((Type *)(&refl_ty$70)), 
((Type *)(&refl_ty$62)), 
((Type *)(&refl_ty$831)), 
((Type *)(&refl_ty$215)), 
};
Method $methods_array5[] = {{ .name = (str){.data = "subslice", .length =  8}, .pointer = u32$subslice }, { .name = (str){.data = "as_slice", .length =  8}, .pointer = u32$as_slice }, { .name = (str){.data = "to_upper", .length =  8}, .pointer = u32$to_upper }, { .name = (str){.data = "to_lower", .length =  8}, .pointer = u32$to_lower }, { .name = (str){.data = "is_graph", .length =  8}, .pointer = u32$is_graph }, { .name = (str){.data = "is_lowercase", .length =  12}, .pointer = u32$is_lowercase }, { .name = (str){.data = "hash", .length =  4}, .pointer = u32$hash }, { .name = (str){.data = "is_alpha", .length =  8}, .pointer = u32$is_alpha }, { .name = (str){.data = "is_ascii_punctuation", .length =  20}, .pointer = u32$is_ascii_punctuation }, { .name = (str){.data = "is_alphanumeric", .length =  15}, .pointer = u32$is_alphanumeric }, { .name = (str){.data = "is_digit", .length =  8}, .pointer = u32$is_digit }, { .name = (str){.data = "is_printable", .length =  12}, .pointer = u32$is_printable }, { .name = (str){.data = "is_uppercase", .length =  12}, .pointer = u32$is_uppercase }, { .name = (str){.data = "is_whitespace", .length =  13}, .pointer = u32$is_whitespace }, { .name = (str){.data = "is_hex_digit", .length =  12}, .pointer = u32$is_hex_digit }, { .name = (str){.data = "is_control", .length =  10}, .pointer = u32$is_control }, };
const Type refl_ty$5 = (Type){ .id = 5, .name = (str){.data="u32", .length = 3}, .size = sizeof(u32), .flags = 2049,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array5, .length = 5, .capacity = 5}, .methods = { .data = $methods_array5, .length = 16, .capacity = 16},  };
Type *$traits_array4[] = {((Type *)(&refl_ty$68)), 
((Type *)(&refl_ty$70)), 
((Type *)(&refl_ty$62)), 
};
Method $methods_array4[] = {{ .name = (str){.data = "hash", .length =  4}, .pointer = u64$hash }, };
const Type refl_ty$4 = (Type){ .id = 4, .name = (str){.data="u64", .length = 3}, .size = sizeof(u64), .flags = 2049,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array4, .length = 3, .capacity = 3}, .methods = { .data = $methods_array4, .length = 1, .capacity = 1},  };
Type *$traits_array3[] = {((Type *)(&refl_ty$68)), 
((Type *)(&refl_ty$70)), 
((Type *)(&refl_ty$62)), 
};
Method $methods_array3[] = {{ .name = (str){.data = "hash", .length =  4}, .pointer = s8$hash }, };
const Type refl_ty$3 = (Type){ .id = 3, .name = (str){.data="s8", .length = 2}, .size = sizeof(s8), .flags = 1025,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array3, .length = 3, .capacity = 3}, .methods = { .data = $methods_array3, .length = 1, .capacity = 1},  };
Type *$traits_array2[] = {((Type *)(&refl_ty$68)), 
((Type *)(&refl_ty$70)), 
((Type *)(&refl_ty$62)), 
};
Method $methods_array2[] = {{ .name = (str){.data = "hash", .length =  4}, .pointer = s16$hash }, };
const Type refl_ty$2 = (Type){ .id = 2, .name = (str){.data="s16", .length = 3}, .size = sizeof(s16), .flags = 1025,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array2, .length = 3, .capacity = 3}, .methods = { .data = $methods_array2, .length = 1, .capacity = 1},  };
Type *$traits_array1[] = {((Type *)(&refl_ty$68)), 
((Type *)(&refl_ty$70)), 
((Type *)(&refl_ty$62)), 
};
Method $methods_array1[] = {{ .name = (str){.data = "hash", .length =  4}, .pointer = s32$hash }, };
const Type refl_ty$1 = (Type){ .id = 1, .name = (str){.data="s32", .length = 3}, .size = sizeof(s32), .flags = 1025,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array1, .length = 3, .capacity = 3}, .methods = { .data = $methods_array1, .length = 1, .capacity = 1},  };
Type *$traits_array0[] = {((Type *)(&refl_ty$68)), 
((Type *)(&refl_ty$70)), 
((Type *)(&refl_ty$62)), 
};
Method $methods_array0[] = {{ .name = (str){.data = "hash", .length =  4}, .pointer = s64$hash }, };
const Type refl_ty$0 = (Type){ .id = 0, .name = (str){.data="s64", .length = 3}, .size = sizeof(s64), .flags = 1025,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array0, .length = 3, .capacity = 3}, .methods = { .data = $methods_array0, .length = 1, .capacity = 1},  };
const Type refl_ty$69 = (Type){ .id = 69, .name = (str){.data="IsFloat", .length = 7}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$traits_array9[] = {((Type *)(&refl_ty$68)), 
((Type *)(&refl_ty$69)), 
((Type *)(&refl_ty$62)), 
};
Method $methods_array9[] = {{ .name = (str){.data = "hash", .length =  4}, .pointer = f32$hash }, };
const Type refl_ty$9 = (Type){ .id = 9, .name = (str){.data="f32", .length = 3}, .size = sizeof(f32), .flags = 2,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array9, .length = 3, .capacity = 3}, .methods = { .data = $methods_array9, .length = 1, .capacity = 1},  };
Type *$traits_array8[] = {((Type *)(&refl_ty$68)), 
((Type *)(&refl_ty$69)), 
((Type *)(&refl_ty$62)), 
};
Method $methods_array8[] = {{ .name = (str){.data = "hash", .length =  4}, .pointer = f64$hash }, };
const Type refl_ty$8 = (Type){ .id = 8, .name = (str){.data="f64", .length = 3}, .size = sizeof(f64), .flags = 2,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array8, .length = 3, .capacity = 3}, .methods = { .data = $methods_array8, .length = 1, .capacity = 1},  };
Type *$traits_array34[] = {((Type *)(&refl_ty$14)), 
((Type *)(&refl_ty$13)), 
};
const Type refl_ty$34 = (Type){ .id = 34, .name = (str){.data="*mut u8", .length = 7}, .size = sizeof(void*), .flags = 512,
.element_type = ((Type *)(&refl_ty$7)),
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array34, .length = 2, .capacity = 2}, .methods = {},  };
Field $fields_array35[] = {};
const Type refl_ty$24 = (Type){ .id = 24, .name = (str){.data="IsDyn", .length = 5}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$traits_array35[] = {((Type *)(&refl_ty$24)), 
};
Method $methods_array35[] = {{ .name = (str){.data = "has_instance", .length =  12}, .pointer = dyn$Allocator$has_instance }, };
const Type refl_ty$35 = (Type){ .id = 35, .name = (str){.data="dyn Allocator", .length = 13}, .size = sizeof(dyn$Allocator), .flags = 8192,
.element_type = NULL,
.fields = { .data = $fields_array35, .length = 7, .capacity = 7},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array35, .length = 1, .capacity = 1}, .methods = { .data = $methods_array35, .length = 1, .capacity = 1},  };
Field $fields_array33[] = {(Field) { .name = (str){.data="data", .length=4}, ._type = ((Type *)(&refl_ty$34)), .size = sizeof(void*),  }, (Field) { .name = (str){.data="length", .length=6}, ._type = ((Type *)(&refl_ty$4)), .size = sizeof(u64), .offset = offsetof(String, length) }, (Field) { .name = (str){.data="capacity", .length=8}, ._type = ((Type *)(&refl_ty$4)), .size = sizeof(u64), .offset = offsetof(String, capacity) }, (Field) { .name = (str){.data="allocator", .length=9}, ._type = ((Type *)(&refl_ty$35)), .size = sizeof(dyn$Allocator), .offset = offsetof(String, allocator) }, };
const Type refl_ty$21 = (Type){ .id = 21, .name = (str){.data="IsStruct", .length = 8}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
const Type refl_ty$181 = (Type){ .id = 181, .name = (str){.data="StringUtils", .length = 11}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
const Type refl_ty$51 = (Type){ .id = 51, .name = (str){.data="Clone", .length = 5}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
const Type refl_ty$61 = (Type){ .id = 61, .name = (str){.data="Destroy", .length = 7}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$gen_args_array193[] = {((Type *)(&refl_ty$7)), };

const Type refl_ty$193 = (Type){ .id = 193, .name = (str){.data="Index!<u8>", .length = 10}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = {.data = $gen_args_array193, .length = 1, .capacity = 1}, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$gen_args_array435[] = {((Type *)(&refl_ty$33)), };

const Type refl_ty$435 = (Type){ .id = 435, .name = (str){.data="PartialEq!<String>", .length = 18}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = {.data = $gen_args_array435, .length = 1, .capacity = 1}, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
const Type refl_ty$67 = (Type){ .id = 67, .name = (str){.data="Iterable", .length = 8}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$traits_array33[] = {((Type *)(&refl_ty$21)), 
((Type *)(&refl_ty$181)), 
((Type *)(&refl_ty$51)), 
((Type *)(&refl_ty$61)), 
((Type *)(&refl_ty$193)), 
((Type *)(&refl_ty$435)), 
((Type *)(&refl_ty$67)), 
((Type *)(&refl_ty$215)), 
((Type *)(&refl_ty$62)), 
};
Method $methods_array33[] = {{ .name = (str){.data = "hash", .length =  4}, .pointer = String$hash }, { .name = (str){.data = "subslice", .length =  8}, .pointer = String$subslice }, { .name = (str){.data = "iter", .length =  4}, .pointer = String$iter }, { .name = (str){.data = "neq", .length =  3}, .pointer = String$neq }, { .name = (str){.data = "eq", .length =  2}, .pointer = String$eq }, { .name = (str){.data = "slice", .length =  5}, .pointer = String$slice }, { .name = (str){.data = "index_mut", .length =  9}, .pointer = String$index_mut }, { .name = (str){.data = "iter_mut", .length =  8}, .pointer = String$iter_mut }, { .name = (str){.data = "index", .length =  5}, .pointer = String$index }, { .name = (str){.data = "clone", .length =  5}, .pointer = String$clone }, { .name = (str){.data = "erase_at", .length =  8}, .pointer = String$erase_at }, { .name = (str){.data = "back", .length =  4}, .pointer = String$back }, { .name = (str){.data = "as_str", .length =  6}, .pointer = String$as_str }, { .name = (str){.data = "is_empty_or_whitespace", .length =  22}, .pointer = String$is_empty_or_whitespace }, { .name = (str){.data = "slice_mut", .length =  9}, .pointer = String$slice_mut }, { .name = (str){.data = "front", .length =  5}, .pointer = String$front }, { .name = (str){.data = "as_slice", .length =  8}, .pointer = String$as_slice }, { .name = (str){.data = "destroy", .length =  7}, .pointer = String$destroy }, { .name = (str){.data = "is_empty", .length =  8}, .pointer = String$is_empty }, { .name = (str){.data = "pop_front", .length =  9}, .pointer = String$pop_front }, { .name = (str){.data = "get_allocator_if_needed", .length =  23}, .pointer = String$get_allocator_if_needed }, { .name = (str){.data = "insert_at", .length =  9}, .pointer = String$insert_at }, { .name = (str){.data = "push", .length =  4}, .pointer = String$push }, { .name = (str){.data = "pop", .length =  3}, .pointer = String$pop }, { .name = (str){.data = "push_front", .length =  10}, .pointer = String$push_front }, { .name = (str){.data = "resize", .length =  6}, .pointer = String$resize }, { .name = (str){.data = "substr", .length =  6}, .pointer = String$substr }, };
const Type refl_ty$33 = (Type){ .id = 33, .name = (str){.data="String", .length = 6}, .size = sizeof(String), .flags = 8,
.element_type = NULL,
.fields = { .data = $fields_array33, .length = 4, .capacity = 4},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array33, .length = 9, .capacity = 9}, .methods = { .data = $methods_array33, .length = 36, .capacity = 36},  };
const Type refl_ty$12 = (Type){ .id = 12, .name = (str){.data="IsConstPointer", .length = 14}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$traits_array29[] = {((Type *)(&refl_ty$14)), 
((Type *)(&refl_ty$12)), 
};
const Type refl_ty$29 = (Type){ .id = 29, .name = (str){.data="*const u8", .length = 9}, .size = sizeof(void*), .flags = 512,
.element_type = ((Type *)(&refl_ty$7)),
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array29, .length = 2, .capacity = 2}, .methods = {},  };
Field $fields_array32[] = {(Field) { .name = (str){.data="data", .length=4}, ._type = ((Type *)(&refl_ty$29)), .size = sizeof(void*),  }, (Field) { .name = (str){.data="length", .length=6}, ._type = ((Type *)(&refl_ty$4)), .size = sizeof(u64), .offset = offsetof(str, length) }, };
Type *$gen_args_array410[] = {((Type *)(&refl_ty$32)), };

const Type refl_ty$410 = (Type){ .id = 410, .name = (str){.data="PartialEq!<str>", .length = 15}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = {.data = $gen_args_array410, .length = 1, .capacity = 1}, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$traits_array32[] = {((Type *)(&refl_ty$21)), 
((Type *)(&refl_ty$181)), 
((Type *)(&refl_ty$193)), 
((Type *)(&refl_ty$67)), 
((Type *)(&refl_ty$410)), 
((Type *)(&refl_ty$62)), 
((Type *)(&refl_ty$215)), 
};
Method $methods_array32[] = {{ .name = (str){.data = "as_slice", .length =  8}, .pointer = str$as_slice }, { .name = (str){.data = "neq", .length =  3}, .pointer = str$neq }, { .name = (str){.data = "eq", .length =  2}, .pointer = str$eq }, { .name = (str){.data = "subslice", .length =  8}, .pointer = str$subslice }, { .name = (str){.data = "iter_mut", .length =  8}, .pointer = str$iter_mut }, { .name = (str){.data = "iter", .length =  4}, .pointer = str$iter }, { .name = (str){.data = "front", .length =  5}, .pointer = str$front }, { .name = (str){.data = "slice", .length =  5}, .pointer = str$slice }, { .name = (str){.data = "is_empty_or_whitespace", .length =  22}, .pointer = str$is_empty_or_whitespace }, { .name = (str){.data = "hash", .length =  4}, .pointer = str$hash }, { .name = (str){.data = "index", .length =  5}, .pointer = str$index }, { .name = (str){.data = "back", .length =  4}, .pointer = str$back }, { .name = (str){.data = "is_empty", .length =  8}, .pointer = str$is_empty }, { .name = (str){.data = "index_mut", .length =  9}, .pointer = str$index_mut }, };
const Type refl_ty$32 = (Type){ .id = 32, .name = (str){.data="str", .length = 3}, .size = sizeof(str), .flags = 8,
.element_type = NULL,
.fields = { .data = $fields_array32, .length = 2, .capacity = 2},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array32, .length = 7, .capacity = 7}, .methods = { .data = $methods_array32, .length = 18, .capacity = 18},  };
const Type refl_ty$10 = (Type){ .id = 10, .name = (str){.data="bool", .length = 4}, .size = sizeof(bool), .flags = 4,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0}, .methods = {},  };
Field $fields_array402[] = {(Field) { .name = (str){.data="$0", .length=2}, ._type = ((Type *)(&refl_ty$1)), .size = sizeof(s32), .offset = offsetof($tuple1$1, $0) }, (Field) { .name = (str){.data="$1", .length=2}, ._type = ((Type *)(&refl_ty$1)), .size = sizeof(s32), .offset = offsetof($tuple1$1, $1) }, };
const Type refl_ty$15 = (Type){ .id = 15, .name = (str){.data="IsTuple", .length = 7}, .flags = 4096,
.element_type = NULL,
.fields = {.data = NULL, .length = 0, .capacity = 0}, .generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = NULL, .length = 0, .capacity = 0},  };
Type *$traits_array402[] = {((Type *)(&refl_ty$15)), 
};
const Type refl_ty$402 = (Type){ .id = 402, .name = (str){.data="(s32, s32)", .length = 10}, .size = sizeof($tuple1$1), .flags = 64,
.element_type = NULL,
.fields = { .data = $fields_array402, .length = 2, .capacity = 2},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array402, .length = 1, .capacity = 1}, .methods = {},  };
Field $fields_array2025[] = {(Field) { .name = (str){.data="$0", .length=2}, ._type = ((Type *)(&refl_ty$32)), .size = 0, .offset = offsetof($tuple32$1$4, $0) }, (Field) { .name = (str){.data="$1", .length=2}, ._type = ((Type *)(&refl_ty$1)), .size = sizeof(s32), .offset = offsetof($tuple32$1$4, $1) }, (Field) { .name = (str){.data="$2", .length=2}, ._type = ((Type *)(&refl_ty$4)), .size = sizeof(u64), .offset = offsetof($tuple32$1$4, $2) }, };
Type *$traits_array2025[] = {((Type *)(&refl_ty$15)), 
};
const Type refl_ty$2025 = (Type){ .id = 2025, .name = (str){.data="(str, s32, u64)", .length = 15}, .size = sizeof($tuple32$1$4), .flags = 64,
.element_type = NULL,
.fields = { .data = $fields_array2025, .length = 3, .capacity = 3},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array2025, .length = 1, .capacity = 1}, .methods = {},  };
Field $fields_array2030[] = {(Field) { .name = (str){.data="$0", .length=2}, ._type = ((Type *)(&refl_ty$1)), .size = sizeof(s32), .offset = offsetof($tuple1$4, $0) }, (Field) { .name = (str){.data="$1", .length=2}, ._type = ((Type *)(&refl_ty$4)), .size = sizeof(u64), .offset = offsetof($tuple1$4, $1) }, };
Type *$traits_array2030[] = {((Type *)(&refl_ty$15)), 
};
const Type refl_ty$2030 = (Type){ .id = 2030, .name = (str){.data="(s32, u64)", .length = 10}, .size = sizeof($tuple1$4), .flags = 64,
.element_type = NULL,
.fields = { .data = $fields_array2030, .length = 2, .capacity = 2},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array2030, .length = 1, .capacity = 1}, .methods = {},  };
Field $fields_array852[] = {(Field) { .name = (str){.data="$0", .length=2}, ._type = ((Type *)(&refl_ty$32)), .size = 0, .offset = offsetof($tuple32, $0) }, };
Type *$traits_array852[] = {((Type *)(&refl_ty$15)), 
};
const Type refl_ty$852 = (Type){ .id = 852, .name = (str){.data="(str)", .length = 5}, .size = sizeof($tuple32), .flags = 64,
.element_type = NULL,
.fields = { .data = $fields_array852, .length = 1, .capacity = 1},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array852, .length = 1, .capacity = 1}, .methods = {},  };
Field $fields_array890[] = {(Field) { .name = (str){.data="x", .length=1}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Vec3, x) }, (Field) { .name = (str){.data="y", .length=1}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Vec3, y) }, (Field) { .name = (str){.data="z", .length=1}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Vec3, z) }, };
Type *$traits_array890[] = {((Type *)(&refl_ty$21)), 
};
Method $methods_array890[] = {{ .name = (str){.data = "div", .length =  3}, .pointer = gl$Vec3$div }, { .name = (str){.data = "sub", .length =  3}, .pointer = gl$Vec3$sub }, { .name = (str){.data = "cross", .length =  5}, .pointer = gl$Vec3$cross }, { .name = (str){.data = "sqr_mag", .length =  7}, .pointer = gl$Vec3$sqr_mag }, { .name = (str){.data = "dot", .length =  3}, .pointer = gl$Vec3$dot }, { .name = (str){.data = "normalize", .length =  9}, .pointer = gl$Vec3$normalize }, { .name = (str){.data = "add", .length =  3}, .pointer = gl$Vec3$add }, { .name = (str){.data = "mul", .length =  3}, .pointer = gl$Vec3$mul }, };
const Type refl_ty$890 = (Type){ .id = 890, .name = (str){.data="Vec3", .length = 4}, .size = sizeof(gl$Vec3), .flags = 8,
.element_type = NULL,
.fields = { .data = $fields_array890, .length = 3, .capacity = 3},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array890, .length = 1, .capacity = 1}, .methods = { .data = $methods_array890, .length = 8, .capacity = 8},  };
Field $fields_array898[] = {(Field) { .name = (str){.data="x", .length=1}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Vec2, x) }, (Field) { .name = (str){.data="y", .length=1}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Vec2, y) }, };
Type *$traits_array898[] = {((Type *)(&refl_ty$21)), 
};
Method $methods_array898[] = {{ .name = (str){.data = "normalize", .length =  9}, .pointer = gl$Vec2$normalize }, { .name = (str){.data = "sqr_mag", .length =  7}, .pointer = gl$Vec2$sqr_mag }, };
const Type refl_ty$898 = (Type){ .id = 898, .name = (str){.data="Vec2", .length = 4}, .size = sizeof(gl$Vec2), .flags = 8,
.element_type = NULL,
.fields = { .data = $fields_array898, .length = 2, .capacity = 2},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array898, .length = 1, .capacity = 1}, .methods = { .data = $methods_array898, .length = 2, .capacity = 2},  };
Field $fields_array1866[] = {(Field) { .name = (str){.data="position", .length=8}, ._type = ((Type *)(&refl_ty$890)), .size = 0, .offset = offsetof(Vertex, position) }, (Field) { .name = (str){.data="normal", .length=6}, ._type = ((Type *)(&refl_ty$890)), .size = 0, .offset = offsetof(Vertex, normal) }, (Field) { .name = (str){.data="texcoord", .length=8}, ._type = ((Type *)(&refl_ty$898)), .size = 0, .offset = offsetof(Vertex, texcoord) }, };
Type *$traits_array1866[] = {((Type *)(&refl_ty$21)), 
};
const Type refl_ty$1866 = (Type){ .id = 1866, .name = (str){.data="Vertex", .length = 6}, .size = sizeof(Vertex), .flags = 8,
.element_type = NULL,
.fields = { .data = $fields_array1866, .length = 3, .capacity = 3},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array1866, .length = 1, .capacity = 1}, .methods = {},  };
Field $fields_array903[] = {(Field) { .name = (str){.data="M00", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M00) }, (Field) { .name = (str){.data="M01", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M01) }, (Field) { .name = (str){.data="M02", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M02) }, (Field) { .name = (str){.data="M03", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M03) }, (Field) { .name = (str){.data="M10", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M10) }, (Field) { .name = (str){.data="M11", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M11) }, (Field) { .name = (str){.data="M12", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M12) }, (Field) { .name = (str){.data="M13", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M13) }, (Field) { .name = (str){.data="M20", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M20) }, (Field) { .name = (str){.data="M21", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M21) }, (Field) { .name = (str){.data="M22", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M22) }, (Field) { .name = (str){.data="M23", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M23) }, (Field) { .name = (str){.data="M30", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M30) }, (Field) { .name = (str){.data="M31", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M31) }, (Field) { .name = (str){.data="M32", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M32) }, (Field) { .name = (str){.data="M33", .length=3}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Mat4, M33) }, };
Type *$traits_array903[] = {((Type *)(&refl_ty$21)), 
};
Method $methods_array903[] = {{ .name = (str){.data = "get_rotation", .length =  12}, .pointer = gl$Mat4$get_rotation }, { .name = (str){.data = "mul", .length =  3}, .pointer = gl$Mat4$mul }, { .name = (str){.data = "normalize", .length =  9}, .pointer = gl$Mat4$normalize }, { .name = (str){.data = "scale", .length =  5}, .pointer = gl$Mat4$scale }, { .name = (str){.data = "determinant", .length =  11}, .pointer = gl$Mat4$determinant }, { .name = (str){.data = "get_translation", .length =  15}, .pointer = gl$Mat4$get_translation }, { .name = (str){.data = "get_scale", .length =  9}, .pointer = gl$Mat4$get_scale }, };
const Type refl_ty$903 = (Type){ .id = 903, .name = (str){.data="Mat4", .length = 4}, .size = sizeof(gl$Mat4), .flags = 8,
.element_type = NULL,
.fields = { .data = $fields_array903, .length = 16, .capacity = 16},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array903, .length = 1, .capacity = 1}, .methods = { .data = $methods_array903, .length = 7, .capacity = 7},  };
Field $fields_array886[] = {(Field) { .name = (str){.data="x", .length=1}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Vec4, x) }, (Field) { .name = (str){.data="y", .length=1}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Vec4, y) }, (Field) { .name = (str){.data="z", .length=1}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Vec4, z) }, (Field) { .name = (str){.data="w", .length=1}, ._type = ((Type *)(&refl_ty$9)), .size = sizeof(f32), .offset = offsetof(gl$Vec4, w) }, };
Type *$traits_array886[] = {((Type *)(&refl_ty$21)), 
};
Method $methods_array886[] = {{ .name = (str){.data = "sqr_mag", .length =  7}, .pointer = gl$Vec4$sqr_mag }, };
const Type refl_ty$886 = (Type){ .id = 886, .name = (str){.data="Vec4", .length = 4}, .size = sizeof(gl$Vec4), .flags = 8,
.element_type = NULL,
.fields = { .data = $fields_array886, .length = 4, .capacity = 4},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array886, .length = 1, .capacity = 1}, .methods = { .data = $methods_array886, .length = 1, .capacity = 1},  };
Field $fields_array1707[] = {(Field) { .name = (str){.data="$0", .length=2}, ._type = ((Type *)(&refl_ty$33)), .size = 0, .offset = offsetof($tuple33, $0) }, };
Type *$traits_array1707[] = {((Type *)(&refl_ty$15)), 
};
const Type refl_ty$1707 = (Type){ .id = 1707, .name = (str){.data="(String)", .length = 8}, .size = sizeof($tuple33), .flags = 64,
.element_type = NULL,
.fields = { .data = $fields_array1707, .length = 1, .capacity = 1},.generic_args = { .data = NULL, .length = 0, .capacity = 0 }, .traits = { .data = $traits_array1707, .length = 1, .capacity = 1}, .methods = {},  };
