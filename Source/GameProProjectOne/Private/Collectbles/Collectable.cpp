#include "Collectbles/Collectable.h"
#include "PlayerCharacter.h"
#include "Components/CapsuleComponent.h"

ACollectable::ACollectable()
{
	PrimaryActorTick.bCanEverTick = true;
	m_pCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	SetRootComponent(m_pCollider);

	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_pMesh->SetupAttachment(m_pCollider);
	m_pMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	m_pCollider->OnComponentBeginOverlap.AddDynamic(this, &ACollectable::OnOverlapBegin);
}

void ACollectable::BeginPlay()
{
	Super::BeginPlay();
}

void ACollectable::OnOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (this != otherActor)
	{
		auto* ptr = Cast<APlayerCharacter>(otherActor);
		if (ptr)
		{
			ptr->OnPeekUp(this);
			Destroy();
		}
	}
}

void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FRotator rotate = FRotator{ 0.0f, m_RotateSpeed, 0.0f } * DeltaTime;
	m_pMesh->AddWorldRotation(rotate);

	if (m_bLevitate)
	{
		m_LevitateCounter += DeltaTime;
		m_PositionOffset = cos(m_LevitateSpeed * m_LevitateCounter + m_LevitateNoise) * m_LevitateRange;
		const FVector pos{
		0.0f, 0.0f, m_PositionOffset
		};
		m_pMesh->SetRelativeLocation(pos);
	}
}