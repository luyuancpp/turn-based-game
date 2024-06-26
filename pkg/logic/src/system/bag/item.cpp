#include "item.h"


NodeBit12Sequence g_bag_node_sequence;

void BagEntityPtrDeleter(entt::entity* p)
{
	Destroy(tls.item_registry, *p);
	delete p;
}

ItemEntity::ItemEntity() : entity_(new entt::entity(tls.item_registry.create()), BagEntityPtrDeleter) {}

Item CreateItem(const CreateItemParam& p)
{
	Item item;
	tls.item_registry.emplace<ItemBaseDb>(item.entity(), p.item_base_db);
	return item;
}

