#include "EntityRenderer.h"

EntityRenderer::EntityRenderer()
{

}

EntityRenderer::~EntityRenderer()
{

}

void EntityRenderer::Work(const EntityRegistry& registry) const
{
	registry.RenderEntities();
}