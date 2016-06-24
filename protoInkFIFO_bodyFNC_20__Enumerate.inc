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
    {$if defined (_M_protoInkFIFO_20__cst_STACK)}
        {$define _cst_piFifo20_STACK:=_M_protoInkFIFO_20__cst_STACK}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_20__cst_context)}
        {$define _cst_piFifo20_context:=_M_protoInkFIFO_20__cst_context}
    {$else}
        {$FATAL 'macro ".._context" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_20__cst_enumFNC)}
        {$define _cst_piFifo20_enumFNC:=_M_protoInkFIFO_20__cst_enumFNC}
    {$else}
        {$FATAL 'macro ".._enumFNC" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_20__out_LAST)}
        {$define _out_piFifo20_LAST:=_M_protoInkFIFO_20__out_LAST}
    {$else}
        {$FATAL 'macro ".._LAST" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_20__lcl_getNext)}
        {$define _fnc_piFifo20_getNext:=_M_protoInkFIFO_20__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifo20_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
begin
    if _cst_piFifo20_STACK<>nil then begin
        {$ifDef inkFIFO_fncHeadMessage}{$message 'inline -> protoInkLLc_bodyFNC_20__Enumerate'}{$endIF}
        {$deFine _M_protoInkLLc_20__cst_FIRST  :=_fnc_piFifo20_getNext(_cst_piFifo20_STACK)}
        {$deFine _M_protoInkLLc_20__cst_context:=_cst_piFifo20_context}
            {$if defined(_M_protoInkFIFO_20__lcl_preENUM)}
        {$deFine _M_protoInkLLc_20__lcl_preENUM:=_M_protoInkFIFO_20__lcl_preENUM}
            {$endif}
        {$deFine _M_protoInkLLc_20__cst_enumFNC:=_cst_piFifo20_enumFNC}
        {$deFine _M_protoInkLLc_20__out_LAST   :=_out_piFifo20_LAST}
        {$deFine _M_protoInkLLc_20__lcl_getNext:=_fnc_piFifo20_getNext}
        {$I protoInkLLc_bodyFNC_20__Enumerate.inc}
    end
    else begin
       _out_piFifo20_LAST:=NIL;
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Local macros
    {$unDef _cst_piFifo20_STACK}
    {$unDef _cst_piFifo20_context}
    {$unDef _cst_piFifo20_enumFNC}
    {$unDef _out_piFifo20_LAST}
    {$unDef _fnc_piFifo20_getNext}
    //--- undef user
    {$unDef _M_protoInkFIFO_20__cst_STACK}
    {$unDef _M_protoInkFIFO_20__cst_context}
    {$unDef _M_protoInkFIFO_20__lcl_preENUM}
    {$unDef _M_protoInkFIFO_20__cst_enumFNC}
    {$unDef _M_protoInkFIFO_20__out_LAST}
    {$unDef _M_protoInkFIFO_20__lcl_getNext}
{%endregion 'unDEF used macros' /fold}
