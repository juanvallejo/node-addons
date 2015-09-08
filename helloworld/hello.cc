/**
 * Hello.cc - Node.js module written in C++
 * Uses Nan and standard module syntax
 */

#include <nan.h>
#include <node.h>
#include <v8.h>

#include <string>

using namespace v8;

/**
 * Hello World method - Returns Hello World
 */
void EmptyArray(const Nan::FunctionCallbackInfo<v8::Value>& args) {
	args.GetReturnValue().Set(Nan::New<v8::Array>());
}

v8::Handle<v8::Value> GetHelloWorld(const v8::Arguments& args) {

	v8::HandleScope scope;
	return scope.Close(String::New("Hello World!"));

}

/**
 * Registers module and makes methods
 * publicly available in Node.js
 */
void init(v8::Handle<v8::Object> exports) {
	exports->Set(v8::String::NewSymbol("getHelloWorld"), v8::FunctionTemplate::New(GetHelloWorld)->GetFunction());
	exports->Set(v8::String::NewSymbol("emptyArray"), Nan::GetFunction(Nan::New<FunctionTemplate>(EmptyArray)).ToLocalChecked());
}

// define native module
NODE_MODULE(HelloWorld, init)