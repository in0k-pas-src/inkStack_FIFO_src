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
    {$if defined (_M_protoInkFIFO_FE__var_STACK)}
        {$define _var_piFifoFE_STACK:=_M_protoInkFIFO_FE__var_STACK}
    {$else}
        {$FATAL 'macro ".._STACK" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_FE__lcl_getNext)}
        {$define _fnc_piFifoFE_getNext:=_M_protoInkFIFO_FE__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifoFE_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_FE__lcl_setNext)}
        {$define _fnc_piFifoFE_setNext:=_M_protoInkFIFO_FE__lcl_setNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__SetNext)}
        {$define _fnc_piFifoFE_setNext:=_M_protoInkFIFO_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro "..setNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_FE__lcl_getDATA)}
        {$define _fnc_piFifoFE_getDATA:=_M_protoInkFIFO_FE__lcl_getDATA}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetDATA)}
        {$define _fnc_piFifoFE_getDATA:=_M_protoInkFIFO_blockFNK__GetDATA}
    {$else}
        {$FATAL 'macro "..getDATA" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_FE__lcl_dataDST)}
        {$define _fnc_piFifoFE_dataDST:=_M_protoInkFIFO_FE__lcl_dataDST}
    {$else}
        {$FATAL 'macro ".._dataDST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_FE__lcl_nodeDST)}
        {$define _fnc_piFifoFE_nodeDST:=_M_protoInkFIFO_FE__lcl_nodeDST}
    {$else}
        {$FATAL 'macro ".._nodeDST" : NOT define!'}
    {$endif}
{%endregion}
{%region /fold 'setUP local VARs'                                        }
{$if defined (_m_protoInkFIFO_FE__tmp_POINTER)}
    {$define _tmp_piFifoFE_POINTER:=_m_protoInkFIFO_FE__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piFifoFE_POINTER:=tmp}
{$endif}
{%endregion}
begin
    if _var_piFifoFE_STACK<>nil then begin
        //--- рвем кольцо, _var_piFifoFE_STACK станет ВТОРЫМ элементом
       _tmp_piFifoFE_POINTER:=_fnc_piFifoFE_getNext(_var_piFifoFE_STACK);
       _fnc_piFifoFE_setNext(_var_piFifoFE_STACK,NIL);
       _var_piFifoFE_STACK  :=_tmp_piFifoFE_POINTER;
        //--- теперь как обычный список
        while _var_piFifoFE_STACK<>nil do begin
            // шаг на СЛЕДУЮЩИЙ
           _tmp_piFifoFE_POINTER:=_var_piFifoFE_STACK;
           _var_piFifoFE_STACK  :=_fnc_piFifoFE_getNext(_tmp_piFifoFE_POINTER);
            // уничтожение элемента tmp
           _fnc_piFifoFE_dataDST(_fnc_piFifoFE_getDATA(_tmp_piFifoFE_POINTER));
           _fnc_piFifoFE_nodeDST(_tmp_piFifoFE_POINTER);
        end;
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef SUPER local macros
    {$unDef _tmp_piFifoFE_POINTER}
    //--- undef Local macros
    {$unDef _var_piFifoFE_STACK}
    {$unDef _fnc_piFifoFE_getNext}
    {$unDef _fnc_piFifoFE_setNext}
    {$unDef _fnc_piFifoFE_getDATA}
    {$unDef _fnc_piFifoFE_dataDST}
    {$unDef _fnc_piFifoFE_nodeDST}
    //--- undef user macros
    {$undef _m_protoInkFIFO_FE__tmp_POINTER}
    {$undef _M_protoInkFIFO_FE__var_STACK}
    {$unDef _M_protoInkFIFO_FE__lcl_getNext}
    {$unDef _M_protoInkFIFO_FE__lcl_setNext}
    {$unDef _M_protoInkFIFO_FE__lcl_getDATA}
    {$unDef _M_protoInkFIFO_FE__lcl_dataDST}
    {$unDef _M_protoInkFIFO_FE__lcl_nodeDST}
{%endregion}

