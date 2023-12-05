#pragma once
#include <QPoint>
#include <QRect>
#include <QList>

#include "window/Window.h"
////
/// \brief The Glyph class
/// 图元有三个基本责任:
/// 1. 它们怎么画出自己->调用Window委托绘制
/// 2. 它们占多大空间
/// 3. 它们的父图元以及子图元是什么
///
class Glyph
{
public:
    Glyph();
    virtual ~Glyph();
    virtual void draw(Window*) = 0;
    virtual void insert(Glyph*, int index) = 0;
    virtual QRect& bounds() const = 0;
    virtual void remove(Glyph*) = 0;
    virtual Glyph* child(int index) = 0;
    virtual Glyph* parent() = 0;
    virtual bool intersects(const QPoint&) = 0;

protected:
    QList<Glyph*> _children;
    Glyph* _parent = nullptr;
};
