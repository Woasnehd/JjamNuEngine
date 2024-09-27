#include "JjamCollider.h"
#include "JjamScript.h"
#include "JjamGameObject.h"

namespace Jjam {
    UINT32 Collider::mCollisionID = 1;

    Collider::Collider(enums::eColliderType type)
        :Component(enums::eComponentType::Collider)
        , mType(type)
        , mOffset(math::Vector2::Zero)
        , mID(mCollisionID++)
        , mSize(math::Vector2::One)
    {

    }

    Collider::~Collider()
    {

    }

    void Collider::Initialize()
    {

    }

    void Collider::Update()
    {

    }

    void Collider::LateUpdate()
    {

    }

    void Collider::Render(HDC hdc)
    {

    }

    void Collider::OnCollisionEnter(Collider* other)
    {
        Script* script = GetOwner()->GetComponent<Script>();
        script->OnCollisionEnter(other);
    }

    void Collider::OnCollisionStay(Collider* other)
    {
        Script* script = GetOwner()->GetComponent<Script>();
        script->OnCollisionStay(other);
    }

    void Collider::OnCollisionExit(Collider* other)
    {
        Script* script = GetOwner()->GetComponent<Script>();
        script->OnCollisionExit(other);
    }
}