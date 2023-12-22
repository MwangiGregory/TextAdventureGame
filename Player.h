#pragma once

#include <string>
#include "Entity.h"

class Player : public Entity
{
private:
    std::string m_name;

public:
    
    const std::string& GetName() const
    {
        return m_name;
    }

    void SetName(const std::string& name)
    {
        m_name = name;
    }
};