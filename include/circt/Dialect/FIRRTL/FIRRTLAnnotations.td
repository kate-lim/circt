//===- FIRRTLAnnotations.td - FIRRTL statement ops ---------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describe MLIR ops for FIRRTL annotations.
//
//===----------------------------------------------------------------------===//

#ifndef CIRCT_DIALECT_FIRRTL_ANNOTATIONS_TD
#define CIRCT_DIALECT_FIRRTL_ANNOTATIONS_TD

include "mlir/IR/OpBase.td"

def Annotation
  : Attr<CPred<"$_self.isa<Annotation>()">,
         "A Scala FIRRTL Compiler Annotation">;

def InlineAnnotation
  : Attr<CPred<"$_self.isa<InlineAnnotation>()">,
         "Indicate that a module should be inlined into its parent">;

def NoDedupAnnotation
  : Attr<CPred<"$_self.isa<NoDedupAnnotation>()">,
         "Indicate that a module should not be deduplicated">;

def RunFirrtlTransformAnnotation
  : Attr<CPred<"$_self.isa<RunFirrtlTransformAnnotation>()">,
         "Request that a specific custom transform be run">;

#endif // CIRCT_DIALECT_FIRRTL_ANNOTATIONS_TD
