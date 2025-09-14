//
// Yu-Gi-Oh! Tag Force - Duel Manager Patches
// by xan1242 / Tenjoin
//

#include "multifix.h"
#include "multifixconfig.h"
#include "duelmgr.h"


#include "helpers.h"
#ifdef YG_PRINTLINE_DEBUG
#include "../../includes/psp/pspmallochelper.h"
#include <wchar.h>
#endif

uintptr_t _base_addr_duelmgr = 0;
uintptr_t _base_size_duelmgr = 0;

#ifdef YG_PRINTLINE_DEBUG
uintptr_t duelmgr_YgFont_PrintLine64_Hook(int X, int Y, uintptr_t unk_a2, wchar_t* string)
{
    helpers_SetYgFontHookBase(_base_addr_duelmgr);
    return YgFont_PrintLine64(X, Y, unk_a2, string);
}

uintptr_t duelmgr_YgFont_PrintLineFit64_Hook(int X, int Y, uintptr_t unk_a2, wchar_t* string, int32_t unk_t0)
{
    helpers_SetYgFontHookBase(_base_addr_duelmgr);
    return YgFont_PrintLineFit64(X, Y, unk_a2, string, unk_t0);
}
#endif

int (*lDuelMgr_Result_CallBack)(uintptr_t ptrFile, uintptr_t filesize) = (int(*)(uintptr_t, uintptr_t))0;
int lDuelMgr_Result_CallBack_Hook(uintptr_t ptrFolder, size_t filesize)
{
    if (!lDuelMgr_Result_CallBack)
        return 0;

    int result = lDuelMgr_Result_CallBack(ptrFolder, filesize);
    if (!result)
        return result;

    PatchButtonStrings(ptrFolder, "strTbl.bin");

    return result;
}

wchar_t* duelmgr_YgSys_wcscat_Hook(wchar_t* dest, const wchar_t* src)
{
    // copy the name back to remove the space
    if (dest[0] == L' ')
        YgSys_wcscpy(dest, &dest[1]);

    if (tf_wcschr(dest, L' '))
        return YgSys_wcscat(dest, src);
    return YgSys_wcscat(dest, L" &");
}

void duelmgr_Patch(uintptr_t base_addr, uintptr_t base_size)
{
    _base_addr_duelmgr = base_addr;
    _base_size_duelmgr = base_size;
    uintptr_t oldaddr = minj_GetBaseAddress();
    uintptr_t oldsize = minj_GetBaseSize();

    minj_SetBaseAddress(base_addr, base_size);

    minj_MakeJMPwNOP(0x2ED54, (uintptr_t)&YgSys_GetLang_Hook);

    // lang file specific exclusions
    minj_MakeCALL(0x1180, (uintptr_t)&YgSys_GetLang_Hook2);
    minj_MakeCALL(0x6CC0, (uintptr_t)&YgSys_GetLang_Hook2);
    minj_MakeCALL(0xBA58, (uintptr_t)&YgSys_GetLang_Hook2);
    minj_MakeCALL(0x175E8, (uintptr_t)&YgSys_GetLang_Hook2);

    // fix Y-pos of "DP" column header in Duel Bonus Post-Duel screen
    minj_WriteMemory16(0xC4D4, 0xAE0);
    minj_WriteMemory16(0xC020, 0xAE0);
//
    // fix Y-pos of "Duel Bonus Total" label in Duel Bonus Post-Duel screen
    minj_WriteMemory16(0xC6AC, 0x38F0);

    // fix Y-pos of "Choose a card." in Rock-Paper-Scissors Pre-Duel screen
    minj_WriteMemory16(0x9184, 0x3EE0);


    if (mfconfig_GetSwapConfirmButtons())
    {
        // change the confirm button text (cross and square)
        uintptr_t callback = minj_WriteLUI_ADDIU(0xBA9C, (uintptr_t)&lDuelMgr_Result_CallBack_Hook, MIPSR_t0);
        lDuelMgr_Result_CallBack = (int(*)(uintptr_t, uintptr_t))(callback);

#ifdef TFMULTIFIX_DEBUG_PRINT
        sceKernelPrintf("lDuelMgr_Result_CallBack: 0x%X", callback);
#endif
    }

    // fix free duel team name formatting
    minj_MakeCALL(0x400C, (uintptr_t)&duelmgr_YgSys_wcscat_Hook);


#ifdef YG_PRINTLINE_DEBUG
    minj_MakeJMPwNOP(0x2BCA8, (uintptr_t)&duelmgr_YgFont_PrintLine64_Hook); //tf6
    minj_MakeJMPwNOP(0x2BCB8, (uintptr_t)&duelmgr_YgFont_PrintLineFit64_Hook); //tf6
#endif

    minj_SetBaseAddress(oldaddr, oldsize);
}
