//
// Yu-Gi-Oh! Tag Force - Deck Edit Patches
// by xan1242 / Tenjoin
//

#include "multifix.h"
#include "multifixconfig.h"
#include "helpers.h"
#include "deck.h"

uintptr_t _base_addr_deck = 0;
uintptr_t _base_size_deck = 0;

void deck_Patch(uintptr_t base_addr, uintptr_t base_size)
{
    _base_addr_deck = base_addr;
    _base_size_deck = base_size;
    uintptr_t oldaddr = minj_GetBaseAddress();
    uintptr_t oldsize = minj_GetBaseSize();

    minj_SetBaseAddress(base_addr, base_size);

    minj_MakeJMPwNOP(0x37474, (uintptr_t)&YgSys_GetLang_Hook);

    // Set letter shortcut box (L+R card name sorting) color to opaque white for TF7
    minj_WriteMemory32(0x1CFB0, 0x2417FFFF); //li s7, -0x1

    // path dependant
    minj_MakeCALL(0x1f344, (uintptr_t)&YgSys_GetLang_Hook2);
    minj_MakeCALL(0x1f19c, (uintptr_t)&YgSys_GetLang_Hook2);
    minj_MakeCALL(0x5994, (uintptr_t)&YgSys_GetLang_Hook2);

    // fix help topic text positions
    minj_WriteMemory16(0x5570, (uint16_t)(9 << 6));

    // fix L+R button text
    minj_WriteMemory16(0x6554, (uint16_t)(0xF8 << 6));
    minj_WriteMemory16(0x6578, (uint16_t)(0xF8 << 6));
    minj_WriteMemory16(0x65b0, (uint16_t)(0xF8 << 6));
    minj_WriteMemory16(0x65d8, (uint16_t)(0xF8 << 6));

    // current topic title
    minj_WriteMemory16(0x6aac, (uint16_t)(9 << 6));

    // Fixes starchip vertical position in the "?Help" menu's category selection list
    minj_WriteMemory32(0x6ccc, 0x02403021); // move a2, s2

    minj_SetBaseAddress(oldaddr, oldsize);
}