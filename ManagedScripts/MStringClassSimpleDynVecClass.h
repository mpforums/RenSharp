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

namespace RenSharp
{
	public ref class StringClassSimpleDynVecClass : public SimpleDynVecClass<String ^>
	{
		private:
			StringClassSimpleDynVecClass();
			StringClassSimpleDynVecClass(int size);

		public:
			StringClassSimpleDynVecClass(IntPtr pointer);

			static IUnmanagedContainer<ISimpleDynVecClass<String ^> ^> ^CreateStringClassSimpleDynVecClass();
			static IUnmanagedContainer<ISimpleDynVecClass<String ^> ^> ^CreateStringClassSimpleDynVecClass(int size);

			bool Resize(int newSize) override sealed;
			bool UninitialisedGrow(int newSize) override sealed;
			void UninitializedResize(int newSize) override sealed;
			IntPtr Peek() override sealed;

#pragma push_macro("ZeroMemory")
#undef ZeroMemory
			void ZeroMemory() override sealed;
#pragma pop_macro("ZeroMemory")

			int FindIndex(String ^object) override sealed;
			bool Add(String ^data, int newSizeHint) override sealed;
			bool Add(String ^data) override;
			int AddMultiple(int numberToAdd) override sealed;
			bool AddHead(String ^object) override sealed;
			void Insert(int index, String ^item) override;
			bool DeleteIndex(int index, bool allowShrink) override sealed;
			bool DeleteIndex(int index) override sealed;
			bool DeleteObject(String ^object, bool allowShrink) override sealed;
			bool DeleteObject(String ^object) override sealed;
			bool DeleteRange(int start, int count, bool allowShrink) override sealed;
			bool DeleteRange(int start, int count) override sealed;
			void DeleteAll(bool allowShrink) override sealed;
			void DeleteAll() override sealed;

			property IntPtr StringClassSimpleDynVecClassPointer
			{
				IntPtr get();
			}

			property int Length
			{
				int get() override sealed;
			}

			property String ^default[int]
			{
				String ^get(int index) override;
				void set(int index, String ^value) override;
			}

			property bool IsEmpty
			{
				bool get() override;
			}

			property int Count
			{
				virtual int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;
			bool Grow(int newSizeHint) override sealed;
			bool Shrink() override sealed;

			property ::SimpleDynVecClass<::StringClass> *InternalStringClassSimpleDynVecClassPointer
			{
				virtual ::SimpleDynVecClass<::StringClass> *get();
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

			property int ActiveCount
			{
				int get() override sealed;
				void set(int value) override sealed;
			}
	};
}