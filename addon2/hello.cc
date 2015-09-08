#include <node.h>
#include <v8.h>
 
using namespace v8;


// Each function to be exported must follow the same pattern as follows: 
// Handle<Value> FunctionName(const Arguments& args);

// Returns "Hello Kitty!".
Handle<Value> Hello(const Arguments& args) {
 HandleScope scope;
 return scope.Close(String::New("Hello!"));
}


// Let's play with a little complexity...

// Returns whatever you passed in, multiple arguments allowed.
Handle<Value> Echo(const Arguments& args) {
 HandleScope scope;
 Handle<String> input = String::New("");
 for (int i = 0; i != args.Length(); i++) {
   input = String::Concat(input,  args[i] -> ToString());
 }
 return scope.Close(input);
}


// Now that we have a handful of great functions, let's go and export them...
/* Equivalent to:
    exports.hello = Hello;
    exports.echo = Echo;
*/
// String::NewSymbol() is similar to String::New().
// However, for property names only NewSymbol() can be used.
// Check https://groups.google.com/forum/#!topic/v8-users/AXnMijKMIxs for details.

void Init(Handle<Object> exports) {
 exports -> Set(String::NewSymbol("hello"),
    FunctionTemplate::New(Hello) -> GetFunction());
 exports -> Set(String::NewSymbol("echo"),
    FunctionTemplate::New(Echo) -> GetFunction());
}

// Note:
// 1. NODE_MODULE is a macro defined in node.h,
//    so do not put a semicolon at the end.
/*
  #define NODE_MODULE(modname, regfunc) \
    extern "C" {                                                       \
      NODE_MODULE_EXPORT node::node_module_struct modname ## _module = \
      {                                                                \
        NODE_STANDARD_MODULE_STUFF,                                    \
        (node::addon_register_func)regfunc,                            \
        NODE_STRINGIFY(modname)                                        \
      };
*/
// 2. "hello" should equal the final output name of the module.
NODE_MODULE(hello, Init)
