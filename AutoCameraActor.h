#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CineCameraComponent.h"
#include "AutoCameraActor.generated.h"

UCLASS()
class YOURPROJECT_API AAutoCameraActor : public AActor // <-- YOURPROJECT_API kısmını KENDİ PROJE ADINIZ_API yapın!
{
	GENERATED_BODY()
	
public:	
	AAutoCameraActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// --- BİLEŞENLER ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCineCameraComponent* CineCameraComp;

	// --- OTOMATİK ODAKLAMA AYARLARI ---
	
	/** Otomatik odaklamayı açar / kapatır */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Focus")
	bool bEnableAutoFocus = true;

	/** Taranacak maksimum mesafe (cm) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Focus", meta = (EditCondition = "bEnableAutoFocus"))
	float TraceDistance = 10000.0f;

	/** Odaklanma hızı (Yüksek = Daha hızlı) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Focus", meta = (EditCondition = "bEnableAutoFocus"))
	float FocusInterpSpeed = 5.0f;

	/** Çizgi bir şeye çarpmadığında varsayılan odak mesafesi */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Focus", meta = (EditCondition = "bEnableAutoFocus"))
	float DefaultFocusDistance = 5000.0f;

	/** Görsel izleme çizgisini (Debug Ray) aktif eder */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Focus")
	bool bShowDebugTrace = false;

private:
	void UpdateAutoFocus(float DeltaTime);
};
