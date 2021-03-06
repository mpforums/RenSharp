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

#include <engine_tt.h>

class RenSharpConsoleFunctionClass : public ConsoleFunctionClass
{
	private:
		StringClass name;
		StringClass alias;
		StringClass help;
		bool aliasNull;

	public:
		RenSharpConsoleFunctionClass(const char *name, const char *alias, const char *help);
		virtual ~RenSharpConsoleFunctionClass();

		virtual const char *Get_Name();
		virtual const char *Get_Alias();
		virtual const char *Get_Help();
		virtual void Activate(const char *pArgs);

		void Set_Name(const char* name);
		void Set_Alias(const char* alias);
		void Set_Help(const char* help);
};