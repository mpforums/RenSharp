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
#include "MSamSiteGameObj.h"

#include "MSamSiteGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SamSiteGameObj.h>
#include <SamSiteGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	SAMSiteGameObj::SAMSiteGameObj(IntPtr pointer)
		: SmartGameObj(pointer)
	{

	}

	IntPtr SAMSiteGameObj::SAMSiteGameObjPointer::get()
	{
		return IntPtr(InternalSAMSiteGameObjPointer);
	}

	ISAMSiteGameObjDef^ SAMSiteGameObj::Definition::get()
	{
		return safe_cast<ISAMSiteGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalSAMSiteGameObjPointer->Get_Definition()));
	}

	::SmartGameObj* SAMSiteGameObj::InternalSmartGameObjPointer::get()
	{
		return InternalSAMSiteGameObjPointer;
	}

	::SAMSiteGameObj* SAMSiteGameObj::InternalSAMSiteGameObjPointer::get()
	{
		return reinterpret_cast<::SAMSiteGameObj*>(Pointer.ToPointer());
	}
}