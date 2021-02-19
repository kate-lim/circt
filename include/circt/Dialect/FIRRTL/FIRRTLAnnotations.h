//===- FIRRTLAnnotations.h - FIRRTL Annotation ------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the annotations available to the MLIR implementation of
// FIRRTL.
//
//===----------------------------------------------------------------------===//

#ifndef CIRCT_DIALECT_FIRRTL_FIRRTLANNOTATIONS_H
#define CIRCT_DIALECT_FIRRTL_FIRRTLANNOTATIONS_H

#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "llvm/ADT/StringRef.h"

namespace circt {
namespace firrtl {

class Annotation : public mlir::Attribute::AttrBase<Annotation, mlir::Attribute,
                                                    mlir::AttributeStorage> {
public:
  using Base::Base;
};

class InlineAnnotation
    : public mlir::Attribute::AttrBase<InlineAnnotation, Annotation,
                                       mlir::AttributeStorage> {
  std::string className = "passes.InlineAnnotation";

public:
  using Base::Base;

  std::string getClassName() { return className; }
};

class NoDedupAnnotation
    : public mlir::Attribute::AttrBase<NoDedupAnnotation, Annotation,
                                       mlir::AttributeStorage> {
  std::string className = "transforms.NoDedupAnnotation";

public:
  using Base::Base;

  std::string getClassName() { return className; }
};

struct StringAttributeStorage : public mlir::AttributeStorage {

  StringAttributeStorage(std::string value) : value(value) {}

  using KeyTy = std::string;

  bool operator==(const KeyTy &key) const { return key == value; };

  static llvm::hash_code hashKey(const KeyTy &key) {
    return llvm::hash_value(key);
  };

  static KeyTy getKey(std::string value) { return value; };

  static StringAttributeStorage *
  construct(mlir::AttributeStorageAllocator &allocator, const KeyTy &key) {
    return new (allocator.allocate<StringAttributeStorage>())
        StringAttributeStorage(key);
  };

  std::string value;
};

class RunFirrtlTransformAnnotation
    : public mlir::Attribute::AttrBase<RunFirrtlTransformAnnotation, Annotation,
                                       StringAttributeStorage> {

  std::string className = "stage.RunFirrtlTransformAnnotation";

public:
  using Base::Base;

  static RunFirrtlTransformAnnotation get(mlir::MLIRContext *context,
                                          std::string value) {
    return Base::get(context, value);
  };

  std::string getClassName() { return className; }

  std::string getTransformName() { return getImpl()->value; }
};

} // namespace firrtl
} // namespace circt

#endif // CIRCT_DIALECT_FIRRTL_FIRRTLANNOTATIONS_H
