# 📷 Unreal Engine Dynamic Auto-Focus Camera System (UE5)

A lightweight, performant **C++** and **Blueprint-compatible** Auto-Focus System for Unreal Engine 5. This project uses continuous single-channel Line Tracing combined with smoothly interpolated focus distance updates (`FInterpTo`) on a `CineCameraComponent` to simulate realistic camera focus dynamics.

---

## 🌟 Key Features

* 🎯 **Real-Time Auto-Focus:** Automatically tracks object depth along the camera's view vector in real-time.
* 🎬 **Cinematic Depth of Field:** Built natively around the UE5 `CineCameraComponent` for photorealistic bokeh and aperture control.
* ⚡ **Optimized C++ Core:** Native C++ implementation ensuring minimal CPU overhead on tick.
* 📈 **Smooth Focus Interpolation:** Prevents sudden depth-of-field pops using customizable interpolation speeds (`FInterpTo`).
* 🎛️ **Editor Friendly:** Fully exposed parameters to the Unreal Details Panel for fast iteration without recompiling.

---

## 💻 Source Code

### `AutoCameraActor.h`

```cpp
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CineCameraComponent.h"
#include "AutoCameraActor.generated.h"

UCLASS()
class YOURPROJECT_API AAutoCameraActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAutoCameraActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// --- COMPONENTS ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCineCameraComponent* CineCameraComp;

	// --- AUTO FOCUS SETTINGS ---
	
	/** Toggles dynamic auto focus system */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Focus")
	bool bEnableAutoFocus = true;

	/** Maximum trace distance in Unreal Units (cm) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Focus", meta = (EditCondition = "bEnableAutoFocus"))
	float TraceDistance = 10000.0f;

	/** Speed of focus transition (Higher = Snappier) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Focus", meta = (EditCondition = "bEnableAutoFocus"))
	float FocusInterpSpeed = 5.0f;

	/** Fallback focus distance when line trace hits nothing */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Focus", meta = (EditCondition = "bEnableAutoFocus"))
	float DefaultFocusDistance = 5000.0f;

	/** Enable visual line trace debug ray */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Auto Focus")
	bool bShowDebugTrace = false;

private:
	void UpdateAutoFocus(float DeltaTime);
};
