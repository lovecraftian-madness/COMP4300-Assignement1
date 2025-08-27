#ifndef ENTITY_HPP
#define ENTITY_HPP

#pragma once

#include "CQualities/CTransform.hpp"
#include "CQualities/CShape.hpp"

#include <tuple>
#include <string>

class Entity {
    using ComponentTuple = std::tuple<
        CTransform,
        CShape
    >;
    ComponentTuple m_components;
    bool m_alive = true;
    std::string m_tag = "default";
    size_t m_id = 0;
public:
    Entity();

    template<typename T, typename... TArgs>
    T& add(TArgs&& ... mArgs){
        auto &component=get<T>();
        component=T(std::forward<TArgs>(mArgs)...);
        component.exists=true;
        return component;
    };

    template <typename T>
    T& get(){
        return std::get<T>(m_components);
    };

    template <typename T>
    T& get() const{
        return std::get<T>(m_components);
    };

    size_t id() const;

    template<typename T>
    bool has() const{
        return get<T>().exists;
    }

    template <typename T>
    void remove(){
        get<T>()=T();
    };

    bool isAlive() const{
        return m_alive;
    };

    const std::string& tag() const{
        return m_tag;
    };

};
#endif