// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	// Opcional: Definir um mesh padrao (ex: Cube)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}
	
	// Inicializa o array com as posições X
	PossiveisPosicoesX.Add(-15.0f);
	PossiveisPosicoesX.Add(-155.0f);
	PossiveisPosicoesX.Add(-295.0f);

	TimeOutDificuldade = 6.;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
    
	// Inicializa o CurrentTimeOut com o valor do TimeOutDificuldade
	CurrentTimeOut = TimeOutDificuldade;
    
	// Chama a função SpawnCubeActor
	ASpawnManager::SpawnCubeActor();
	//GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnManager::SpawnCubeActor, TimeOutDificuldade, true);
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnManager::SpawnCubeActor()
{
    UWorld* World = GetWorld();
    if (World && SpawnCubeClass)
    {
    	FVector Location = GetActorLocation();
        
    	int32 IndiceAleatorio = FMath::RandRange(0, PossiveisPosicoesX.Num() - 1);
    	Location.X = PossiveisPosicoesX[IndiceAleatorio];
        
    	FRotator Rotation = GetActorRotation();
    	World->SpawnActor<AActor>(SpawnCubeClass, Location, Rotation);
        
    	// Diminui o tempo para o próximo spawn
    	CurrentTimeOut = FMath::Max(CurrentTimeOut - TimeOutDecrement, MinTimeOut);
        
    	// Configura o próximo timer com o novo tempo
    	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnManager::SpawnCubeActor, CurrentTimeOut, false);
    }

}