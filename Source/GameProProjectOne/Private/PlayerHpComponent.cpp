// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHpComponent.h"

// Sets default values for this component's properties
UPlayerHpComponent::UPlayerHpComponent()
	: hp{ 0 }
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerHpComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerHpComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UPlayerHpComponent::operator+=(const int x) {
	return this->hp += x;
}

int UPlayerHpComponent::operator-=(const int x) {
	return this->hp -= x;
}

int UPlayerHpComponent::Get() const {
	return this->hp;
}