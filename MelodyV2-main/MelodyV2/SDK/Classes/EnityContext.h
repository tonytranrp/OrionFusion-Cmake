#pragma once

#include "Entityid.h"
#include "Enityregistry.h"
#include "WeakPtr.h"
#include "ClientInstance.h"

#undef max
#include <entt/entity/registry.hpp>

#include <cstdint>
#include <optional>


class EntityContextBase
{
public:
	EntityRegistry* mRegistry = nullptr;
	entt::basic_registry<EntityId>* mEnttRegistry = nullptr;
	EntityId id{};
public:
	template<typename component_t>
	auto& assure_for(entt::basic_registry<EntityId>* registry)
	{
		return registry->storage<component_t>();
		/*using assure_t = entt::basic_storage<component_t, EntityId>* (__fastcall *)(const entt::basic_registry<EntityId>*, uint32_t);
		static auto assureFunc = reinterpret_cast<assure_t>(resolveAssureFunc<component_t>());

		return assureFunc(registry, entt::type_hash<component_t>::value());*/
	}
	[[nodiscard]] bool empty() const
	{
		return this->mRegistry == nullptr || this->mEnttRegistry == nullptr || this->id == entt::tombstone || this->id == entt::null;
	}

	template<typename component_t>
	[[nodiscard]] bool hasComponent() const
	{
		auto& storage = assure_for<component_t>(&this->mRegistry->mOwnedRegistry);
		return storage.contains(this->id);
	}

	template<typename component_t>
	component_t* tryGetComponent()
	{
		auto& storage = assure_for<component_t>(&this->mRegistry->mOwnedRegistry);
		if (storage.contains(this->id))
		{
			return std::addressof(storage.get(this->id));
		}
		return nullptr;
	}

	template<typename component_t, typename... args_t>
	auto getOrAddComponent(args_t... args)
	{
		if (auto& cpool = assure_for<component_t>(&this->mRegistry->mOwnedRegistry); cpool.contains(this->id)) {
			return cpool.get(this->id);
		}
		else {
			return cpool.emplace(this->id, std::forward<args_t>(args)...);
		}
	}

	template<typename component_t>
	void removeComponent()
	{
		auto& storage = assure_for<component_t>(&this->mRegistry->mOwnedRegistry);
		storage.remove(this->id);
	}
};

class EntityContext : public EntityContextBase
{
public:
};
static_assert(sizeof(EntityContext) == 0x18);
static_assert(sizeof(std::optional<EntityContext>) == 0x20);