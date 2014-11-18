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

#include <Compiler/AnsiCpp.h>
#include <Compiler/stl.h>
#include <Debug/db.h>
#include <ModInterface/DllInterface.h>

class Setup : public DLLSetupInterface {
private:
	DLLInterface* owner;
	DLLSetupInterface* original;

public:
	Setup(DLLInterface* owner) : owner(owner), original(owner->SetupCreate()) {}

	virtual ~Setup() {
		owner->SetupDestroy(original);
	}

	virtual bool OptionChoiceAISupport(unsigned long option, size_t choice) const {
		return (option == 'TYPE' && choice == 0) || original->OptionChoiceAISupport(option, choice);
	}

	virtual void SetGameType(GameType type) {original->SetGameType(type);}
	virtual void SetNetworkGame(bool network) {original->SetNetworkGame(network);}
	virtual void SetRandomSeed(unsigned long seed) {original->SetRandomSeed(seed);}
	virtual void SetStatsScenario(const char* file, const wchar_t* name) {original->SetStatsScenario(file, name);}
	virtual void SetStatsGameID(const GUID& id) {original->SetStatsGameID(id);}
	virtual unsigned long GetGameModeOptionID() const {return original->GetGameModeOptionID();}

	virtual void PlayerSetCount(size_t count) {original->PlayerSetCount(count);}
	virtual size_t PlayerGetCount() const {return original->PlayerGetCount();}
	virtual void PlayerSetMax(size_t max) {original->PlayerSetMax(max);}
	virtual void PlayerSetToAI(size_t index) {original->PlayerSetToAI(index);}
	virtual void PlayerSetToHuman(size_t index) {original->PlayerSetToHuman(index);}
	virtual void PlayerSetName(size_t index, const wchar_t* name) {original->PlayerSetName(index, name);}
	virtual void PlayerSetPassport(size_t index, const wchar_t* passport) {original->PlayerSetPassport(index, passport);}
	virtual void PlayerSetRace(size_t index, size_t race) {original->PlayerSetRace(index, race);}
	virtual void PlayerSetTeam(size_t index, size_t team) {original->PlayerSetTeam(index, team);}

	virtual void OptionsInit(GameType type, bool network) {original->OptionsInit(type, network);}
	virtual size_t OptionsCount() const {return original->OptionsCount();}
	virtual unsigned long OptionID(size_t option) const {return original->OptionID(option);}
	virtual void OptionName(wchar_t* out, size_t length, unsigned long option) const {original->OptionName(out, length, option);}
	virtual void OptionTooltip(wchar_t* out, size_t length, unsigned long option) const {original->OptionTooltip(out, length, option);}
	virtual size_t OptionChoices(unsigned long option) const {return original->OptionChoices(option);}
	virtual size_t OptionChoiceDef(unsigned long option) const {return original->OptionChoiceDef(option);}
	virtual bool OptionChoiceValid(unsigned long option, size_t choice) const {return original->OptionChoiceValid(option, choice);}
	virtual void OptionChoiceName(wchar_t* out, size_t length, unsigned long option, size_t choice) const {original->OptionChoiceName(out, length, option, choice);}
	virtual void OptionSet(unsigned long option, size_t choice) {original->OptionSet(option, choice);}

	virtual size_t RaceGetCount() const {return original->RaceGetCount();}
	virtual const wchar_t* RaceGetName(size_t index) const {return original->RaceGetName(index);}
	virtual const wchar_t* RaceGetDesc(size_t index) const {return original->RaceGetDesc(index);}
	virtual const char*	RaceGetImageFilename(size_t index) const {return original->RaceGetImageFilename(index);}

	virtual bool TeamGetEnabled() const {return original->TeamGetEnabled();}
};
