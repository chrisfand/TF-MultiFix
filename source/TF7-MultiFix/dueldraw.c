//
// Yu-Gi-Oh! Tag Force - Duel Renderer Patches
// by xan1242 / Tenjoin
//

#include "multifix.h"
#include "dueldraw.h"
#include "helpers.h"
#include "multifixconfig.h"

uintptr_t _base_addr_dueldraw = 0;
uintptr_t _base_size_dueldraw = 0;

int (*dueldraw_sub_262C0)() = (int (*)())(0);

int dueldraw_sub_262C0_Hook()
{
    MultiFixConfig* config = mfconfig_GetConfig();
    if (config->basic.bDisableDuelHelpIcon)
        return 0;
    return dueldraw_sub_262C0();
}

void dueldraw_SetPlayerLP(uint16_t val)
{
    *(uint16_t*)(PLAYER_LP_VAL_ADDR + _base_addr_dueldraw) = val;
}

void dueldraw_SetOpponentLP(uint16_t val)
{
    *(uint16_t*)(OPPONENT_LP_VAL_ADDR + _base_addr_dueldraw) = val;
}

void dueldraw_Patch(uintptr_t base_addr, uintptr_t base_size)
{
    _base_addr_dueldraw = base_addr;
    _base_size_dueldraw = base_size;
    uintptr_t oldaddr = minj_GetBaseAddress();
    uintptr_t oldsize = minj_GetBaseSize();

    minj_SetBaseAddress(base_addr, base_size);

    dueldraw_sub_262C0 = (int (*)())(0x27e5c + base_addr);

    // lang fixes (L trigger menu)
    minj_MakeCALL(0x7AD98, (uintptr_t)&YgSys_GetLang_Hook);
    minj_MakeCALL(0x7ADE4, (uintptr_t)&YgSys_GetLang_Hook);
    minj_MakeCALL(0x1CE2C, (uintptr_t)&YgSys_GetLang_Hook);

    // lang fix the help topics
    minj_MakeCALL(0x2230, (uintptr_t)&YgSys_GetLang_Hook);

    // fix help topic text positions
    minj_WriteMemory16(0x1808, (uint16_t)(9 << 6));

    // button text
    minj_WriteMemory16(0x2464, (uint16_t)(0xF8 << 6));
    minj_WriteMemory16(0x2488, (uint16_t)(0xF8 << 6));
    minj_WriteMemory16(0x24C0, (uint16_t)(0xF8 << 6));
    minj_WriteMemory16(0x24E8, (uint16_t)(0xF8 << 6));

    // current topic title
    minj_WriteMemory16(0x29BC, (uint16_t)(9 << 6));

    // fix starchip infront of the category menu
    minj_WriteMemory32(0x2BDC, 0x02403021); // move a2, s2

    // nuke the "help" icon at the bottom right corner
    minj_MakeCALL(0x1CE1C, (uintptr_t)&dueldraw_sub_262C0_Hook);


    minj_SetBaseAddress(oldaddr, oldsize);
}