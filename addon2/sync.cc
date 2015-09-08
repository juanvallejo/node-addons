// sync.cc
#include <node.h>
#include <nan.h>
#include "./sync.h"
// ...

using v8::Number;

// Simple synchronous access to the `Estimate()` function
NAN_METHOD(CalculateSync) {
  NanScope();

  // expect a number as the first argument
  int points = args[0]->Uint32Value();
  double est = Estimate(points);

  NanReturnValue(NanNew<Number>(est));
}