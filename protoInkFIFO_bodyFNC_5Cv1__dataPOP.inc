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
    {$if defined (_M_protoInkFIFO_5Cv1__var_STACK)}
        {$define _var_piFifo5Cv1_STACK:=_M_protoInkFIFO_5Cv1__var_STACK}
    {$else}
        {$FATAL 'macro ".._STACK" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_5Cv1__out_DATA)}
        {$define _out_piFifo5Cv1_DATA:=_M_protoInkFIFO_5Cv1__out_DATA}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_5Cv1__lcl_getNext)}
        {$define _fnc_piFifo5Cv1_getNext:=_M_protoInkFIFO_5Cv1__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifo5Cv1_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_5Cv1__lcl_setNext)}
        {$define _fnc_piFifo5Cv1_setNext:=_M_protoInkFIFO_5Cv1__lcl_setNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__SetNext)}
        {$define _fnc_piFifo5Cv1_setNext:=_M_protoInkFIFO_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_5Cv1__lcl_getDATA)}
        {$define _fnc_piFifo5Cv1_getDATA:=_M_protoInkFIFO_5Cv1__lcl_getDATA}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetDATA)}
        {$define _fnc_piFifo5Cv1_getDATA:=_M_protoInkFIFO_blockFNK__GetDATA}
    {$else}
        {$FATAL 'macro ".._getDATA" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_5Cv1__lcl_nodeDST)}
        {$define _fnc_piFifo5Cv1_nodeDST:=_M_protoInkFIFO_5Cv1__lcl_nodeDST}
    {$else}
        {$FATAL 'macro ".._nodeDST" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
{%region /fold 'setUP local vars'                                        }
{$if defined (_m_protoInkFIFO_5Cv1__tmp_POINTER)}
    {$define _tmp_piFifo5Cv1_POINTER:=_m_protoInkFIFO_5Cv1__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piFifo5Cv1_POINTER:=tmp}
{$endif}
{%endregion 'setUP local vars' /fold}
begin
    _tmp_piFifo5Cv1_POINTER:=_var_piFifo5Cv1_STACK;
     if _tmp_piFifo5Cv1_POINTER<>nil then begin
         if _fnc_piFifo5Cv1_getNext(_tmp_piFifo5Cv1_POINTER)<>_tmp_piFifo5Cv1_POINTER then begin
             {$ifDef inkFIFO_fncHeadMessage}{$message 'inline -> protoInkLLc_bodyFNC_C2__cutNodeSecond'}{$endIF}
             {$deFine _M_protoInkLLc_C2__cst_FIRST  :=_var_piFifo5Cv1_STACK}
             {$deFine _M_protoInkLLc_C2__out_NODE   :=_tmp_piFifo5Cv1_POINTER}
             {$deFine _M_protoInkLLc_C2__lcl_getNext:=_fnc_piFifo5Cv1_getNext}
             {$deFine _M_protoInkLLc_C2__lcl_setNext:=_fnc_piFifo5Cv1_setNext}
             {$I protoInkLLc_bodyFNC_C2__cutNodeSecond.inc}
         end
         else begin
            _var_piFifo5Cv1_STACK:=NIL;
         end;
         //---
        _out_piFifo5Cv1_DATA:=_fnc_piFifo5Cv1_getDATA(_tmp_piFifo5Cv1_POINTER);
        _fnc_piFifo5Cv1_nodeDST(_tmp_piFifo5Cv1_POINTER);
     end
     else _out_piFifo5Cv1_DATA:=nil;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Local macros
    {$unDef _tmp_piFifo5Cv1_POINTER}
    //--- undef Local macros
    {$unDef _var_piFifo5Cv1_STACK}
    {$unDef _out_piFifo5Cv1_DATA}
    {$unDef _fnc_piFifo5Cv1_getNext}
    {$unDef _fnc_piFifo5Cv1_setNext}
    {$unDef _fnc_piFifo5Cv1_getDATA}
    {$unDef _fnc_piFifo5Cv1_nodeDST}
    //--- undef user
    {$unDef _m_protoInkFIFO_5Cv1__tmp_POINTER}
    {$unDef _M_protoInkFIFO_5Cv1__var_STACK}
    {$unDef _M_protoInkFIFO_5Cv1__out_DATA}
    {$unDef _M_protoInkFIFO_5Cv1__lcl_getNext}
    {$unDef _M_protoInkFIFO_5Cv1__lcl_setNext}
    {$unDef _M_protoInkFIFO_5Cv1__lcl_getDATA}
    {$unDef _M_protoInkFIFO_5Cv1__lcl_nodeDST}
{%endregion 'unDEF used macros' /fold}
