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

#ifndef FIRESTORE_CORE_TEST_UNIT_TESTUTIL_VALUES_H_
#define FIRESTORE_CORE_TEST_UNIT_TESTUTIL_VALUES_H_

#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Firestore/core/src/core/core_fwd.h"
#include "Firestore/core/src/model/field_value.h"
#include "Firestore/core/src/model/model_fwd.h"
#include "absl/strings/string_view.h"

#include "Firestore/core/src/nanopb/message.h"

namespace google {
    namespace firestore {
        namespace v1 {
            class Value;
        }
    }
}

namespace firebase {
class Timestamp;

namespace firestore {
class GeoPoint;

namespace model {
class FieldValue;
}
namespace nanopb {
class ByteString;
}


namespace testutil {
class ProtoValue {
 public:
  static google::firestore::v1::Value Wrap(std::nullptr_t);

  static google::firestore::v1::Value  Wrap(bool b);

  static google::firestore::v1::Value  Wrap(int64_t i);

  static google::firestore::v1::Value  Wrap(double d);

  // int64_t and double are equally good overloads for integer literals so this
  // avoids ambiguity
  static google::firestore::v1::Value  Wrap(int i);

  static google::firestore::v1::Value  Wrap(const char* s);

  static google::firestore::v1::Value  Wrap(const std::string& s);

  static google::firestore::v1::Value  Wrap(const Timestamp& ts);

  static google::firestore::v1::Value  Wrap(const nanopb::ByteString& blob);

  static google::firestore::v1::Value  Wrap(
      const model::FieldValue::Reference& ref);

  static google::firestore::v1::Value  Wrap(const GeoPoint& geo_point);

  static google::firestore::v1::Value  Wrap(
      const std::vector<model::FieldValue>& array);

  static google::firestore::v1::Value  Wrap(
      const std::unordered_map<std::string, model::FieldValue> map);
};

}  // namespace testutil

}  // namespace firestore
}  // namespace firebase

#endif  // FIRESTORE_CORE_TEST_UNIT_TESTUTIL_VALUES_H_