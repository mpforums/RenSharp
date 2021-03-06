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
#include "Mda_gamespy.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamespy.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAGameSpyGameFeatureClass::DAGameSpyGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DAGameSpyGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAGameSpyGameFeatureClass::Equals(Object^ other)
	{
		if (DAEventClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherDAGameFeatureClass = dynamic_cast<IDAGameFeatureClass^>(other);
		if (otherDAGameFeatureClass != nullptr)
		{
			if (daGameFeatureClass->Equals(otherDAGameFeatureClass))
			{
				return true;
			}
		}

		auto otherDAGameSpyGameFeatureClass = dynamic_cast<IDAGameSpyGameFeatureClass^>(other);
		if (otherDAGameSpyGameFeatureClass != nullptr)
		{
			if (DAGameSpyGameFeatureClassPointer.Equals(otherDAGameSpyGameFeatureClass->DAGameSpyGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAGameSpyGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAGameSpyGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DAGameSpyGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAGameSpyGameFeatureClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			daGameFeatureClass = nullptr;
		}
		else
		{
			daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
		}
	}

	IntPtr DAGameSpyGameFeatureClass::DAGameSpyGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameSpyGameFeatureClassPointer);
	}

	IntPtr DAGameSpyGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAGameSpyGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAGameSpyGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAGameSpyGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAGameSpyGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAGameSpyGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAGameSpyGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAGameSpyGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAGameSpyGameFeatureClassPointer;
	}

	::DAGameSpyGameFeatureClass* DAGameSpyGameFeatureClass::InternalDAGameSpyGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAGameSpyGameFeatureClass*>(Pointer.ToPointer());
	}
}