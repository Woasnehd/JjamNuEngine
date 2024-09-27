#include "JjamColliderManager.h"
#include "JjamScene.h"
#include "JjamSceneManager.h"
#include "JjamGameObject.h"
#include "JjamCollider.h"
#include "JjamTransform.h"
#include "JjamGameObject.h"

namespace Jjam {
	bitset<(UINT)enums::eLayerType::Max> ColliderManager::mCollisionLayerMatrix[(UINT)enums::eLayerType::Max] = {};
	unordered_map<UINT64, bool> ColliderManager::mCollisionMap = {};
	
	void ColliderManager::Initialize()
	{

	}

	void ColliderManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();

		for (UINT row = 0; row < (UINT)enums::eLayerType::Max; row++) {
			for (UINT col = 0; col < (UINT)enums::eLayerType::Max; col++) {
				if (mCollisionLayerMatrix[row][col] == true) {
					LayerCollision(scene, (enums::eLayerType)row, (enums::eLayerType)col);
				}
			}
		}
	}

	void ColliderManager::LateUpdate()
	{

	}

	void ColliderManager::Render(HDC hdc)
	{

	}

	void ColliderManager::CollisionLayerCheck(enums::eLayerType left, enums::eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right) {
			row = (UINT)left;
			col = (UINT)right;
		}
		else {
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}

	void ColliderManager::LayerCollision(Scene* scene, enums::eLayerType left, enums::eLayerType right)
	{
		const vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

		for (GameObject* left : lefts) {
			if (left->IsActive() == false) {
				continue;
			}

			Collider* leftCol = left->GetComponent<Collider>();

			if (leftCol == nullptr) {
				continue;
			}

			for (GameObject* right : rights) {
				Collider* rightCol = right->GetComponent<Collider>();

				if (right->IsActive() == false) {
					continue;
				}

				if (rightCol == nullptr) {
					continue;
				}

				if (left == right) {
					continue;
				}

				ColliderCollision(leftCol, rightCol);
			}
		}
	}
	void ColliderManager::ColliderCollision(Collider* left, Collider* right)
	{
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		auto it = mCollisionMap.find(id.id);
		if (it == mCollisionMap.end()) {
			mCollisionMap.insert(make_pair(id.id, false));
			it = mCollisionMap.find(id.id);
		}

		if (Intersect(left, right)) {
			if (it->second == false) {
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);

				it->second = true;
			}

			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}

		else
		{
			//충돌을 하지 않은 상태
			if (it->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
				it->second = false;
			}
		}
	}

	bool ColliderManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();
		Vector2 leftPos = leftTr->GetPosition() + left->GetOffSet();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffSet();

		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
			&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
		{
			return true;
		}

		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D
			&& rightType == enums::eColliderType::Rect2D)
		{
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
			{
				return true;
			}
		}

		if (leftType == enums::eColliderType::Circle2D
			&& rightType == enums::eColliderType::Circle2D)
		{
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);
			float distance = (leftCirclePos - rightCirclePos).Length();

			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			{
				return true;
			}
		}

		if ((leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D)
			|| (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D))
		{
			// circle - rect
			// 숙제
		}

		return false;
	}
}