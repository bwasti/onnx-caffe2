#pragma once

#include "onnx.pb.h"

namespace onnx { namespace optimization {

struct Tensor {
private:
  bool is_segment_;
  int64_t segment_begin_;
  int64_t segment_end_;
  bool has_name_;
  std::string name_;
  onnx::TensorProto_DataType elem_type_;
  std::vector<int64_t> sizes_;

  std::vector<float> float_data_;
  std::vector<double> double_data_;
  std::vector<int32_t> int32_data_;
  std::vector<int64_t> int64_data_;
  std::vector<uint64_t> uint64_data_;
  std::vector<std::string> string_data_;

  bool is_raw_data_;
  std::string raw_data_;

public:
  Tensor()
  : is_segment_(false)
  , segment_begin_(0)
  , segment_end_(0)
  , has_name_(false)
  , elem_type_(onnx::TensorProto_DataType_UNDEFINED)
  , is_raw_data_(false)
  {}

  const std::vector<int64_t>& sizes() const {
    return sizes_;
  }
  std::vector<int64_t>& sizes() {
    return sizes_;
  }

  const onnx::TensorProto_DataType elem_type() const {
    return elem_type_;
  }

  onnx::TensorProto_DataType& elem_type() {
    return elem_type_;
  }

  std::vector<std::string>& strings() {
    return string_data_;
  }

  const std::vector<std::string>& strings() const {
    return string_data_;
  }

  std::vector<float>& floats() {
    return float_data_;
  }

  const std::vector<float>& floats() const {
    return float_data_;
  }

  std::vector<double>& doubles() {
    return double_data_;
  }

  const std::vector<double>& doubles() const {
    return double_data_;
  }

  std::vector<int32_t>& int32s() {
    return int32_data_;
  }

  const std::vector<int32_t>& int32s() const {
    return int32_data_;
  }

  std::vector<int64_t>& int64s() {
    return int64_data_;
  }

  const std::vector<int64_t>& int64s() const {
    return int64_data_;
  }

  std::vector<uint64_t>& uint64s() {
    return uint64_data_;
  }

  const std::vector<uint64_t>& uint64s() const {
    return uint64_data_;
  }

  const std::string& raw() const {
    return raw_data_;
  }

  void set_raw_data(const std::string& raw_data) {
    is_raw_data_ = true;
    raw_data_ = raw_data;
  }

  bool is_segment() const {
    return is_segment_;
  }

  int64_t segment_begin() const {
    return segment_begin_;
  }

  int64_t segment_end() const {
    return segment_end_;
  }

  void set_segment_begin_and_end(int64_t begin, int64_t end) {
    is_segment_ = true;
    segment_begin_ = begin;
    segment_end_ = end;
  }

  bool hasName() const {
    return has_name_;
  }

  const std::string& name() const {
    return name_;
  }

  void setName(const std::string& name) {
    has_name_ = true;
    name_ = name;
  }
};

}}
