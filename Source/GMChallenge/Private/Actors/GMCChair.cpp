
#include "Actors/GMCChair.h"

void AGMCChair::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer.Reset();
	TagContainer.AppendTags(GameplayTagContainer);
}