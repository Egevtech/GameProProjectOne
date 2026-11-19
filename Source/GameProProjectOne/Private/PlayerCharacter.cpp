#include "PlayerCharacter.h"
#include "Collectbles/CoinCollectable.h"
#include "Collectbles/HealthCollectable.h"

void APlayerCharacter::OnPeekUp(const ACollectable* pCollectable)
{
	if (auto* ptr = Cast<ACoinCollectable>(pCollectable))
	{
		m_Score += ptr->m_Value;
	}
	if (auto* ptr = Cast<AHealthCollectable>(pCollectable))
	{
		m_Health += ptr->m_Value;
	}
}