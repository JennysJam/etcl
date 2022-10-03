#ifndef ETCL_INCLUDE_INTERP_H
#define ETCL_INCLUDE_INTERP_H
#pragma once

#include <etcl/common.h>
#include <etcl/Value.h>
#include <etcl/Parser.h>

#include <optional>
#include <vector>
#include <map>

namespace etcl
{

class Interp final
{
public:
    Interp() noexcept = default;
    ~Interp() noexcept = default;

    bool init();
    bool cleanup();

    Status exec(const char* string);
    Optional<Value> eval(const char* string);

    bool register_cmd(NativeCmd, void* userdata);

private:
    Parser parser;
};

};

#endif