#include "EntityRenderer.h"

EntityRenderer::EntityRenderer()
{

}

EntityRenderer::~EntityRenderer()
{

}

void EntityRenderer::Work(EntityRegistry& registry)
{
	registry.RenderEntities();
}