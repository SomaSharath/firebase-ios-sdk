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

#include "Firestore/core/test/unit/testutil/testutil.h"
#include "Firestore/Protos/cpp/google/firestore/v1/document.pb.h"

namespace firebase {
namespace firestore {
namespace testutil {

{

    namespace v1 = google::firestore::v1;
using nanopb::ByteString;

v1::Value ProtoValue::Wrap(std::nullptr_t) {
  ByteString bytes = EncodeFieldValue(FieldValue::Null());
  return ProtobufParse<v1::Value>(bytes);
}

v1::Value ProtoValue::Wrap(bool b) {
  ByteString bytes = EncodeFieldValue(FieldValue::FromBoolean(b));
  return ProtobufParse<v1::Value>(bytes);
}

v1::Value ProtoValue::Wrap(int64_t i) {
  ByteString bytes = EncodeFieldValue(FieldValue::FromInteger(i));
  return ProtobufParse<v1::Value>(bytes);
}

v1::Value ProtoValue::Wrap(double d) {
  ByteString bytes = EncodeFieldValue(FieldValue::FromDouble(d));
  return ProtobufParse<v1::Value>(bytes);
}

v1::Value ProtoValue::Wrap(int i) {
  return Wrap(static_cast<int64_t>(i));
}

v1::Value ProtoValue::Wrap(const char* s) {
  return Wrap(std::string(s));
}

v1::Value ProtoValue::Wrap(const std::string& s) {
  ByteString bytes = EncodeFieldValue(FieldValue::FromString(s));
  return ProtobufParse<v1::Value>(bytes);
}

v1::Value ProtoValue::Wrap(const Timestamp& ts) {
  ByteString bytes = EncodeFieldValue(FieldValue::FromTimestamp(ts));
  return ProtobufParse<v1::Value>(bytes);
}

v1::Value ProtoValue::Wrap(const ByteString& blob) {
  ByteString bytes = EncodeFieldValue(FieldValue::FromBlob(blob));
  return ProtobufParse<v1::Value>(bytes);
}

v1::Value ProtoValue::WrapReference(
    const FieldValue::Reference& ref) {
  ByteString bytes =
      EncodeFieldValue(FieldValue::FromReference(ref.database_id(), ref.key()));
  return ProtobufParse<v1::Value>(bytes);
}

v1::Value ProtoValue::Wrap(const GeoPoint& geo_point) {
  ByteString bytes = EncodeFieldValue(FieldValue::FromGeoPoint(geo_point));
  return ProtobufParse<v1::Value>(bytes);
}

v1::Value ProtoValue::Wrap(const std::vector<FieldValue>& array) {
  ByteString bytes = EncodeFieldValue(FieldValue::FromArray(array));
  return ProtobufParse<v1::Value>(bytes);
}

v1::Value ProtoValue::Wrap(const FieldValue::Map& map) {
  ByteString bytes = EncodeFieldValue(FieldValue::FromMap(map));
  return ProtobufParse<v1::Value>(bytes);
}
}  // namespace
}  // namespace testutil
}  // namespace firestore
}  // namespace firebase