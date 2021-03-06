/**
 * Copyright 2004-present, Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <perfevents/detail/RLimits.h>

namespace facebook {
namespace perfevents {
namespace detail {

rlimit getrlimit(int resource) {
  rlimit res{};
  if (getrlimit(resource, &res) != 0) {
    throw std::system_error(errno, std::system_category());
  }
  return res;
}

void setrlimit(int resource, const rlimit& limits) {
  if (setrlimit(resource, &limits) != 0) {
    throw std::system_error(errno, std::system_category());
  }
}

} // namespace detail
} // namespace perfevents
} // namespace facebook
