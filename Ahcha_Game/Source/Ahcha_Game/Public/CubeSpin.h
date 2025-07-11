// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeSpin.generated.h"

UCLASS()
class AHCHA_GAME_API ACubeSpin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeSpin();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spin")
	UStaticMeshComponent* CubeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spin")
	FVector VectorSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spin")
	float RotationSpeedX;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spin", meta=(ClampMin="0", ClampMax="360"))
	float RotationSpeedY;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spin", meta=(ClampMin="0", ClampMax="360"))
	float RotationSpeedZ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spin")
	int32 VariavelInt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spin")
	bool bVariavelBool;

	
protected:

	virtual void BeginPlay() override;

private:

};
