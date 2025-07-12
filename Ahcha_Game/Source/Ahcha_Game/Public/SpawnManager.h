#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "SpawnManager.generated.h"

UCLASS()
class AHCHA_GAME_API ASpawnManager : public AActor
{
	GENERATED_BODY()
public:
	ASpawnManager();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Classe do actor a ser spawnado
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AActor> SpawnCubeClass;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	UStaticMeshComponent* MeshComponent;
		  
	// Array com as posições X possíveis
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TArray<float> PossiveisPosicoesX;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	float TimeOutDificuldade; 

private:
	FTimerHandle SpawnTimerHandle;
	void SpawnCubeActor();
    
	// Valor inicial do TimeOut
	float CurrentTimeOut;
    
	// Valor mínimo que o TimeOut pode atingir
	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	float MinTimeOut = 1.0f;
    
	// Quanto o tempo diminui a cada spawn
	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	float TimeOutDecrement = 0.2f;
};