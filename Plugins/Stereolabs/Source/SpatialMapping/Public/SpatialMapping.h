//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Modules/ModuleManager.h"

class FStereolabsSpatialMapping : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};