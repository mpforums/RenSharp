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
#include "MRepairBayGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <RepairBayGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	RepairBayGameObjDef::RepairBayGameObjDef(IntPtr pointer)
		: BuildingGameObjDef(pointer)
	{

	}

	IntPtr RepairBayGameObjDef::RepairBayGameObjDefPointer::get()
	{
		return IntPtr(InternalRepairBayGameObjDefPointer);
	}

	float RepairBayGameObjDef::RepairPerSec::get()
	{
		return InternalRepairBayGameObjDefPointer->RepairPerSec;
	}

	void RepairBayGameObjDef::RepairPerSec::set(float value)
	{
		InternalRepairBayGameObjDefPointer->RepairPerSec = value;
	}

	int RepairBayGameObjDef::RepairingStaticAnimDefID::get()
	{
		return InternalRepairBayGameObjDefPointer->RepairingStaticAnimDefID;
	}

	void RepairBayGameObjDef::RepairingStaticAnimDefID::set(int value)
	{
		InternalRepairBayGameObjDefPointer->RepairingStaticAnimDefID = value;
	}

	::BuildingGameObjDef *RepairBayGameObjDef::InternalBuildingGameObjDefPointer::get()
	{
		return InternalRepairBayGameObjDefPointer;
	}

	::RepairBayGameObjDef *RepairBayGameObjDef::InternalRepairBayGameObjDefPointer::get()
	{
		return reinterpret_cast<::RepairBayGameObjDef *>(Pointer.ToPointer());
	}
}