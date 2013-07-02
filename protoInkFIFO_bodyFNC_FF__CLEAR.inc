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
    {$if defined (_M_protoInkFIFO_FF__var_STACK)}
        {$define _var_piFifoFF_STACK:=_M_protoInkFIFO_FF__var_STACK}
    {$else}
        {$FATAL 'macro ".._STACK" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_FF__lcl_getNext)}
        {$define _fnc_piFifoFF_getNext:=_M_protoInkFIFO_FF__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifoFF_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_FF__lcl_setNext)}
        {$define _prc_piFifoFF_setNext:=_M_protoInkFIFO_FF__lcl_setNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__SetNext)}
        {$define _prc_piFifoFF_setNext:=_M_protoInkFIFO_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_FF__lcl_nodeDST)}
        {$define _fnc_piFifoFF_nodeDST:=_M_protoInkFIFO_FF__lcl_nodeDST}
    {$else}
        {$FATAL 'macro ".._nodeDST" : NOT define!'}
    {$endif}
{%endregion}
{%region /fold 'setUP local VARs'                                        }
{$if defined (_m_protoInkFIFO_FF__tmp_POINTER)}
    {$define _tmp_piFifoFF_POINTER:=_m_protoInkFIFO_FF__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piFifoFF_POINTER:=tmp}
{$endif}
{%endregion}
begin
    {$ifDef inkFIFO_fncHeadMessage}{$message 'inline -> protoInkLLc_bodyFNC_FFv2__CLEAR'}{$endIF}
    {$deFine _m_protoInkLLc_FFv2__tmp_POINTER:=_tmp_piFifoFF_POINTER}
    {$deFine _M_protoInkLLc_FFv2__var_FIRST  :=_var_piFifoFF_STACK}
    {$deFine _M_protoInkLLc_FFv2__lcl_getNext:=_fnc_piFifoFF_getNext}
    {$deFine _M_protoInkLLc_FFv2__lcl_setNext:=_prc_piFifoFF_setNext}
    {$deFine _M_protoInkLLc_FFv2__lcl_nodeDST:=_fnc_piFifoFF_nodeDST}
    {$I protoInkLLc_bodyFNC_FFv2__CLEAR.inc}
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef SUPER local macros
    {$unDef _tmp_piFifoFF_POINTER}
    //--- undef Local macros
    {$unDef _var_piFifoFF_STACK}
    {$unDef _fnc_piFifoFF_getNext}
    {$unDef _prc_piFifoFF_setNext}
    {$unDef _fnc_piFifoFF_nodeDST}
    //--- undef user macros
    {$undef _m_protoInkFIFO_FF__tmp_POINTER}
    {$undef _M_protoInkFIFO_FF__var_STACK}
    {$unDef _M_protoInkFIFO_FF__lcl_getNext}
    {$unDef _M_protoInkFIFO_FF__lcl_setNext}
    {$unDef _M_protoInkFIFO_FF__lcl_nodeDST}
{%endregion}

