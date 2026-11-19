// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Collectable.generated.h"

class UCapsuleComponent;

UCLASS()
class GAMEPROPROJECTONE_API ACollectable : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACollectable();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_pMesh;

	UPROPERTY(EditAnywhere)
	UCapsuleComponent* m_pCollider;

	UPROPERTY(EditAnywhere, Category = "Collectable")
	float m_RotateSpeed = 120.0f;

	UPROPERTY(EditAnywhere, Category = "Collectable")
	bool m_bLevitate = true;

	UPROPERTY(EditAnywhere, Category = "Collectable")
	float m_LevitateRange = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Collectable")
	float m_LevitateSpeed = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Collectable")
	float m_LevitateNoise = FMath::FRand() * 100;

	UPROPERTY(EditAnywhere, Category = "Collectable")
	uint32 m_Value = 1;

protected:
	float m_LevitateCounter = 0.0f;
	float m_PositionOffset = 0.0f;

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

public:
	virtual void Tick(float DeltaTime) override;
};
