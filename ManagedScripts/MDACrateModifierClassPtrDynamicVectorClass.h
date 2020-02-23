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

#pragma once

#include "Mengine_vector.h"

#pragma managed(push, off)

class DACrateModifierClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDACrateModifierClass;

	public ref class DACrateModifierClassPtrDynamicVectorClass : public DynamicVectorClass<IDACrateModifierClass ^>
	{
		private:
			DACrateModifierClassPtrDynamicVectorClass();
			DACrateModifierClassPtrDynamicVectorClass(int size);

		public:
			DACrateModifierClassPtrDynamicVectorClass(IntPtr pointer);

			static IUnmanagedContainer<IDynamicVectorClass<IDACrateModifierClass ^> ^> ^CreateDACrateModifierClassPtrDynamicVectorClass();
			static IUnmanagedContainer<IDynamicVectorClass<IDACrateModifierClass ^> ^> ^CreateDACrateModifierClassPtrDynamicVectorClass(int size);

			bool Resize(int newSize) override sealed;
			void Clear() override;
			int ID(IDACrateModifierClass ^object) override sealed;
			void Insert(int index, IDACrateModifierClass ^object) override;
			bool Add(IDACrateModifierClass ^object) override;
			void ResetActive() override sealed;
			bool AddHead(IDACrateModifierClass ^object) override sealed;
			bool DeleteObj(IDACrateModifierClass ^object) override sealed;
			bool Delete(int index) override sealed;
			void DeleteAll() override sealed;
			int UninitializedAdd() override sealed;
			void AddMultiple(int numberToAdd) override sealed;

			property IntPtr DACrateModifierClassPtrDynamicVectorClassPointer
			{
				IntPtr get();
			}

			property IDACrateModifierClass ^default[int]
			{
				IDACrateModifierClass ^get(int index) override;
				void set(int index, IDACrateModifierClass ^value) override;
			}

			property int Length
			{
				int get() override sealed;
			}

			property int Count
			{
				int get() override;
				void set(int value) override sealed;
			}

			property int GrowthStep
			{
				int get() override sealed;
				void set(int value) override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DynamicVectorClass<::DACrateModifierClass *> *InternalDACrateModifierClassPtrDynamicVectorClassPointer
			{
				virtual ::DynamicVectorClass<::DACrateModifierClass *> *get();
			}

			property IntPtr Vector
			{
				IntPtr get() override sealed;
				void set(IntPtr value) override sealed;
			}

			property int VectorMax
			{
				int get() override sealed;
				void set(int value) override sealed;
			}

			property bool IsValid
			{
				bool get() override sealed;
				void set(bool value) override sealed;
			}

			property bool IsAllocated
			{
				bool get() override sealed;
				void set(bool value) override sealed;
			}

			property int ActiveCount
			{
				int get() override sealed;
				void set(int value) override sealed;
			}
	};
}