/* Insect Invasion AI Patch
 * Copyright (c) 2014 Ulrik de Muelenaere (github.com/ulrikdem)
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the
 * use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not claim
 * that you wrote the original software. If you use this software in a product,
 * an acknowledgment in the product documentation would be appreciated but is
 * not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#include "setup.h"

#include <Compiler/AnsiCpp.h>
#include <Compiler/stl.h>
#include <Debug/db.h>
#include <ModInterface/DllInterface.h>

#include <windows.h>

class Mod : public DLLInterface {
private:
	HMODULE dll;
	DLLInterface* original;

public:
	virtual const wchar_t* GetName() {
		return L"Insect Invasion";
	}

	virtual bool Initialize(const char* version) {
		dll = LoadLibrary("InsectModOriginal.dll");
		original = reinterpret_cast<modGetDLLInterface>(GetProcAddress(dll, "GetDllInterface"))();
		return original->Initialize(version);
	}

	virtual void Shutdown() {
		original->Shutdown();
		FreeLibrary(dll);
	}

	virtual DLLSetupInterface* SetupCreate() {
		return new Setup(original);
	}

	virtual void SetupDestroy(DLLSetupInterface* setup)  {
		delete setup;
	}

	virtual bool IsScenarioCompatible(const char* mod) const {return original->IsScenarioCompatible(mod);}

	virtual DLLGameInterface* GameCreate(SimEngineInterface* engine) {return original->GameCreate(engine);}
	virtual void GameDestroy(DLLGameInterface* game) {original->GameDestroy(game);}
	virtual DLLScoreInterface* ScoreCreate() {return original->ScoreCreate();}
	virtual void ScoreDestroy(DLLScoreInterface* score) {original->ScoreDestroy(score);}

	virtual ZsProgress ZsPublish() {return original->ZsPublish();}
	virtual ZsProgress ZsUpdate() {return original->ZsUpdate();}
	virtual ZsProgress ZsAbort() {return original->ZsAbort();}
};
