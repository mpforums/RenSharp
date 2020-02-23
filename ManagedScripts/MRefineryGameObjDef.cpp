/*
Copyright 2020 Neijwiert

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "stdafx.h"
#include "MRefineryGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <RefineryGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	RefineryGameObjDef::RefineryGameObjDef(IntPtr pointer)
		: BuildingGameObjDef(pointer)
	{

	}

	IntPtr RefineryGameObjDef::RefineryGameObjDefPointer::get()
	{
		return IntPtr(InternalRefineryGameObjDefPointer);
	}

	float RefineryGameObjDef::UnloadTime::get()
	{
		return InternalRefineryGameObjDefPointer->UnloadTime;
	}

	void RefineryGameObjDef::UnloadTime::set(float value)
	{
		InternalRefineryGameObjDefPointer->UnloadTime = value;
	}

	float RefineryGameObjDef::FundsGathered::get()
	{
		return InternalRefineryGameObjDefPointer->FundsGathered;
	}

	void RefineryGameObjDef::FundsGathered::set(float value)
	{
		InternalRefineryGameObjDefPointer->FundsGathered = value;
	}

	float RefineryGameObjDef::FundsDistributedPerSec::get()
	{
		return InternalRefineryGameObjDefPointer->FundsDistributedPerSec;
	}

	void RefineryGameObjDef::FundsDistributedPerSec::set(float value)
	{
		InternalRefineryGameObjDefPointer->FundsDistributedPerSec = value;
	}

	int RefineryGameObjDef::HarvesterDefID::get()
	{
		return InternalRefineryGameObjDefPointer->HarvesterDefID;
	}

	void RefineryGameObjDef::HarvesterDefID::set(int value)
	{
		InternalRefineryGameObjDefPointer->HarvesterDefID = value;
	}

	::BuildingGameObjDef *RefineryGameObjDef::InternalBuildingGameObjDefPointer::get()
	{
		return InternalRefineryGameObjDefPointer;
	}

	::RefineryGameObjDef *RefineryGameObjDef::InternalRefineryGameObjDefPointer::get()
	{
		return reinterpret_cast<::RefineryGameObjDef *>(Pointer.ToPointer());
	}
}