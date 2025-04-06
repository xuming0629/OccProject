#pragma once
#include <TopAbs.hxx>
#include <TopoDS_Shape.hxx>

class ShapeBase {
public:
    // 默认构造函数：初始化 m_shape 为一个空形状
    ShapeBase() : m_shape(TopoDS_Shape()) {}

    // 虚析构函数，确保派生类析构函数被调用
    virtual ~ShapeBase() = default;

    // 获取形状接口
    virtual TopoDS_Shape GetShape() const = 0;

    // 保存和加载接口
    virtual bool Save(const std::string& filename) const = 0;
    virtual bool Load(const std::string& filename) = 0;

protected:
    TopoDS_Shape m_shape;  // 形状数据
};
