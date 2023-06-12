// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UtilityStructs.h"

#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"
#include "Stereolabs/Public/Core/StereolabsBaseTypes.h"

#include "PerfExporter.generated.h"

UCLASS()
class ZEDSAMPLES_API APerfExporter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerfExporter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool IsFileOpen() const;
	void CreateJSONFile(const std::string& file_path);
	void CloseFile();

	UFUNCTION()
	void Init();

	UFUNCTION(BlueprintCallable, Category = "Zed|Internal")
	bool IsInit();
	UFUNCTION(BlueprintCallable, Category = "Zed|Internal")
	void PushNewFrame(int FrameCount, FSlTimestamp TS, TMap<int, USkeletalMeshComponent*> Avatars, FSlPose CameraPose);

	UFUNCTION(BlueprintCallable, Category = "Zed|Internal")
	void Save();

	FPerfJsonData data;

	/* Must be the BP_BodyTrackingVisualizer actor*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ZED)
	AActor* BodyTrackingVisualizer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ZED)
	FString  JSONFilename = "perf_result.json";
private:

	void WriteString(const std::string& line) const;

	IFileHandle* log_file_handle_ = nullptr;

	bool is_init_ = false;

	int current_frame = -1;
};
