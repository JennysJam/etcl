#ifndef ETCL_INCLUDE_PARSER_H
#define ETCL_INCLUDE_PARSER_H

#pragma once

#include <etcl/common.h>

namespace etcl
{

enum class TokenType
{
    Command,
    String,
    Error,
    EOF
};


struct Token final
{
    TokenType type;
    char* text;
    int len;
    int line;
};

class Parser final
{
public:
    Parser() noexcept = default;
    ~Parser() noexcept = default;

    void init(char* data, size_t length);
    Token next();
    Token current();
    Token peek();
    bool expect(TokenType type);

private:
    char* pointer;
    size_t length;
    int line;
};

};

#endif