{//.[ PROto Cyclic Linked Lists].....................[ in0k © 13.01.2013 ]...///
///                                                                          ///
///                                _____                                     ///
///                     +-+-+-+-+-|   __|_ _ first -> -                      ///
///                     |  PROto  |  |__| | |         -                      ///
///                     +-+-+-+-+-|_____|_|_|         -                      ///
///                          v 2.0           first <- =                      ///
///                                                                          ///
///............................................[ v 2.0 in0k © 05.06.2013 ]...//}
{%region /fold 'check "define" for all used macros'                      }
    //--- VARs
    {$if defined (_M_protoInkFIFO_E4__var_STACK)}
        {$define _var_piFifoE4_STACK:=_M_protoInkFIFO_E4__var_STACK}
    {$else}
        {$FATAL 'macro ".._STACK" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_E4__cst_cmpCTX)}
        {$define _cst_piFifoE4_cmpCXT:=_M_protoInkFIFO_E4__cst_cmpCTX}
    {$else}
        {$FATAL 'macro ".._cmpCTX" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_E4__lcl_cmpFNC)}
        {$define _fnc_piFifoE4_cmpFNC:=_M_protoInkFIFO_E4__lcl_cmpFNC}
    {$else}
        {$FATAL 'macro ".._cmpFNC" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_E4__lcl_getNext)}
        {$define _fnc_piFifoE4_getNext:=_M_protoInkFIFO_E4__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifoE4_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._GetNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_E4__lcl_setNext)}
        {$define _prc_piFifoE4_setNext:=_M_protoInkFIFO_E4__lcl_setNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__SetNext)}
        {$define _prc_piFifoE4_setNext:=_M_protoInkFIFO_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._SetNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_E4__lcl_dspPRC)}
        {$define _prc_piFifoE4_dspPRC:=_M_protoInkFIFO_E4__lcl_dspPRC}
    {$else}
        {$FATAL 'macro ".._dspPRC" : NOT define!'}
    {$endif}
    {$if defined(_M_protoInkFIFO_E4__lcl_getDATA) AND defined(_M_protoInkFIFO_E4__lcl_dspDATA)}
        procedure __protoInkLLc_E4__lcl_dspNODE__(const node:pointer); inline;
        begin
          _M_protoInkFIFO_E4__lcl_dspDATA(_M_protoInkFIFO_E4__lcl_getDATA(node));
          _M_protoInkFIFO_E4__lcl_dspPRC (node);
        end;
        {/$define _prc_piFifoE4_dspPRC:=_M_protoInkFIFO_E4__lcl_dspDATA(_M_protoInkFIFO_E4__lcl_getDATA(node));_M_protoInkFIFO_E4__lcl_dspPRC(node);}
    {$endif}
{%endregion}
{%region /fold 'setUP local VARs'                                        }
{$if defined (_m_protoInkFIFO_E4__tmp_POINTER0)}
    {$define _tmp_piFifoE4_POINTER0:=_m_protoInkFIFO_E4__tmp_POINTER0}
{$else}
var tmp:pointer;
    {$define _tmp_piFifoE4_POINTER0:=tmp}
{$endif}
{$if defined (_m_protoInkFIFO_E4__tmp_POINTER1)}
    {$define _tmp_piFifoE4_POINTER1:=_m_protoInkFIFO_E4__tmp_POINTER1}
{$else}
var tmq:pointer;
    {$define _tmp_piFifoE4_POINTER1:=tmq}
{$endif}
{%endregion}
begin


    {$ifDef inkFIFO_fncHeadMessage}{$message 'inline -> protoInkLLc_bodyFNC_E4__Erase'}{$endIF}
    {$define _m_protoInkLLc_E4__tmp_POINTER0:=_tmp_piFifoE4_POINTER0}
    {$define _m_protoInkLLc_E4__tmp_POINTER1:=_tmp_piFifoE4_POINTER1}
    {$define _M_protoInkLLc_E4__var_FIRST   :=_var_piFifoE4_STACK}
    {$define _M_protoInkLLc_E4__cst_cmpCTX  :=_cst_piFifoE4_cmpCXT}
    {$define _M_protoInkLLc_E4__lcl_cmpFNC  :=_fnc_piFifoE4_cmpFNC}
    {$define _M_protoInkLLc_E4__lcl_dspPRC  :=_prc_piFifoE4_dspPRC}
    {$define _M_protoInkLLc_E4__lcl_getNext :=_fnc_piFifoE4_getNext}
    {$define _M_protoInkLLc_E4__lcl_setNext :=_prc_piFifoE4_setNext}
    {$I protoInkLLc_bodyFNC_E4__Erase.inc}
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef SUPER local macros
    {$unDef _tmp_piFifoE4_POINTER0}
    {$unDef _tmp_piFifoE4_POINTER1}
    //--- undef Local macros
    {$unDef _var_piFifoE4_STACK}
    {$unDef _cst_piFifoE4_cmpCXT}
    {$unDef _fnc_piFifoE4_cmpFNC}
    {$unDef _prc_piFifoE4_dspPRC}
    {$unDef _fnc_piFifoE4_getNext}
    {$unDef _prc_piFifoE4_setNext}
    //--- undef user macros
    {$undef _m_protoInkFIFO_E4__tmp_POINTER0}
    {$undef _M_protoInkFIFO_E4__tmp_POINTER1}
    {$undef _M_protoInkFIFO_E4__var_STACK}
    {$unDef _M_protoInkFIFO_E4__cst_cmpCTX}
    {$unDef _M_protoInkFIFO_E4__lcl_cmpFNC}
    {$unDef _M_protoInkFIFO_E4__lcl_dspPRC}
    {$unDef _M_protoInkFIFO_E4__lcl_getNext}
    {$unDef _M_protoInkFIFO_E4__lcl_setNext}
    {$unDef _M_protoInkFIFO_E4__lcl_getDATA}
    {$unDef _M_protoInkFIFO_E4__lcl_dspDATA}

{%endregion}
