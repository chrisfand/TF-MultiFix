//
// Yu-Gi-Oh! Tag Force - ygBasicWindow & YgSelWnd interface
// by xan1242 / Tenjoin
//

#include "YgWindow.h"

uintptr_t(*_YgSelWnd_Init)(YgSelWnd* window) = (uintptr_t(*)(YgSelWnd*))(0);
int(*_YgSelWnd_Cont)(YgSelWnd* window) = (int(*)(YgSelWnd*))(0);
uintptr_t(*_YgSelWnd_Term)(YgSelWnd* window) = (uintptr_t(*)(YgSelWnd*))(0);
uintptr_t(*_YgSelWnd_Draw)(uintptr_t ehpacket, YgSelWnd* window) = (uintptr_t(*)(uintptr_t, YgSelWnd*))(0);

#ifndef YGWINDOW_ESSENTIALS_ONLY
uintptr_t(*_YgSelWnd_DecideButton)(YgSelWnd* window, unsigned char unk) = (uintptr_t(*)(YgSelWnd*, unsigned char))(0);
uintptr_t(*_YgSelWnd_DecideSelect)(YgSelWnd* window, int unk) = (uintptr_t(*)(YgSelWnd*, int))(0);
uintptr_t(*_YgSelWnd_ReqestCloseAnim)(YgSelWnd* window) = (uintptr_t(*)(YgSelWnd*))(0);
uintptr_t(*_YgSelWnd_DrawButton)(uintptr_t ehpacket, YgSelWnd* window, int X, int Y) = (uintptr_t(*)(uintptr_t, YgSelWnd*, int, int))(0);
uintptr_t(*_YgSelWnd_DrawSelectCsr)(uintptr_t ehpacket, YgSelWnd* window, int X, int Y) = (uintptr_t(*)(uintptr_t, YgSelWnd*, int, int))(0);
uintptr_t(*_YgSelWnd_DrawSelectItemBG)(uintptr_t ehpacket, YgSelWnd* window, int X, int Y) = (uintptr_t(*)(uintptr_t, YgSelWnd*, int, int))(0);
uintptr_t(*_YgSelWnd_SelCsrDec)(YgSelWnd* window) = (uintptr_t(*)(YgSelWnd*))(0);
uintptr_t(*_YgSelWnd_SelCsrInc)(YgSelWnd* window) = (uintptr_t(*)(YgSelWnd*))(0);
#endif

uintptr_t(*_ygBasicWindow_Init)(ygWindowResource* res, uintptr_t heap) = (uintptr_t(*)(ygWindowResource*, uintptr_t))(0);
uintptr_t(*_ygBasicWindow_Create)(ygWindowResource* res, ygBasicWindow* window) = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*))(0);
uintptr_t(*_ygBasicWindow_Term)(ygWindowResource* res) = (uintptr_t(*)(ygWindowResource*))(0);
uintptr_t(*_ygBasicWindow_Draw)(uintptr_t ehpacket, ygWindowResource* window) = (uintptr_t(*)(uintptr_t, ygWindowResource*))(0);
uintptr_t(*_ygBasicWindow_ReqestOpenAnim)(ygWindowResource* res, ygBasicWindow* window) = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*))(0);

#ifndef YGWINDOW_ESSENTIALS_ONLY
uintptr_t(*_ygBasicWindow_DeleteWindow)(ygWindowResource* res, ygBasicWindow* window) = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*))(0);
uintptr_t(*_ygBasicWindow_ReqestCloseAnim)(ygWindowResource* res, ygBasicWindow* window) = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*))(0);
uintptr_t(*_ygBasicWindow_IsFinishAnim)(ygWindowResource* res, ygBasicWindow* window) = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*))(0);
int(*_ygBasicWindow_GetWndStringBottom)(ygWindowResource* res, ygBasicWindow* window) = (int(*)(ygWindowResource*, ygBasicWindow*))(0);
uintptr_t(*_ygBasicWindow_GetWndStringRect)(ygWindowResource* res, ygBasicWindow* window, int* outWidth, int* outHeight) = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*, int*, int*))(0);
int(*_ygBasicWindow_GetWndState)(ygWindowResource* res, ygBasicWindow* window) = (int(*)(ygWindowResource*, ygBasicWindow*))(0);
#endif

uintptr_t YgSelWnd_Init(YgSelWnd* window)
{
    return _YgSelWnd_Init(window);
}

int YgSelWnd_Cont(YgSelWnd* window)
{
    return _YgSelWnd_Cont(window);
}

uintptr_t YgSelWnd_Term(YgSelWnd* window)
{
    return _YgSelWnd_Term(window);
}

uintptr_t YgSelWnd_Draw(uintptr_t ehpacket, YgSelWnd* window)
{
    return _YgSelWnd_Draw(ehpacket, window);
}

#ifndef YGWINDOW_ESSENTIALS_ONLY
uintptr_t YgSelWnd_DecideButton(YgSelWnd* window, unsigned char unk)
{
    return _YgSelWnd_DecideButton(window, unk);
}

uintptr_t YgSelWnd_DecideSelect(YgSelWnd* window, int unk)
{
    return _YgSelWnd_DecideSelect(window, unk);
}

uintptr_t YgSelWnd_DrawButton(uintptr_t ehpacket, YgSelWnd* window, int X, int Y)
{
    return _YgSelWnd_DrawButton(ehpacket, window, X, Y);
}

uintptr_t YgSelWnd_DrawSelectCsr(uintptr_t ehpacket, YgSelWnd* window, int X, int Y)
{
    return _YgSelWnd_DrawSelectCsr(ehpacket, window, X, Y);
}

uintptr_t YgSelWnd_DrawSelectItemBG(uintptr_t ehpacket, YgSelWnd* window, int X, int Y)
{
    return _YgSelWnd_DrawSelectItemBG(ehpacket, window, X, Y);
}

uintptr_t YgSelWnd_ReqestCloseAnim(YgSelWnd* window)
{
    return _YgSelWnd_ReqestCloseAnim(window);
}

uintptr_t YgSelWnd_SelCsrDec(YgSelWnd* window)
{
    return _YgSelWnd_SelCsrDec(window);
}

uintptr_t YgSelWnd_SelCsrInc(YgSelWnd* window)
{
    return _YgSelWnd_SelCsrInc(window);
}
#endif

uintptr_t ygBasicWindow_Init(ygWindowResource* res, uintptr_t heap)
{
    return _ygBasicWindow_Init(res, heap);
}

uintptr_t ygBasicWindow_Create(ygWindowResource* res, ygBasicWindow* window)
{
    return _ygBasicWindow_Create(res, window);
}

uintptr_t ygBasicWindow_Term(ygWindowResource* res)
{
    return _ygBasicWindow_Term(res);
}

uintptr_t ygBasicWindow_Draw(uintptr_t ehpacket, ygWindowResource* window)
{
    return _ygBasicWindow_Draw(ehpacket, window);
}

uintptr_t ygBasicWindow_ReqestOpenAnim(ygWindowResource* res, ygBasicWindow* window)
{
    return _ygBasicWindow_ReqestOpenAnim(res, window);
}

#ifndef YGWINDOW_ESSENTIALS_ONLY
uintptr_t ygBasicWindow_DeleteWindow(ygWindowResource* res, ygBasicWindow* window)
{
    return _ygBasicWindow_DeleteWindow(res, window);
}

uintptr_t ygBasicWindow_ReqestCloseAnim(ygWindowResource* res, ygBasicWindow* window)
{
    return _ygBasicWindow_ReqestCloseAnim(res, window);
}

uintptr_t ygBasicWindow_IsFinishAnim(ygWindowResource* res, ygBasicWindow* window)
{
    return _ygBasicWindow_IsFinishAnim(res, window);
}

int ygBasicWindow_GetWndStringBottom(ygWindowResource* res, ygBasicWindow* window)
{
    return _ygBasicWindow_GetWndStringBottom(res, window);
}

uintptr_t ygBasicWindow_GetWndStringRect(ygWindowResource* res, ygBasicWindow* window, int* outWidth, int* outHeight)
{
    return _ygBasicWindow_GetWndStringRect(res, window, outWidth, outHeight);
}

int ygBasicWindow_GetWndState(ygWindowResource* res, ygBasicWindow* window)
{
    return _ygBasicWindow_GetWndState(res, window);
}
#endif

void YgWindow_Init(uintptr_t base_addr)
{
    _YgSelWnd_Init = (uintptr_t(*)(YgSelWnd*))(0x6840 + base_addr);
    _YgSelWnd_Cont = (int(*)(YgSelWnd*))(0x7608 + base_addr);
    _YgSelWnd_Term = (uintptr_t(*)(YgSelWnd*))(0x5D10 + base_addr);
    _YgSelWnd_Draw = (uintptr_t(*)(uintptr_t, YgSelWnd*))(0x6B58 + base_addr);
#ifndef YGWINDOW_ESSENTIALS_ONLY
    _YgSelWnd_ReqestCloseAnim = (uintptr_t(*)(YgSelWnd*))(0x5CD4 + base_addr);
    _YgSelWnd_DecideButton = (uintptr_t(*)(YgSelWnd*, unsigned char))(0x5C20 + base_addr);
    _YgSelWnd_DecideSelect = (uintptr_t(*)(YgSelWnd*, int))(0x5C54 + base_addr);
    _YgSelWnd_DrawButton = (uintptr_t(*)(uintptr_t, YgSelWnd*, int, int))(0x7E74 + base_addr);
    _YgSelWnd_DrawSelectCsr = (uintptr_t(*)(uintptr_t, YgSelWnd*, int, int))(0x5D44 + base_addr);
    _YgSelWnd_DrawSelectItemBG = (uintptr_t(*)(uintptr_t, YgSelWnd*, int, int))(0x5E74 + base_addr);
    _YgSelWnd_SelCsrDec = (uintptr_t(*)(YgSelWnd*))(0x61B0 + base_addr);
    _YgSelWnd_SelCsrInc = (uintptr_t(*)(YgSelWnd*))(0x641C + base_addr);
#endif

    _ygBasicWindow_Init = (uintptr_t(*)(ygWindowResource*, uintptr_t))(0x00048444 + base_addr);
    _ygBasicWindow_Create = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*))(0x000484D8 + base_addr);
    _ygBasicWindow_Term = (uintptr_t(*)(ygWindowResource*))(0x00048618 + base_addr);
    _ygBasicWindow_Draw = (uintptr_t(*)(uintptr_t, ygWindowResource*))(0x00048680 + base_addr);
    _ygBasicWindow_ReqestOpenAnim = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*))(0x48888 + base_addr);

#ifndef YGWINDOW_ESSENTIALS_ONLY
    _ygBasicWindow_DeleteWindow = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*))(0x48824 + base_addr);
    _ygBasicWindow_ReqestCloseAnim = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*))(0x488E4 + base_addr);
    _ygBasicWindow_IsFinishAnim = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*))(0x48944 + base_addr);
    _ygBasicWindow_GetWndStringBottom = (int(*)(ygWindowResource*, ygBasicWindow*))(0x489BC + base_addr);
    _ygBasicWindow_GetWndStringRect = (uintptr_t(*)(ygWindowResource*, ygBasicWindow*, int*, int*))(0x48B70 + base_addr);
    _ygBasicWindow_GetWndState = (int(*)(ygWindowResource*, ygBasicWindow*))(0x48C80 + base_addr);
#endif
}
