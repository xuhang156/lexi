#pragma once
#include <QPoint>
#include <QRect>
#include <QList>

class Glyph
{
public:
    Glyph();
    virtual ~Glyph();
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
