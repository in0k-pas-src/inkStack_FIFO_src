{//-----------------------------------------------[ mangust © 29.01.2010 ]---///
///                                 _____ _ ___                              ///
///            +-+-+-+-+-+_     _  |   __|_|  _|___last -> -                 ///
///            |  PRoTo  |_|___| |_|   __| |  _| . | first -                 ///
///            +-+-+-+-+-| |   | '_|__|  |_|_| |___|       -                 ///
///                      |_|_|_|_,_|    v 4.0      last <- =                 ///
///                                                                          ///
///--------------------------------------------[ v 4.0 in0k © 29.05.2013 ]---//}
{%region /fold 'check "define" for all used macros'                      }
    //--- VARs
    {$if defined (_M_protoInkFIFO_11__cst_STACK)}
        {$define _cst_piFifo11_STACK:=_M_protoInkFIFO_11__cst_STACK}
    {$else}
        {$FATAL 'macro ".._STACK" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_11__out_COUNT)}
        {$define _out_piFifo11_COUNT:=_M_protoInkFIFO_11__out_COUNT}
    {$else}
        {$FATAL 'macro ".._COUNT" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_11__lcl_getNext)}
        {$define _fnc_piFifo11_getNext:=_M_protoInkFIFO_11__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifo11_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
{%endregion}
{%region /fold 'setUP local VARs'                                        }
{$if defined (_m_protoInkFIFO_11__tmp_POINTER)}
    {$define _tmp_piFifo11_POINTER:=_m_protoInkFIFO_11__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piFifo11_POINTER:=tmp}
{$endif}
{%endregion}
begin
    {$ifDef inkFIFO_fncHeadMessage}{$message 'inline -> protoInkLLc_bodyFNC_11__Count'}{$endIF}
    {$deFine _M_protoInkLLc_11__tmp_POINTER:=_tmp_piFifo11_POINTER}
    {$deFine _M_protoInkLLc_11__cst_FIRST  :=_cst_piFifo11_STACK}
    {$deFine _M_protoInkLLc_11__out_COUNT  :=_out_piFifo11_COUNT}
    {$deFine _M_protoInkLLc_11__lcl_getNext:=_fnc_piFifo11_getNext}
    {$I protoInkLLc_bodyFNC_11__Count.inc}
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef SUPER local macros
    {$unDef _tmp_piFifo11_POINTER}
    //--- undef Local macros
    {$unDef _cst_piFifo11_STACK}
    {$unDef _out_piFifo11_COUNT}
    {$unDef _fnc_piFifo11_getNext}
    //--- undef user macros
    {$undef _m_protoInkFIFO_11__tmp_POINTER}
    {$undef _M_protoInkFIFO_11__cst_STACK}
    {$unDef _M_protoInkFIFO_11__out_COUNT}
    {$unDef _M_protoInkFIFO_11__lcl_getNext}
{%endregion}

