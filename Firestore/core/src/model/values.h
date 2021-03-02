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

#include "Firestore/core/src/model/values.h"

namespace firebase {
namespace firestore {
namespace model {

int32_t Values::GetTypeOrder(const google_firestore_v1_Value& value) {
  return 0;
}

boolean Values::Equals(const google_firestore_v1_Value& left,
                       const google_firestore_v1_Value& right) {
  return false;
}

int32_t Values::Compare(const google_firestore_v1_Value& left,
                        const google_firestore_v1_Value& right) {
  return 0;
}

std::string Values::CanonicalId(const google_firestore_v1_Value& value) {
  return "";
}

class Values {
 public:
  /** Returns the backend's type order of the given Value type. */
  static int32_t GetTypeOrder(const google_firestore_v1_Value& value);

  static boolean Equals(const google_firestore_v1_Value& left,
                        const google_firestore_v1_Value& right);

  static int32_t Compare(const google_firestore_v1_Value& left,
                         const google_firestore_v1_Value& right);

  /** Generate the canonical ID for the provided field value (as used in Target
   * serialization). */
  static std::string CanonicalId(const google_firestore_v1_Value& value);

 private:
  Values() = default;
};

}  // namespace model
}  // namespace firestore
}  // namespace firebase
