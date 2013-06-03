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
    {$if defined (_M_protoInkFIFO_CDv1__var_STACK)}
        {$define _var_piFifoCDv1_STACK:=_M_protoInkFIFO_CDv1__var_STACK}
    {$else}
        {$FATAL 'macro ".._STACK" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_CDv1__cst_DATA)}
        {$define _cst_piFifoCDv1_DATA:=_M_protoInkFIFO_CDv1__cst_DATA}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_CDv1__lcl_getNext)}
        {$define _fnc_piFifoCDv1_getNext:=_M_protoInkFIFO_CDv1__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifoCDv1_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_CDv1__lcl_setNext)}
        {$define _prc_piFifoCDv1_setNext:=_M_protoInkFIFO_CDv1__lcl_setNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__SetNext)}
        {$define _prc_piFifoCDv1_setNext:=_M_protoInkFIFO_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_CDv1__lcl_getDATA)}
        {$define _fnc_piFifoCDv1_getDATA:=_M_protoInkFIFO_CDv1__lcl_getDATA}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetDATA)}
        {$define _fnc_piFifoCDv1_getDATA:=_M_protoInkFIFO_blockFNK__GetDATA}
    {$else}
        {$FATAL 'macro ".._getDATA" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_CDv1__lcl_nodeDST)}
        {$define _fnc_piFifoCDv1_nodeDST:=_M_protoInkFIFO_CDv1__lcl_nodeDST}
    {$else}
        {$FATAL 'macro ".._nodeDST" : NOT define!'}
    {$endif}
{%endregion}
{%region /fold 'setUP local vars'                                        }
{$if defined (_m_protoInkFIFO_CDv1__tmp_POINTER_01)}
    {$define _tmp_piFifoCDv1_POINTER_01:=_m_protoInkFIFO_CDv1__tmp_POINTER_01}
{$else}
var tmp:pointer;
    {$define _tmp_piFifoCDv1_POINTER_01:=tmp}
{$endif}
//---
{$if defined (_m_protoInkFIFO_CDv1__tmp_POINTER_02)}
    {$define _tmp_piFifoCDv1_POINTER_02:=_m_protoInkFIFO_CDv1__tmp_POINTER_02}
{$else}
var tmq:pointer;
    {$define _tmp_piFifoCDv1_POINTER_02:=tmq}
{$endif}
{%endregion}
begin
    {$ifDef inkFIFO_fncHeadMessage}{$message 'inline -> protoInkFIFO_bodyFNC_CDv0__cutNodeDATA'}{$endIF}
    {$deFine _M_protoInkFIFO_CDv0__tmp_POINTER:=_tmp_piFifoCDv1_POINTER_01}
    {$deFine _M_protoInkFIFO_CDv0__var_STACK  :=_var_piFifoCDv1_STACK}
    {$deFine _M_protoInkFIFO_CDv0__cst_DATA   :=_cst_piFifoCDv1_DATA}
    {$deFine _M_protoInkFIFO_CDv0__out_RES    :=_tmp_piFifoCDv1_POINTER_02}
    {$deFine _M_protoInkFIFO_CDv0__lcl_getNext:=_fnc_piFifoCDv1_getNext}
    {$deFine _M_protoInkFIFO_CDv0__lcl_setNext:=_prc_piFifoCDv1_setNext}
    {$deFine _M_protoInkFIFO_CDv0__lcl_getDATA:=_fnc_piFifoCDv1_getDATA}
    {$I protoInkFIFO_bodyFNC_CDv0__cutNodeDATA.inc}
    {$ifDef inkFIFO_fncHeadMessage}{$message '<<main code>>'}{$endIF}
    if _tmp_piFifoCDv1_POINTER_02<>nil then begin
       _fnc_piFifoCDv1_nodeDST(_tmp_piFifoCDv1_POINTER_02);
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Supre Local macros
    {$unDef _tmp_piFifoCDv1_POINTER_01}
    {$unDef _tmp_piFifoCDv1_POINTER_02}
    //--- undef Local macros
    {$unDef _var_piFifoCDv1_STACK}
    {$unDef _cst_piFifoCDv1_DATA}
    {$unDef _fnc_piFifoCDv1_getNext}
    {$unDef _prc_piFifoCDv1_setNext}
    {$unDef _fnc_piFifoCDv1_getDATA}
    {$unDef _fnc_piFifoCDv1_nodeDST}
    //--- undef user
    {$unDef _m_protoInkFIFO_CDv1__tmp_POINTER_01}
    {$unDef _m_protoInkFIFO_CDv1__tmp_POINTER_02}
    {$unDef _M_protoInkFIFO_CDv1__var_STACK}
    {$unDef _M_protoInkFIFO_CDv1__cst_DATA}
    {$unDef _M_protoInkFIFO_CDv1__lcl_getNext}
    {$unDef _M_protoInkFIFO_CDv1__lcl_setNext}
    {$unDef _M_protoInkFIFO_CDv1__lcl_getDATA}
    {$unDef _M_protoInkFIFO_CDv1__lcl_nodeDST}
{%endregion}
