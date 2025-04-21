
#### Tagged Unions & Pattern Matching.

#### Drop trait and "destructors"

#### Fix any type and add ability to do implicit casting routine stuff.

#### #type needs to be it's own node, not ride on the back of ASTType

#### instead of just # stuff BEGINNING statements, we should be using them as attributes

such as
```rust
// compile time compatible struct.
struct Struct @const {
  x: f32,
  y: f32
}

fn snprintf() @foreign;
fn c_printf() @foreign(printf);

// we won't be constrained to 'main' as an entry point.
fn my_fruity_ahh_entry_point() @entry {
  ur_cappin: bool = false;
  printlnf("no cap bruh? = %", .[any::from(&ur_cappin)]);
}
```

This would allow us to stack up attributes too, and not be constrained to beginning a statement with #...

like 

```rust
  fn fmod() @foreign(fmod) @const;

  // we can also do auto impl's for common interfaces like Debug or Clone or whatever.
  union Result![_Ok, _Err] @impl[Clone, Debug] {

  }

  // we could also use this on even normal declarations / types.
  f: @dyn Interface;

```


#### Interfaces should have default or 'overrideable' functions, where the trait itself can define a method
  and the consumer of the trait can choose to provide a new one, or use the default.


#### Modules.
  A simple module system would take us a far way, avoid namespacing conflicts, provide a simple name mangling scheme etc. They would be ultimately optional.

```rust
  // or, import a module, an expose it via the :: operator, qualified.
  module main;
  import std::format;
  fn main() @entry {
    format::println("hello world");
  }


  // or, import targeted symbols.
  module main;
  import { println } in std::format;
  fn main() @entry {
    println("hello world");
  }

  // or, unload all symbols from the module into here.
  module main;
  import * in std::format;
  fn main() @entry {
    println("hello world");
  }


  // this wouldn't work, because we didn't actually implement std::format, we just added the std module which contains very little itself.
  module main;
  import std;
  fn main() @entry {
    std::format::println("hello world");
  }

```


#### change ![] to !<>. much kinder to read.
```rust
fn default!<T>() -> T {
  return .{}
}
```


#### allow tuple/struct destructure in for loop
```rust
  for k, v in hash_map {

  }
  for i, v in list.iter().indexed() {
    
  }
  for x, y in list_of_vec2s {

  }
```

#### add variadic generics and value generics.
```rust
  fn format!<T...>(fmt: str, pack: ...T) -> String {
    builder: std::StringBuilder;
    builder.set_allocator(std::mem::temp_allocator.{});
    defer builder.deinit();
    #for (t, v) in pack {
      builder.rtti_append(#type(t), v);
    }
    return builder.string();
  }
```

```rust
struct Fixed_Array!<T, N: u32> {
  data: T[N],
  length: N
}
```

```rust
fn index!<T, SIZE: u32, N: u32>(array: T[SIZE]) -> T {
  return array[N];
}
```


#### improve aliases. make it so we can alias functions and bascially any symbol (besides variables and arguments)

```rust
module main;
import { println } in std::format;

alias!<_Ok, _Err> Ok  :: Result!<_Ok, _Err>::Ok;
alias!<_Ok, _Err> Err :: Result!<_Ok, _Err>::Err;

fn main() @entry {
  x : Result!<s32, None> = Ok(100);
}
```