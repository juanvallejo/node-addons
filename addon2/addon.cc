#include "v8.h"
#include "v8-profiler.h"

// ...

FILE* fp = fopen(filename, "w");
if (fp == NULL) {
  return false;
}

const HeapSnapshot* const snap = C::HeapProfiler::TakeHeapSnapshot(isolate);
FileOutputStream stream(fp);
snap->Serialize(&stream, HeapSnapshot::kJSON);
fclose(fp);

// ...
NODE_MODULE(addon, Initialize)