//===- FIRAnnotation.cpp - defines FIRRTL Annotations -----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Defines annotations that can currently be handled.
//
//===----------------------------------------------------------------------===//

#include "circt/Dialect/FIRRTL/FIRRTLAnnotations.h"

namespace circt {
namespace firrtl {

class InlineAnnotation : FIRRTLAnnotation {
public:
  std::string target = "foo";

  std::string clazz = "firrtl.passes.InlineAnnotation";
};

} // namespace firrtl
} // namespace circt
