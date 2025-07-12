// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeSpin.h"

// Sets default values
ACubeSpin::ACubeSpin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RotationSpeedX = 30.f;
	RotationSpeedY = 15.f;
	RotationSpeedZ = 0.f;
	VectorSpeed = FVector(30.f);
	
	VariavelInt = 1;
	bVariavelBool = false;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
    // RootComponent = CubeMesh;

}

// Called when the game starts or when spawned
void ACubeSpin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubeSpin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CubeMesh)
	{
		FRotator NewRotation = CubeMesh->GetComponentRotation();
		NewRotation.Yaw += RotationSpeedX * DeltaTime;
		NewRotation.Roll += RotationSpeedY * DeltaTime;
		NewRotation.Pitch += RotationSpeedZ * DeltaTime;
		CubeMesh->SetWorldRotation(NewRotation);
		//CubeMesh->SetRelativeRotation(NewRotation);
	}
}
