/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef CYBERTRON_TOOLS_CYBER_RECORDER_SPLITER_H_
#define CYBERTRON_TOOLS_CYBER_RECORDER_SPLITER_H_

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "cybertron/common/log.h"
#include "cybertron/proto/record.pb.h"
#include "cybertron/record/header_builder.h"
#include "cybertron/record/record_file.h"

using ::apollo::cybertron::proto::Header;
using ::apollo::cybertron::proto::ChunkHeader;
using ::apollo::cybertron::proto::ChunkBody;
using ::apollo::cybertron::proto::ChannelCache;

namespace apollo {
namespace cybertron {
namespace record {

class Spliter {
 public:
  Spliter(const std::string& input_file, const std::string& output_file,
          bool all_channels, const std::vector<std::string>& channel_vec,
          uint64_t begin_time = 0, uint64_t end_time = UINT64_MAX);
  virtual ~Spliter();
  bool Proc();

 private:
  RecordFileReader reader_;
  RecordFileWriter writer_;
  std::string input_file_;
  std::string output_file_;
  std::vector<std::string> channel_vec_;
  bool all_channels_;
  uint64_t begin_time_;
  uint64_t end_time_;
};

}  // namespace record
}  // namespace cybertron
}  // namespace apollo

#endif  // CYBERTRON_TOOLS_CYBER_RECORDER_SPLITER_H_
