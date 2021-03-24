#include "RegistryMember.h"

RegistryMember::RegistryMember()
{

}

RegistryMember::~RegistryMember()
{

}

bool RegistryMember::IsFlaggedForRemoval() const
{
	return isFlaggedForRemoval;
}

void RegistryMember::FlagForRemoval(const bool& flag)
{
	isFlaggedForRemoval = flag;
}

void RegistryMember::SetDeleteQueue(const std::shared_ptr<std::queue<int>> dQueue)
{
	deleteQueue = dQueue;
}