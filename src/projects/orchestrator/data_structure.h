//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Hyunjun Jang
//  Copyright (c) 2019 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

#include <base/info/info.h>
#include <base/ovlibrary/ovlibrary.h>

enum class OrchestratorModuleType
{
	Unknown,
	Provider,
	MediaRouter,
	Transcoder,
	Publisher
};

const char *GetOrchestratorModuleTypeName(OrchestratorModuleType type);

class OrchestratorModuleInterface : public ov::EnableSharedFromThis<OrchestratorModuleInterface>
{
public:
	virtual OrchestratorModuleType GetModuleType() const = 0;
};

class OrchestratorProviderModuleInterface : public OrchestratorModuleInterface
{
public:
	OrchestratorModuleType GetModuleType() const override
	{
		return OrchestratorModuleType::Provider;
	}

	/// Callend when another module is requested to pull stream
	///
	/// @param from The module that requested the pull
	/// @param url The streaming URL to pull
	/// @return Returns true if successfully pulled and finishes creating the stream, false otherwise
	virtual bool PullStream(const ov::String &url) = 0;
};

class OrchestratorMediaRouterModuleInterface : public OrchestratorModuleInterface
{
public:
	OrchestratorModuleType GetModuleType() const override
	{
		return OrchestratorModuleType::MediaRouter;
	}
};

class OrchestratorTranscoderModuleInterface : public OrchestratorModuleInterface
{
public:
	OrchestratorModuleType GetModuleType() const override
	{
		return OrchestratorModuleType::Transcoder;
	}
};

class OrchestratorPublisherModuleInterface : public OrchestratorModuleInterface
{
public:
	OrchestratorModuleType GetModuleType() const override
	{
		return OrchestratorModuleType::Publisher;
	}
};