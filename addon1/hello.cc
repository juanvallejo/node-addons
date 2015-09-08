/**
 * Node.js module to compile
 * @author juanvallejo
 * @date 7/9/15
 */

#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * Our only method in this module. Returns a Handle<Value>
 * object containing our hello world v8::String
 */
Handle<Value> SayHello(const Arguments& args) {
	HandleScope scope;
	return scope.Close(String::New("Hello World!"));
}

/**
 * initialize our module by setting our SayHello function
 * as the value to our sayHello key in our module.exports.
 */
void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("sayHello"), FunctionTemplate::New(SayHello)->GetFunction());
}

// export our module
NODE_MODULE(hello, init)

