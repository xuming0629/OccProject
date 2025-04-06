#pragma once
#include <TopAbs.hxx>
#include <TopoDS_Shape.hxx>

class ShapeBase {
public:
    // Ĭ�Ϲ��캯������ʼ�� m_shape Ϊһ������״
    ShapeBase() : m_shape(TopoDS_Shape()) {}

    // ������������ȷ����������������������
    virtual ~ShapeBase() = default;

    // ��ȡ��״�ӿ�
    virtual TopoDS_Shape GetShape() const = 0;

    // ����ͼ��ؽӿ�
    virtual bool Save(const std::string& filename) const = 0;
    virtual bool Load(const std::string& filename) = 0;

protected:
    TopoDS_Shape m_shape;  // ��״����
};
