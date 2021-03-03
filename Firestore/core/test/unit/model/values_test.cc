/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Firestore/core/src/model/transform_operation.h"

#include "Firestore/core/src/model/values.h.h"
#include "Firestore/core/test/unit/testutil/equals_tester.h"
#include "Firestore/core/test/unit/testutil/testutil.h"
#include "Firestore/core/test/unit/testutil/proto_value.h"
#include "gtest/gtest.h"

namespace firebase {
namespace firestore {
namespace model {

using testutil::Value;
using testutil::ProtoValue;

using Type = TransformOperation::Type;

TEST(ValuesTest, Equality) {
  // Avoid statically dividing by zero; MSVC considers this an error.
  double zero = 0.0;
  testutil::EqualsTester<google_firestore_v1_Value>()
      .AddEqualityGroup(Wrap(nullptr), Wrap(nullptr))
      .AddEqualityGroup(Wrap(false), Wrap(false))
      .AddEqualityGroup(Wrap(true), Wrap(true))
      .AddEqualityGroup(Wrap(0.0 / zero), Wrap(ToDouble(kCanonicalNanBits)),
                        Wrap(ToDouble(kAlternateNanBits)), Wrap(std::nan("1")),
                        Value(std::nan("2")))
      // -0.0 and 0.0 compare the same but are not equal.
      .AddEqualityGroup(Wrap(-0.0))
      .AddEqualityGroup(Wrap(0.0))
      .AddEqualityGroup(Wrap(1), Wrap(1LL))
      // Doubles and Longs aren't equal (even though they compare same).
      .AddEqualityGroup(Wrap(1.0), Wrap(1.0))
      .AddEqualityGroup(Wrap(1.1), Wrap(1.1))
      .AddEqualityGroup(WrapBlob(0, 1, 1))
      .AddEqualityGroup(WrapBlob(0, 1))
      .AddEqualityGroup(Wrap("string"), Wrap("string"))
      .AddEqualityGroup(Wrap("strin"))
      // latin small letter e + combining acute accent
      .AddEqualityGroup(Wrap("e\u0301b"))
      // latin small letter e with acute accent
      .AddEqualityGroup(Wrap("\u00e9a"))
      .AddEqualityGroup(Wrap(Timestamp::FromTimePoint(kDate1)),
                        Wrap(kTimestamp1))
      .AddEqualityGroup(Wrap(Timestamp::FromTimePoint(kDate2)),
                        Wrap(kTimestamp2))
      // NOTE: ServerTimestampValues can't be parsed via Value().
      .AddEqualityGroup(FieldValue::FromServerTimestamp(kTimestamp1),
                        FieldValue::FromServerTimestamp(kTimestamp1))
      .AddEqualityGroup(FieldValue::FromServerTimestamp(kTimestamp2))
      .AddEqualityGroup(Wrap(0, 1), Wrap(0, 1))
      .AddEqualityGroup(WrapGeoPoint(1, 0))
      .AddEqualityGroup(WrapReference(DbId(), Key("coll/doc1")),
                        WrapReference(DbId(), Key("coll/doc1")))
      .AddEqualityGroup(WrapReference(DbId("project/bar"), Key("coll/doc2")))
      .AddEqualityGroup(WrapReference(DbId("project/baz"), Key("coll/doc2")))
      .AddEqualityGroup(Wrap("foo", "bar"), Wrap("foo", "bar"))
      .AddEqualityGroup(Wrap("foo", "bar", "baz"))
      .AddEqualityGroup(Wrap("foo"))
      .AddEqualityGroup(Wrap("bar", 1, "foo", 2), Wrap("foo", 2, "bar", 1))
      .AddEqualityGroup(Wrap("bar", 2, "foo", 1))
      .AddEqualityGroup(Wrap("bar", 1))
      .AddEqualityGroup(Wrap("foo", 1))
      .TestEquals();
}

TEST(ValuesTest, Ordering) {
}

TEST(ValuesTest, CanonicalId) {
}

<template typename=T>
google_firestore_v1_Value Wrap(T input) {
    // TODO: Magic
    return static_cast<google_firestore_v1_Value>(ProtoValue::Wrap(input));
}

}  // namespace model
}  // namespace firestore
}  // namespace firebase
