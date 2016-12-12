/* Copyright 2016 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifdef __MAKEFILE_JS__
#include <emscripten.h>
#endif

#include "tensorflow/tools/benchmark/benchmark_model.h"

int main(int argc, char** argv) {
   #if defined(__MAKEFILE_JS__) && !defined(__MAKEFILE_JS_MAKE_HTML__)
    // mount the directory so we can compile into JS
    EM_ASM(
      FS.mkdir('/working');
      FS.mount(NODEFS, { root: '/' }, '/working');
    );
  #endif

  return tensorflow::benchmark_model::Main(argc, argv);
}
