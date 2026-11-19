// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameProProjectOneCharacter.h"

#include "PlayerCharacter.generated.h"

class ACollectable;

/**
 * 
 */
UCLASS()
class GAMEPROPROJECTONE_API APlayerCharacter : public AGameProProjectOneCharacter
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "Player")
	uint32 m_Health = 100;

	UPROPERTY(EditAnywhere, Category = "Player")
	uint32 m_Score = 0;

public:

	UFUNCTION(BlueprintCallable, Category = "Player")
	void OnPeekUp(const ACollectable* pCollectable);
};
