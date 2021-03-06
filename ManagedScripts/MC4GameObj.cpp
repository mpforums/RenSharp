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
#include "MC4GameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <C4GameObj.h>
#include <C4GameObjDef.h>
#include <weaponmgr.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MSoldierGameObj.h"
#include "Mweaponmgr.h"
#include "MPlayerDataClass.h"
#include "MC4GameObjDef.h"

namespace RenSharp
{
	C4GameObj::C4GameObj(IntPtr pointer)
		: SimpleGameObj(pointer)
	{

	}

	IntPtr C4GameObj::C4GameObjPointer::get()
	{
		return IntPtr(InternalC4GameObjPointer);
	}

	IC4GameObjDef ^C4GameObj::Definition::get()
	{
		return safe_cast<IC4GameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalC4GameObjPointer->Get_Definition()));
	}

	IScriptableGameObj ^C4GameObj::StuckObject::get()
	{
		auto result = InternalC4GameObjPointer->Get_Stuck_Object();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	ISoldierGameObj ^C4GameObj::Owner::get()
	{
		auto result = InternalC4GameObjPointer->Get_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void C4GameObj::Owner::set(ISoldierGameObj ^value)
	{
		if (value == nullptr || value->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalC4GameObjPointer->Set_Owner(nullptr);
		}
		else
		{
			InternalC4GameObjPointer->Set_Owner(reinterpret_cast<::ScriptableGameObj *>(value->ScriptableGameObjPointer.ToPointer()));
		}
	}

	IAmmoDefinitionClass ^C4GameObj::AmmoDef::get()
	{
		auto defPtr = const_cast<::AmmoDefinitionClass *>(InternalC4GameObjPointer->Get_Ammo_Def());
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IAmmoDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	IPlayerDataClass ^C4GameObj::PlayerData::get()
	{
		auto result = InternalC4GameObjPointer->Get_Player_Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PlayerDataClass(IntPtr(result));
		}
	}

	void C4GameObj::PlayerData::set(IPlayerDataClass ^value)
	{
		if (value == nullptr || value->PlayerDataClassPointer.ToPointer() == nullptr)
		{
			InternalC4GameObjPointer->Set_Player_Data(nullptr);
		}
		else
		{
			InternalC4GameObjPointer->Set_Player_Data(reinterpret_cast<::PlayerDataClass *>(value->PlayerDataClassPointer.ToPointer()));
		}
	}

	int C4GameObj::DetonationMode::get()
	{
		return InternalC4GameObjPointer->Get_Detonation_Mode();
	}

	::SimpleGameObj *C4GameObj::InternalSimpleGameObjPointer::get()
	{
		return InternalC4GameObjPointer;
	}

	::C4GameObj *C4GameObj::InternalC4GameObjPointer::get()
	{
		return reinterpret_cast<::C4GameObj *>(Pointer.ToPointer());
	}
}