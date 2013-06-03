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
    {$if defined (_M_protoInkFIFO_51v1__var_STACK)}
        {$define _var_piFifo51v1_STACK:=_M_protoInkFIFO_51v1__var_STACK}
    {$else}
        {$FATAL 'macro ".._STACK" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_51v1__cst_DATA)}
        {$define _cst_piFifo51v1_DATA:=_M_protoInkFIFO_51v1__cst_DATA}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_51v1__lcl_getNext)}
        {$define _fnc_piFifo51v1_getNext:=_M_protoInkFIFO_51v1__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifo51v1_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_51v1__lcl_setNext)}
        {$define _prc_piFifo51v1_setNext:=_M_protoInkFIFO_51v1__lcl_setNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__SetNext)}
        {$define _prc_piFifo51v1_setNext:=_M_protoInkFIFO_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_51v1__lcl_nodeCRT)}
        {$define _fnc_piFifo51v1_nodeCRT:=_M_protoInkFIFO_51v1__lcl_nodeCRT}
    {$else}
        {$FATAL 'macro ".._nodeCRT" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
begin
    if _var_piFifo51v1_STACK=nil then begin
       _var_piFifo51v1_STACK:=_fnc_piFifo51v1_nodeCRT(_cst_piFifo51v1_DATA,nil);
       _prc_piFifo51v1_setNext(_var_piFifo51v1_STACK,_var_piFifo51v1_STACK);
    end
    else begin
      _prc_piFifo51v1_setNext(_var_piFifo51v1_STACK,_fnc_piFifo51v1_nodeCRT(_cst_piFifo51v1_DATA,_fnc_piFifo51v1_getNext(_var_piFifo51v1_STACK)));
      _var_piFifo51v1_STACK:=_fnc_piFifo51v1_getNext(_var_piFifo51v1_STACK);
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Local macros
    {$unDef _var_piFifo51v1_STACK}
    {$unDef _cst_piFifo51v1_DATA}
    {$unDef _fnc_piFifo51v1_getNext}
    {$unDef _prc_piFifo51v1_setNext}
    {$unDef _fnc_piFifo51v1_nodeCRT}
    //--- undef user
    {$unDef _M_protoInkFIFO_51v1__var_STACK}
    {$unDef _M_protoInkFIFO_51v1__cst_DATA}
    {$unDef _M_protoInkFIFO_51v1__lcl_getNext}
    {$unDef _M_protoInkFIFO_51v1__lcl_setNext}
    {$unDef _M_protoInkFIFO_51v1__lcl_nodeCRT}
{%endregion 'unDEF used macros' /fold}
