#ifndef ETCL_INCLUDE_COMMON_H
#define ETCL_INCLUDE_COMMON_H

#pragma once

#include <cstddef>
#include <vector>
#include <map>
#include <optional>

namespace etcl
{

using std::size_t;

// forward edeclrations

class Interp;
class Value;
class String;
class Object;
class Slice;
class Parser;

/// @brief Status code of a command result
enum class Status
{
    Ok,     ///< Command returned correctly
    Error,  ///< Command had an unkown error
};

// typedefs

/// @brief A function pointer to a native command in C++ code
using NativeCmd = Status (*)(Interp* interpreter, Value* values, void* userdata);

using Number = int;

// todo -- make these generic

template<typename T> using Vector = std::pmr::vector;
template<typename K, typename V> using Map = std::pmr::map;
template<typename t> using Optional = std::optional;

};

#endif