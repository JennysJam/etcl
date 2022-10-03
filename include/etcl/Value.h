#ifndef ETCL_INCLUDE_VALUE_H
#define ETCL_INCLUDE_VALUE_H

#pragma once

#include <etcl/common.h>
#include <etcl/Interp.h>

#include <optional>

namespace etcl
{

/// @brief A smart pointer that is used to interact with ETCL values
class Value final
{
public:
    Value(Object& object);
    ~Value();
    Value(const Value& copee);
    Value(Value&& movee);
    Value& operator=(const Value& copee);
    Value& operator=(Value&& movee);
    
    // method accessors
    
    String& as_string();
    const String& as_string() const;
    Optional<Number> as_number() const;
    const Vector<Value>* as_list() const;
    Optional<Value> list_index(int index);



private:
    Object* object_ptr;
    
    void increment_rc();
    void decrement_rc();


};

};


#endif